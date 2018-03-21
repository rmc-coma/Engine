// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Component.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 20:49:22 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:17:22 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameObject.class.hpp"
#include "Component.class.hpp"

Component::Component(void) : _GameObject(*(new GameObject()))
{
	return ;
}

Component::Component(const GameObject &gameobject) : _GameObject(gameobject)
{
	return ;
}

Component::Component(const Component &other) : _GameObject(other._GameObject)
{
	*this = other;
	return ;
}

Component::~Component(void)
{
	return ;
}

Component	&Component::operator=(const Component &other)
{
	(void)other;
	return (*this);
}
