/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 00:42:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/24 20:22:09 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.class.hpp"

GameObject::GameObject(void) : _Scene(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))))
{
	return ;
}

GameObject::GameObject(Scene &scene, const std::string &name) : _Scene(scene),
																_Name(name)
{
	return ;
}

GameObject::GameObject(const GameObject &other) : _Scene(other._Scene)												  
{
	*this = other;
	return ;
}

GameObject::~GameObject(void)
{
	return ;
}

GameObject	&GameObject::operator=(const GameObject &other)
{
	this->_Transform = other._Transform;
	this->_Scene = other._Scene;
	this->_Name = other._Name;
	for (auto it = this->_Children.begin(); it != this->_Children.end(); ++it)
		delete *it;
	this->_Children.clear();
	for (auto it = other._Children.begin(); it != other._Children.end(); ++it)
		this->_Children.push_back(new GameObject(**it));
	for (auto it = this->_AComponents.begin(); it != this->_AComponents.end(); ++it)
		delete *it;
	this->_AComponents.clear();
	for (auto it = other._AComponents.begin(); it != other._AComponents.end(); ++it)
		this->_AComponents.push_back(new AComponent(**it));
	return (*this);
}

void		GameObject::addChild(GameObject &child)
{
	child._Parent = this;
	this->_Children.push_back(&child);
	return ;
}

template<typename T>
T			*GameObject::createComponent(void)
{
	T	*component;

	component = new T(*this);
	this->_AComponents.push_back(component);
	return (component);
}

template<typename T>
T			*GameObject::getComponent(void) const
{
	for (auto it = this->_AComponents.begin(); it != this->_AComponents.end(); ++it)
	{
		if (typeid(*it) == typeid(T))
			return (*it);
	}
	return (NULL);
}

void		GameObject::Initialize(void)
{
	for (auto it = this->_AComponents.begin(); it != this->_AComponents.end(); ++it)
		(*it)->Initialize();
	return ;
}

void		GameObject::Update(void)
{
	for (auto it = this->_AComponents.begin(); it != this->_AComponents.end(); ++it)
		(*it)->Update();
	return ;
}
