// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Program.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 10:14:52 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 11:15:36 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <iostream>

#include "Program.class.hpp"
#include "Shader.class.hpp"

Program::Program(void) : _GL_ID(0),
						 _Vertex_Shader(*(new Shader(NULL, SHD_DEFAULT))),
						 _Fragment_Shader(*(new Shader(NULL, SHD_DEFAULT))),
						 _Attribs(0)
{
	return ;
}

Program::Program(const Shader &vertex, const Shader &fragment,
				 const std::vector<std::string> attribs) : _GL_ID(0),
														   _Vertex_Shader(vertex),
														   _Fragment_Shader(fragment),
														   _Attribs(attribs)
{
	GLuint	i;
	GLint	linkError;
	GLint	errorSize;
	char	*error;

	if (!(this->_GL_ID = glCreateProgram()))
		throw (std::runtime_error("Failed to create program"));
	glAttachShader(vertex.getGL_ID(), this->_GL_ID);
	glAttachShader(fragment.getGL_ID(), this->_GL_ID);
	i = 0;
	for (auto it = attribs.begin(); it != attribs.end(); ++it)
		glBindAttribLocation(this->_GL_ID, i++, (*it).c_str());
	glLinkProgram(this->_GL_ID);
	linkError = GL_TRUE;
	glGetProgramiv(this->_GL_ID, GL_LINK_STATUS, &linkError);
	if (linkError != GL_TRUE)
	{
		errorSize = 0;
		glGetProgramiv(this->_GL_ID, GL_INFO_LOG_LENGTH, &errorSize);
		error = new char[errorSize + 1];
		glGetShaderInfoLog(this->_GL_ID, errorSize, &errorSize, error);
		error[errorSize] = '\0';
		std::cout << error << std::endl;
		delete [] error;
		glDeleteProgram(this->_GL_ID);
		throw (std::runtime_error("Failed to link program"));
	}
	return ;
}

Program::Program(const Program &other) : _GL_ID(other._GL_ID),
										 _Vertex_Shader(other._Vertex_Shader),
										 _Fragment_Shader(other._Fragment_Shader),
										 _Attribs(other._Attribs)
{
	*this = other;
	return ;
}

Program::~Program(void)
{
	return ;
}


Program		&Program::operator=(const Program &other)
{
	this->_GL_ID = other._GL_ID;
	return (*this);
}
