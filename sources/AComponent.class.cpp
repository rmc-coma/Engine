/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AComponent.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:49:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:39:51 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.class.hpp"
#include "AComponent.class.hpp"

AComponent::AComponent(void) : _GameObject(*(new GameObject(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))), "kek"))),
							   _Type(CMP_DEFAULT)
{
	return ;
}

AComponent::AComponent(const GameObject &gameobject, const t_AComponent_type type) : _GameObject(gameobject),
																				  	 _Type(type)
{
	//gameobject.addAComponent(*this);
	return ;
}

AComponent::AComponent(const AComponent &other) : _GameObject(other._GameObject),
											   	  _Type(other._Type)
{
	*this = other;
	return ;
}

AComponent::~AComponent(void)
{
	return ;
}

AComponent			&AComponent::operator=(const AComponent &other)
{
	(void)other;
	return (*this);
}

t_AComponent_type	AComponent::getType(void) const	{ return (this->_Type); }

void				AComponent::Initialize(void)
{
	return ;
}

void				AComponent::Update(void)
{
	return ;
}
