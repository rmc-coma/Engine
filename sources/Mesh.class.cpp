// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Mesh.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 00:26:24 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 04:32:00 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Mesh.class.hpp"
#include <iostream>

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

Mesh::Mesh(void) : _Scene(NULL),
				   _Vertices(NULL),
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
	if (!(this->_Scene = aiImportFile(path.c_str(),
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType)))
		throw std::runtime_error(std::string("Failed to parse file ") + path);
	std::cout << this->_Scene << std::endl;
	return ;
}

Mesh::Mesh(const Mesh &other) : Mesh()
{
	*this = other;
	return ;
}

Mesh::~Mesh(void)
{
	if (this->_Scene)
		aiReleaseImport(this->_Scene);
	if (this->_N_Vertices)
		delete [] this->_Vertices;
	if (this->_N_Normals)
		delete [] this->_Normals;
	if (this->_N_UVs)
		delete [] this->_UVs;
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
