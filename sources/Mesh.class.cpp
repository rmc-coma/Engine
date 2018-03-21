// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Mesh.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 00:26:24 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 06:53:48 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.class.hpp"

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
	Assimp::Importer	importer;

	if (!(this->_Scene = importer.ReadFile(path,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_GenSmoothNormals |
		aiProcess_GenUVCoords |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType)))
		throw std::runtime_error(std::string("Failed to parse file ") + path);


	for (size_t i = 0; i < this->_Scene->mNumMeshes; ++i)
	{
		this->_N_Vertices += this->_Scene->mMeshes[i]->mNumFaces * 3;
		this->_N_Normals += this->_Scene->mMeshes[i]->mNumFaces * 3;
		this->_N_UVs += this->_Scene->mMeshes[i]->mNumFaces * 3;
	}

	this->_Vertices = new GLfloat[this->_N_Vertices * 3];
	this->_Normals = new GLfloat[this->_N_Normals * 3];
	if (this->_Scene->HasTextures())
		this->_UVs = new GLfloat[this->_N_UVs * 2];
	else
		this->_N_UVs = 0;

	size_t	x = 0;
	size_t	y = 0;
	size_t	z = 0;

	for (size_t i = 0; i < this->_Scene->mNumMeshes; ++i)
	{
		for (size_t j = 0; j < this->_Scene->mMeshes[i]->mNumFaces; ++j)
		{
			for (size_t k = 0; k < 3; ++k)
			{
				this->_Vertices[x++] =
					this->_Scene->mMeshes[i]->mVertices[this->_Scene->mMeshes[i]->mFaces[j].mIndices[k]].x;
				this->_Vertices[x++] =
					this->_Scene->mMeshes[i]->mVertices[this->_Scene->mMeshes[i]->mFaces[j].mIndices[k]].y;
				this->_Vertices[x++] =
					this->_Scene->mMeshes[i]->mVertices[this->_Scene->mMeshes[i]->mFaces[j].mIndices[k]].z;
				this->_Normals[y++] =
					this->_Scene->mMeshes[i]->mNormals[this->_Scene->mMeshes[i]->mFaces[j].mIndices[k]].x;
				this->_Normals[y++] =
					this->_Scene->mMeshes[i]->mNormals[this->_Scene->mMeshes[i]->mFaces[j].mIndices[k]].y;
				this->_Normals[y++] =
					this->_Scene->mMeshes[i]->mNormals[this->_Scene->mMeshes[i]->mFaces[j].mIndices[k]].z;
			}
			if (this->_Scene->HasTextures())
			{
				for (size_t k = 0; k < 2; ++k)
				{
					this->_UVs[z++] =
						this->_Scene->mMeshes[i]->mTextureCoords[this->_Scene->mMeshes[i]->mFaces[j].mIndices[0]][0].x;
					this->_UVs[z++] =
						this->_Scene->mMeshes[i]->mTextureCoords[this->_Scene->mMeshes[i]->mFaces[j].mIndices[0]][0].y;
					this->_UVs[z++] =
						this->_Scene->mMeshes[i]->mTextureCoords[this->_Scene->mMeshes[i]->mFaces[j].mIndices[1]][0].x;
					this->_UVs[z++] =
						this->_Scene->mMeshes[i]->mTextureCoords[this->_Scene->mMeshes[i]->mFaces[j].mIndices[1]][0].y;
				}
			}
		}
	}
	for (size_t i = 0; i < this->_N_Vertices; ++i)
		std::cout << "v " << std::to_string(this->_Vertices[i]) << " " << std::to_string(this->_Vertices[i + 1]) << " " << std::to_string(this->_Vertices[i + 2]) << std::endl;
	std::cout << "Number of vertices : " << this->_N_Vertices << std::endl
			  << "Number of normals : " << this->_N_Normals << std::endl
			  << "Number of UVs : " << this->_N_UVs << std::endl;
	return ;
}

Mesh::Mesh(const Mesh &other) : Mesh()
{
	*this = other;
	return ;
}

Mesh::~Mesh(void)
{
//	if (this->_Scene)
//		aiReleaseImport(this->_Scene);
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

GLfloat	*Mesh::getVertices() const	{ return (this->_Vertices); }
GLuint	Mesh::getNVertices() const	{ return (this->_N_Vertices); }
GLfloat	*Mesh::getNormals() const	{ return (this->_Normals); }
GLuint	Mesh::getNNormals() const	{ return (this->_N_Normals); }
GLfloat	*Mesh::getUVs() const		{ return (this->_UVs); }
GLuint	Mesh::getNUVs() const		{ return (this->_N_UVs); }
