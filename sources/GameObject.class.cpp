/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 00:42:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:27:31 by rmc-coma         ###   ########.fr       */
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
	for (auto it = this->_Components.begin(); it != this->_Components.end(); ++it)
		delete *it;
	this->_Components.clear();
	for (auto it = other._Components.begin(); it != other._Components.end(); ++it)
		this->_Components.push_back(new Component(**it));
	return (*this);
}

void		GameObject::addChild(GameObject &child)
{
	child._Parent = this;
	this->_Children.push_back(&child);
	return ;
}

void		GameObject::addComponent(Component &component)
{
	this->_Components.push_back(&component);
	component.insertIntoScene(this->_Scene);
	return ;
}

Component	*GameObject::getComponent(const t_component_type type) const
{
	for (auto it = this->_Components.begin(); it != this->_Components.end(); ++it)
	{
		if ((*it)->getType() == type)
			return (*it);
	}
	return (NULL);
}

void		GameObject::Initialize(void)
{
	return ;
}

void		GameObject::Update(void)
{
	return ;
}

void		GameObject::Render(void)
{
	return ;
}