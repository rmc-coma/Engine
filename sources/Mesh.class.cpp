// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Mesh.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 00:26:24 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 01:38:59 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Mesh.class.hpp"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

Mesh::Mesh(void) : _Vertices(NULL),
				   _N_Vertices(0),
				   _Normals(NULL),
				   _N_Normals(0),
				   _UVs(0),
				   _N_UVs(0)
{
	return ;
}

Mesh::Mesh(const std::string &path) : Mesh()
{
	const struct aiScene* scene = NULL;
	scene = aiImportFile(path.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);
	return ;
}

Mesh::Mesh(const Mesh &other) : Mesh()
{
	*this = other;
	return ;
}

Mesh::~Mesh(void)
{
	return ;
}

Mesh	&Mesh::operator=(const Mesh &other)
{
	this->_Vertices = other._Vertices;
	this->_N_Vertices = other._N_Vertices;
	this->_Normals = other._Normals;
	this->_N_Normals = other._N_Normals;
	this->_UVs = other._UVs;
	this->_N_UVs = other._N_UVs;
	return (*this);
}
