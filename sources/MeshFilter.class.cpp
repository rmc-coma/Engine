/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshFilter.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:14:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 08:42:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MeshFilter.class.hpp"
#include "Mesh.class.hpp"
#include "GameObject.class.hpp"
#include "VBO.class.hpp"
#include "VAO.class.hpp"

MeshFilter::MeshFilter(void) : Component(*(new GameObject(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))), "kek")), CMP_MESHFILTER),
							   _Mesh(NULL),
							   _VBO(NULL)
{
	return ;
}

MeshFilter::MeshFilter(const GameObject &gameobject) : Component(gameobject, CMP_MESHFILTER),
													   _Mesh(NULL),
													   _VBO(NULL)
{
	return ;
}

MeshFilter::MeshFilter(const GameObject &gameobject, Mesh &mesh) : Component(gameobject, CMP_MESHFILTER),
																   _Mesh(&mesh),
																   _VBO(NULL)
{
	this->setMesh(mesh);
	return ;
}

MeshFilter::MeshFilter(const MeshFilter &other) : Component(other._GameObject, other._Type)
{
	*this = other;
	return ;
}

MeshFilter::~MeshFilter(void)
{
	if (this->_Mesh)
		delete this->_Mesh;
	if (this->_VBO)
		delete this->_VBO;
	return ;
}

MeshFilter	&MeshFilter::operator=(const MeshFilter &other)
{
	this->_Mesh = other._Mesh;
	return (*this);
}

Mesh		*MeshFilter::getMesh(void) const	{ return (this->_Mesh); }
VBO			*MeshFilter::getVBO(void) const		{ return (this->_VBO); }

void		MeshFilter::setMesh(Mesh &mesh)
{
	if (this->_VBO)
		delete this->_VBO;
	this->_Mesh = &mesh;
	return ;
}

void		MeshFilter::Initialize(void)
{
	if (!this->_VBO)
		this->_VBO = new VBO(*this->_Mesh);
	if (!this->_VAO)
		this->_VAO = new VAO(*this->_VBO);
	return ;
}

void		MeshFilter::Update(void)
{
	return ;
}
