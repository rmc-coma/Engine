// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Shader.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 09:43:45 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 11:06:27 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHADER_CLASS_HPP
# define SHADER_CLASS_HPP

# include <OpenGL/gl3.h>

# include <string>

typedef enum	e_shader_type
{
	SHD_DEFAULT = 0,
	SHD_VERTEX = GL_VERTEX_SHADER,
	SHD_FRAGMENT = GL_FRAGMENT_SHADER
}				t_shader_type;

class Shader {

public:
	Shader(const std::string &path, const t_shader_type type);
	Shader(const Shader &other);
	~Shader(void);

	Shader	&operator=(const Shader &other);

	GLuint	getGL_ID(void) const;

private:
	Shader(void);

	
	GLuint				_GL_ID;
	const GLenum		_Type;
	const std::string	_Path;
	const GLchar		*_Source;

};

#endif
