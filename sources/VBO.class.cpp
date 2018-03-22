/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VBO.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:38:02 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 06:21:56 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <stdexcept>

#include "VBO.class.hpp"

VBO::VBO(void) : _GL_ID(0),
				 _Data(0),
				 _TotalSize(0)
{
	return ;
}

VBO::VBO(const Mesh &mesh) : _GL_ID(0),
							 _Data(0),
							 _TotalSize(0)
{
	glGenBuffers(1, &this->_GL_ID);
	if (!glIsBuffer(this->_GL_ID))
		throw (std::runtime_error("Failed to create new VBO"));
	t_vbo_data	vbod;
	GLuint		offset = 0;

	if (mesh.hasVertices())
	{
		vbod.attrib = std::string(ATTRIB_VERTICES_NAME);
		vbod.n_components = ATTRIB_VERTICES_SIZE;
		vbod.data = static_cast<void *>(mesh.getVertices());
		vbod.size = static_cast<GLuint>(mesh.getNVertices() * vbod.n_components * sizeof(GLfloat));
		vbod.offset = offset;
		offset += vbod.size;
		this->_Data.push_back(vbod);
	}
	if (mesh.hasNormals())
	{
		vbod.attrib = ATTRIB_NORMALS_NAME;
		vbod.n_components = ATTRIB_NORMALS_SIZE;
		vbod.data = static_cast<void *>(mesh.getNormals());
		vbod.size = static_cast<GLuint>(mesh.getNNormals() * vbod.n_components * sizeof(GLfloat));
		vbod.offset = offset;
		offset += vbod.size;
		this->_Data.push_back(vbod);
	}
	if (mesh.hasUVs())
	{
		vbod.attrib = ATTRIB_UVS_NAME;
		vbod.n_components = ATTRIB_UVS_SIZE;
		vbod.data = static_cast<void *>(mesh.getUVs());
		vbod.size = static_cast<GLuint>(mesh.getNUVs() * vbod.n_components * sizeof(GLfloat));
		vbod.offset = offset;
		offset += vbod.size;
		this->_Data.push_back(vbod);
	}
	this->_TotalSize = offset;
	glBindBuffer(GL_ARRAY_BUFFER, this->_GL_ID);
	glBufferData(GL_ARRAY_BUFFER, this->_TotalSize, 0, GL_STATIC_DRAW);
	for (auto it = this->_Data.begin(); it != this->_Data.end(); ++it)
		glBufferSubData(GL_ARRAY_BUFFER, it->offset, it->size, it->data);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return ;
}

VBO::VBO(const VBO &other) : _GL_ID(0),
							 _Data(other._Data),
							 _TotalSize(other._TotalSize)
{
	*this = other;
	return ;
}

VBO::~VBO(void)
{
	if (glIsBuffer(this->_GL_ID))
		glDeleteBuffers(1, &this->_GL_ID);
	return ;
}

VBO	&VBO::operator=(const VBO &other)
{
	if (glIsBuffer(this->_GL_ID))
		glDeleteBuffers(1, &this->_GL_ID);
	this->_GL_ID = other._GL_ID;
	this->_Data = other._Data;
	this->_TotalSize = other._TotalSize;
	return (*this);
}

GLuint							VBO::getGL_ID(void) const		{ return (this->_GL_ID); }
const std::vector<t_vbo_data>	&VBO::getData(void) const		{ return (this->_Data); }
GLuint							VBO::getTotalSize(void) const	{ return (this->_TotalSize); }