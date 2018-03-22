/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 00:25:28 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 01:21:10 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_CLASS_HPP
# define MESH_CLASS_HPP

# include <string>

# include <OpenGL/gl3.h>


struct aiScene;

class Mesh {

public:
	Mesh(const std::string &path);
	Mesh(const Mesh &other);
	~Mesh(void);

	Mesh	&operator=(const Mesh &other);

	bool			hasVertices() const;
	bool			hasNormals() const;
	bool			hasUVs() const;

	GLfloat			*getVertices() const;
	GLuint			getNVertices() const;
	GLfloat			*getNormals() const;
	GLuint			getNNormals() const;
	GLfloat			*getUVs() const;
	GLuint			getNUVs() const;

private:
	Mesh(void);

	const aiScene	*_Scene;
	GLfloat			*_Vertices;
	GLuint			_N_Vertices;
	GLfloat			*_Normals;
	GLuint			_N_Normals;
	GLfloat			*_UVs;
	GLuint			_N_UVs;

};

#endif
