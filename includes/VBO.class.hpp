/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VBO.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:34:37 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/23 06:04:46 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VBO_CLASS_HPP
# define VBO_CLASS_HPP

# include <OpenGL/gl3.h>

# include "Mesh.class.hpp"

# ifndef BUFFER_OFFSET
#  define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
# endif

# define ATTRIB_VERTICES_NAME	"in_Vertices"
# define ATTRIB_NORMALS_NAME	"in_Normals"
# define ATTRIB_UVS_NAME		"in_UVs"

# define ATTRIB_VERTICES_SIZE	3
# define ATTRIB_NORMALS_SIZE	3
# define ATTRIB_UVS_SIZE		2

typedef struct	s_vbo_data
{
	std::string			attrib;
	const void			*data;
	GLint				n_AComponents;
	GLuint				size;
	GLuint				offset;
}				t_vbo_data;

class VBO {
public:
	VBO(const Mesh &mesh);
	VBO(const VBO &other);
	~VBO(void);

	VBO		&operator=(const VBO &other);

	GLuint							getGL_ID(void) const;
	const std::vector<t_vbo_data>	&getData(void) const;
	GLuint							getTotalSize(void) const;

private:
	VBO(void);
	GLuint							_GL_ID;
	std::vector<t_vbo_data>			_Data;
	GLuint							_TotalSize;
};

#endif
