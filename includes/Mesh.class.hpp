// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Mesh.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 00:25:28 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 03:09:02 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MESH_CLASS_HPP
# define MESH_CLASS_HPP

# include <string>

# include <OpenGL/gl3.h>
# include <assimp/cimport.h>
# include <assimp/scene.h>
# include <assimp/postprocess.h>

class Mesh {

public:
	Mesh(const std::string &path);
	Mesh(const Mesh &other);
	~Mesh(void);

	Mesh	&operator=(const Mesh &other);

private:
	Mesh(void);

	const aiScene	*_Scene;
	GLfloat			*_Vertices;
	size_t			_N_Vertices;
	GLfloat			*_Normals;
	size_t			_N_Normals;
	GLfloat			*_UVs;
	size_t			_N_UVs;

};

#endif
