// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameObject.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/17 00:42:47 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 08:18:57 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameObject.class.hpp"

GameObject::GameObject(void) : _Name("Unnamed")
{
	return ;
}

GameObject::GameObject(const std::string &name) : _Name(name)
{
	return ;
}

GameObject::GameObject(const GameObject &other)
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
	return (*this);
}

void		GameObject::addChild(GameObject &child)
{
	this->_Children.push_back(&child);
	return ;
}

void		GameObject::addComponent(Component &component)
{
	this->_Components.push_back(&component);
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
