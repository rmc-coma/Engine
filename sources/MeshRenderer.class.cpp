// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MeshRenderer.class.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 06:57:59 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 09:36:17 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MeshRenderer.class.hpp"
#include "GameObject.class.hpp"
#include "MeshFilter.class.hpp"
#include "Mesh.class.hpp"

MeshRenderer::MeshRenderer(void) : Component(*(new GameObject()), CMP_MESHRENDERER)
{
	return ;
}

MeshRenderer::MeshRenderer(const GameObject &gameobject) : Component(gameobject, CMP_MESHRENDERER)
{
	return ;
}

MeshRenderer::MeshRenderer(const MeshRenderer &other) : Component(other._GameObject, CMP_MESHRENDERER)
{
	*this = other;
	return ;
}

MeshRenderer::~MeshRenderer(void)
{
	return ;
}

MeshRenderer	&MeshRenderer::operator=(const MeshRenderer &other)
{
	(void)other;
	return (*this);
}

void			MeshRenderer::Initialize(void)
{
	MeshFilter	*meshfilter;

	if (!(meshfilter = dynamic_cast<MeshFilter *>(this->_GameObject.getComponent(CMP_MESHFILTER))))
		throw std::runtime_error("Failed to fetch MeshFilter");
	glGenVertexArrays(1, &this->_VAO_ID);
	glBindVertexArray(this->_VAO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, meshfilter->getVBOID());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,
						  BUFFER_OFFSET(meshfilter->getMesh()->getNVertices() * 3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0,
						  BUFFER_OFFSET(meshfilter->getMesh()->getNVertices() * 3 * sizeof(GLfloat) +
										meshfilter->getMesh()->getNNormals() * 3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return ;
}

void			MeshRenderer::Update(void)
{
	return ;
}
