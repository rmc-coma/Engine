/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Component.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:49:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:39:51 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.class.hpp"
#include "Component.class.hpp"

Component::Component(void) : _GameObject(*(new GameObject(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))), "kek"))),
							 _Type(CMP_DEFAULT)
{
	return ;
}

Component::Component(const GameObject &gameobject, const t_component_type type) : _GameObject(gameobject),
																				  _Type(type)
{
	gameobject.addComponent(*this);
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

void				Component::insertIntoScene(Scene &scene)
{
	scene.addInitializable(this);
	scene.addUpdatable(this);
}

void				Component::removeFromScene(Scene &scene)
{
	scene.removeInitializable(this);
	scene.removeUpdatable(this);
}

void				Component::Initialize(void)
{
	return ;
}

void				Component::Update(void)
{
	return ;
}
