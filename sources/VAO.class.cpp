/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAO.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:38:02 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/23 06:19:56 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stdexcept>
#include <string>

#include "VAO.class.hpp"
#include "VBO.class.hpp"

VAO::VAO(void) : _GL_ID(0),
				 _VBO(*(new VBO(*(new Mesh(std::string(NULL))))))
{
	return ;
}

VAO::VAO(const VBO &vbo) : _GL_ID(0),
						   _VBO(vbo)
{
	const std::vector<t_vbo_data>	&VBO_Data = vbo.getData();
	glGenVertexArrays(1, &this->_GL_ID);
	if (!glIsVertexArray(this->_GL_ID))
		throw (std::runtime_error("Failed to create VAO"));
	glBindVertexArray(this->_GL_ID);
	glBindBuffer(GL_ARRAY_BUFFER, vbo.getGL_ID());
	GLuint	i = 0;
	for (auto it = VBO_Data.begin(); it != VBO_Data.end(); ++it)
	{
		glVertexAttribPointer(i, it->n_AComponents, GL_FLOAT, GL_FALSE, 0,
			BUFFER_OFFSET(it->offset));
		glEnableVertexAttribArray(i++);
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return ;
}

VAO::VAO(const VAO &other) : _GL_ID(other._GL_ID),
							 _VBO(other._VBO)
{
	*this = other;
	return ;
}

VAO::~VAO(void)
{
	if (this->_GL_ID)
		glDeleteVertexArrays(1, &this->_GL_ID);
	return ;
}

VAO	&VAO::operator=(const VAO &other)
{
	this->_GL_ID = other._GL_ID;
	return (*this);
}
