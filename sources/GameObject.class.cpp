// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameObject.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/17 00:42:47 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/17 00:45:15 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameObject.hpp"

GameObject::GameObject(void)
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

GameObject	GameObject::&operator(const GameObject &other)
{
	this->m_Transform = other.m_Transform;
	return ;
}
