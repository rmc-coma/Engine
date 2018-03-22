/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:14:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 07:54:02 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.class.hpp"
#include "GameObject.class.hpp"

Camera::Camera(void) : Component(*(new GameObject(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))), "kek")), CMP_CAMERA)
{
	return ;
}

Camera::Camera(const GameObject &gameobject) : Component(gameobject, CMP_CAMERA),
											   _FOV(70),
											   _Near(0.1f),
											   _Far(1000.0f),
											   _ViewportX(0),
											   _ViewportY(0),
											   _ViewportWidth(1),
											   _ViewportHeight(1)
{
	return ;
}

Camera::Camera(const GameObject &gameobject, const GLfloat fov, const GLfloat near,
			   const GLfloat far, const GLuint viewportx, const GLuint viewporty,
			   const GLuint viewportwidth, const GLuint viewportheight) : Component(gameobject, CMP_CAMERA),
																		  _FOV(fov),
																		  _Near(near),
																		  _Far(far),
																		  _ViewportX(viewportx),
																		  _ViewportY(viewporty),
																		  _ViewportWidth(viewportwidth),
																		  _ViewportHeight(viewportheight)
{
	return ;
}

Camera::Camera(const Camera &other) : Component(other._GameObject, other._Type)
{
	*this = other;
	return ;
}

Camera::~Camera(void)
{
	return ;
}

Camera	&Camera::operator=(const Camera &other)
{
	this->_FOV = other._FOV;
	this->_Near = other._Near;
	this->_Far = other._Far;
	this->_ViewportX = other._ViewportX;
	this->_ViewportY = other._ViewportY;
	this->_ViewportWidth = other._ViewportWidth;
	this->_ViewportHeight = other._ViewportHeight;
	return (*this);
}

void		Camera::Initialize(void)
{
	return ;
}

void		Camera::Update(void)
{
	return ;
}
