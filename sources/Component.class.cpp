// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Component.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 20:49:22 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 08:26:00 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameObject.class.hpp"
#include "Component.class.hpp"

Component::Component(void) : _GameObject(*(new GameObject())),
							 _Type(CMP_DEFAULT)
{
	return ;
}

Component::Component(const GameObject &gameobject, const t_component_type type) : _GameObject(gameobject),
																				  _Type(type)
{
	return ;
}

Component::Component(const Component &other) : _GameObject(other._GameObject),
											   _Type(other._Type)
{
	*this = other;
	return ;
}

Component::~Component(void)
{
	return ;
}

Component			&Component::operator=(const Component &other)
{
	(void)other;
	return (*this);
}

t_component_type	Component::getType(void) const	{ return (this->_Type); }

void				Component::Initialize(void)
{
	return ;
}

void				Component::Update(void)
{
	return ;
}
