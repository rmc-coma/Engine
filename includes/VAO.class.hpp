/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAO.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:34:37 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 06:17:24 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAO_CLASS_HPP
# define VAO_CLASS_HPP

# ifndef BUFFER_OFFSET
#  define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
# endif

# include <vector>
# include <string>

# include <OpenGL/gl3.h>

class VBO;

class VAO {
public:
	VAO(const VBO &vbo);
	VAO(const VAO &other);
	~VAO(void);

	VAO	&operator=(const VAO &other);

private:
	VAO(void);

	GLuint						_GL_ID;
	const VBO					&_VBO;

};

#endif
