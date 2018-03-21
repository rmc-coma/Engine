// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Transform.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/16 21:12:26 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:10:36 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Transform.class.hpp"

Transform::Transform(void) : _Position(qm::vec4<GLfloat>(0.0f)),
							 _Rotation(qm::vec4<GLfloat>(0.0f)),
							 _Scale(qm::vec3<GLfloat>(1.0f))
{
	return ;
}

Transform::Transform(const qm::vec4<GLfloat> &Position, const qm::vec4<GLfloat> &Rotation,
					 const qm::vec3<GLfloat> &Scale) : _Position(Position),
													   _Rotation(Rotation),
													   _Scale(Scale)
{
	return ;
}

Transform::Transform(Transform const &other)
{
	*this = other;
	return ;
}

Transform::~Transform(void)
{
	return ;
}

Transform	&Transform::operator=(Transform const &other)
{
	this->_Position = other._Position;
	this->_Rotation = other._Rotation;
	this->_Scale = other._Scale;
	return (*this);
}

qm::vec4<GLfloat>	Transform::getPosition(void) const	{ return (this->_Position); }
qm::vec4<GLfloat>	Transform::getRotation(void) const	{ return (this->_Rotation); }
qm::vec3<GLfloat>	Transform::getScale(void) const		{ return (this->_Scale); }

void				Transform::setPosition(const qm::vec4<GLfloat> &Position)	{ this->_Position = Position; }
void				Transform::setRotation(const qm::vec4<GLfloat> &Rotation)	{ this->_Rotation = Rotation; }
void				Transform::setScale(const qm::vec3<GLfloat> &Scale)			{ this->_Scale = Scale; }
