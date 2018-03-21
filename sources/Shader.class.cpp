// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Shader.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 09:43:07 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 11:09:34 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <fstream>
#include <iostream>

#include <OpenGL/gl3.h>

#include "Shader.class.hpp"

Shader::Shader(void) : _GL_ID(0),
					   _Type(static_cast<GLenum>(SHD_DEFAULT)),
					   _Path(NULL),
					   _Source(NULL)
{
	return ;
}

Shader::Shader(const std::string &path, const t_shader_type type) : _GL_ID(0),
																	_Type(static_cast<GLenum>(type)),
																	_Path(path),
																	_Source(NULL)
{
	std::ifstream	sourcefile(path.c_str());
	std::string		line;
	std::string		sourcecode;
	GLint			compileError(GL_TRUE);
	GLint			errorLength(0);
	char			*error;

	if (!(this->_GL_ID = glCreateShader(this->_Type)))
		throw (std::runtime_error("Failed to create shader"));
	if (!sourcefile)
	{
		throw (std::runtime_error(std::string("Failed to open file ") + path));
		glDeleteShader(this->_GL_ID);
	}
	while (getline(sourcefile, line))
		sourcecode += line + '\n';
	sourcefile.close();
	this->_Source = sourcecode.c_str();
	glShaderSource(this->_GL_ID, 1, &this->_Source, 0);
	glCompileShader(this->_GL_ID);
	glGetShaderiv(this->_GL_ID, GL_COMPILE_STATUS, &compileError);
	if (compileError != GL_TRUE)
	{
		glGetShaderiv(this->_GL_ID, GL_INFO_LOG_LENGTH, &errorLength);
		error = new char[errorLength + 1];
		glGetShaderInfoLog(this->_GL_ID, errorLength, &errorLength, error);
		error[errorLength] = '\0';
		std::cout << error << std::endl;
		delete [] error;
		glDeleteShader(this->_GL_ID);
		throw (std::runtime_error("Failed to parse shader"));
	}
	return ;
}

Shader::Shader(const Shader &other) : _GL_ID(other._GL_ID),
									  _Type(other._Type),
									  _Path(other._Path),
									  _Source(other._Source)
{
	*this = other;
	return ;
}

Shader::~Shader(void)
{
	return ;
}

Shader	&Shader::operator=(const Shader &other)
{
	this->_GL_ID = other._GL_ID;
	this->_Source = other._Source;
	return (*this);
}

GLuint	Shader::getGL_ID(void) const	{ return (this->_GL_ID); }
