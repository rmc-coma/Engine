// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MeshFilter.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 21:14:19 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 09:34:34 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MeshFilter.class.hpp"
#include "Mesh.class.hpp"
#include "GameObject.class.hpp"

MeshFilter::MeshFilter(void) : Component(*(new GameObject()), CMP_MESHFILTER),
							   _Mesh(NULL),
							   _VBO_ID(0)
{
	return ;
}

MeshFilter::MeshFilter(const GameObject &gameobject) : Component(gameobject, CMP_MESHFILTER),
													   _Mesh(NULL),
													   _VBO_ID(0)
{
	return ;
}

MeshFilter::MeshFilter(const GameObject &gameobject, Mesh &mesh) : Component(gameobject, CMP_MESHFILTER),
																   _Mesh(&mesh),
																   _VBO_ID(0)
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
	if (this->_Mesh && this->_VBO_ID)
		glDeleteBuffers(1, &this->_VBO_ID);
	return ;
}

MeshFilter	&MeshFilter::operator=(const MeshFilter &other)
{
	this->_Mesh = other._Mesh;
	return (*this);
}

Mesh		*MeshFilter::getMesh(void) const	{ return (this->_Mesh); }
GLuint		MeshFilter::getVBOID(void) const	{ return (this->_VBO_ID); }

void		MeshFilter::setMesh(Mesh &mesh)		{ this->_Mesh = &mesh; }

void		MeshFilter::Initialize(void)
{
	glGenBuffers(1, &this->_VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, this->_VBO_ID);
	glBufferData(GL_ARRAY_BUFFER, this->_Mesh->getNVertices() * 3 * sizeof(GLfloat) +
				 this->_Mesh->getNNormals() * 3 * sizeof(GLfloat) + 
				 this->_Mesh->getNUVs() * 2 * sizeof(GLfloat), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER,
					0,
					this->_Mesh->getNVertices() * 3 * sizeof(GLfloat),
					this->_Mesh->getVertices());
	glBufferSubData(GL_ARRAY_BUFFER,
					this->_Mesh->getNVertices() * 3 * sizeof(GLfloat),
					this->_Mesh->getNNormals() * 3 * sizeof(GLfloat),
					this->_Mesh->getNormals());
	glBufferSubData(GL_ARRAY_BUFFER,
					this->_Mesh->getNVertices() * 3 * sizeof(GLfloat) +
					this->_Mesh->getNNormals() * 3 * sizeof(GLfloat),
					this->_Mesh->getNUVs() * 3 * sizeof(GLfloat),
					this->_Mesh->getUVs());
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void		MeshFilter::Update(void)
{
	return ;
}
