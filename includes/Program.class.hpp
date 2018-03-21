// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Program.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 09:43:45 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 11:11:13 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PROGRAM_CLASS_HPP
# define PROGRAM_CLASS_HPP

# include <OpenGL/gl3.h>

class Shader;

class Program {

public:
	Program(const Shader &vertex, const Shader &fragment, const std::vector<std::string> attribs);
	Program(const Program &other);
	~Program(void);

	Program	&operator=(const Program &other);

private:
	Program(void);

	
	GLuint							_GL_ID;
	const Shader					&_Vertex_Shader;
	const Shader					&_Fragment_Shader;
	const std::vector<std::string>	_Attribs;


};

#endif
