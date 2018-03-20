// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Transform.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/16 21:12:26 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:44:25 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Transform.class.hpp"

Transform::Transform(void) : Position(qm::vec4<GLfloat>(0.0f)),
							 Rotation(qm::vec4<GLfloat>(0.0f)),
							 Scale(qm::vec3<GLfloat>(1.0f))
{
	return ;
}

Transform::Transform(const qm::vec4<GLfloat> &Position, const qm::vec4<GLfloat> &Rotation,
					 const qm::vec3<GLfloat> &Scale) : Position(Position),
													   Rotation(Rotation),
													   Scale(Scale)
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
	this->Position = other.Position;
	this->Rotation = other.Rotation;
	this->Scale = other.Scale;
	return (*this);
}

qm::vec4<GLfloat>	Transform::getPosition(void) const	{ return (this->Position); }
qm::vec4<GLfloat>	Transform::getRotation(void) const	{ return (this->Rotation); }
qm::vec3<GLfloat>	Transform::getScale(void) const		{ return (this->Scale); }

void				Transform::setPosition(const qm::vec4<GLfloat> &Position)	{ this->Position = Position; }
void				Transform::setRotation(const qm::vec4<GLfloat> &Rotation)	{ this->Rotation = Rotation; }
void				Transform::setScale(const qm::vec3<GLfloat> &Scale)			{ this->Scale = Scale; }
