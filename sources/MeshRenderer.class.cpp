/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshRenderer.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 06:57:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/25 03:44:56 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MeshRenderer.class.hpp"
#include "GameObject.class.hpp"
#include "MeshFilter.class.hpp"
#include "Mesh.class.hpp"
#include "Material.class.hpp"
#include "Shader.class.hpp"
#include "Program.class.hpp"
#include "VBO.class.hpp"
#include "Shader.template.hpp"

MeshRenderer::MeshRenderer(void) : AComponent(*(new GameObject(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))), "kek"))),
								   _Vertex(NULL),
								   _Fragment(NULL),
								   _Program(NULL)
{
	return ;
}

MeshRenderer::MeshRenderer(const GameObject &gameobject) : AComponent(gameobject),
														   _Vertex(NULL),
														   _Fragment(NULL),
														   _Program(NULL)
{
	return ;
}

MeshRenderer::MeshRenderer(const MeshRenderer &other) : AComponent(other._GameObject),
														_Vertex(NULL),
														_Fragment(NULL),
														_Program(NULL)
{
	*this = other;
	return ;
}

MeshRenderer::~MeshRenderer(void)
{
	return ;
}

MeshRenderer	&MeshRenderer::operator=(const MeshRenderer &other)
{
	(void)other;
	return (*this);
}

std::string		MeshRenderer::assembleShaderSources(std::vector<std::string> header, std::vector<std::string> body)
{
	std::string source;

	for (auto it = header.begin(); it != header.end(); ++it)
		source += *it + "\n";
	for (auto it = body.begin(); it != body.end(); ++it)
		source += *it + "\n";
	return (source);
}

std::string		MeshRenderer::bakeVertexShader(void)
{
	MeshFilter					*meshfilter;
	Mesh						*mesh;
	std::vector<std::string>	shadersources_header;
	std::vector<std::string>	shadersources_body;

	shadersources_header.push_back(SHADER_VERSION);
	shadersources_body.push_back("void main()\n{");
	if (!(meshfilter = this->_GameObject.getComponent<MeshFilter>()) ||
		!(mesh = meshfilter->getMesh()))
		return (NULL);
	if (mesh->hasVertices())
	{
		shadersources_header.push_back(IN_VERTEX);
		shadersources_header.push_back(OUT_VERTEX);
		shadersources_body.push_back(VERTEX_INSTRUCTIONS);
	}
	if (mesh->hasNormals())
	{
		shadersources_header.push_back(IN_NORMAL);
		shadersources_header.push_back(OUT_NORMAL);
		shadersources_body.push_back(NORMAL_INSTRUCTIONS);
	}
	if (mesh->hasUVs())
	{
		shadersources_header.push_back(IN_UV);
		shadersources_header.push_back(OUT_UV);
		shadersources_body.push_back(UV_INSTRUCTIONS);
	}
	shadersources_header.push_back(UNIFORM_MODEL);
	shadersources_header.push_back(UNIFORM_VIEW);
	shadersources_header.push_back(UNIFORM_PROJECTION);
	shadersources_body.push_back("}\n");
	return (MeshRenderer::assembleShaderSources(shadersources_header, shadersources_body));
}

std::string		MeshRenderer::bakeFragmentShader(void)
{
	MeshFilter					*meshfilter;
	Mesh						*mesh;
	Material					*material;
	std::vector<std::string>	shadersources_header;
	std::vector<std::string>	shadersources_body;

	if (!(meshfilter = this->_GameObject.getComponent<MeshFilter>()) ||
		!(mesh = meshfilter->getMesh()) ||
		!(material = meshfilter->getMaterial()))
		return (NULL);
	shadersources_header.push_back(SHADER_VERSION);
	shadersources_body.push_back("void main()\n{");
	shadersources_body.push_back(OUT_COLOR);
	if (mesh->hasVertices())
		shadersources_header.push_back(IN_VERTEX2);
	if (mesh->hasNormals())
	{
		shadersources_header.push_back(IN_NORMAL2);
		shadersources_header.push_back(OUT_NORMAL);
	}
	if (mesh->hasUVs())
	{
		shadersources_header.push_back(IN_UV2);
		shadersources_header.push_back(OUT_UV);
	}
	if (mesh->hasExponent())
		shadersources_header.push_back(UNIFORM_EXPONENT);
	shadersources_header.push_back(UNIFORM_MODEL);
	shadersources_header.push_back(UNIFORM_VIEW);
	shadersources_header.push_back(UNIFORM_PROJECTION);

	shadersources_body.push_back(PHONG_INSTRUCTIONS);
	if (material->hasDiffuseTexture() && mesh->hasVertices() && mesh->hasNormals() && mesh->hasUVs())
	{
		shadersources_header.push_back(UNIFORM_DIFFUSE_TEXTURE);
		shadersources_body.push_back(DIFFUSE_TEX_INSTRUCTIONS);
	}
	else if (material->hasDiffuse() && mesh->hasVertices() && mesh->hasNormals())
	{
		shadersources_header.push_back(UNIFORM_DIFFUSE);
		shadersources_body.push_back(DIFFUSE_INSTRUCTIONS);
	}
	else
		shadersources_body.push_back(NO_DIFFUSE_INSTRUCTIONS);

	if (material->hasAmbientTexture() && mesh->hasVertices() && mesh->hasNormals() && mesh->hasUVs())
	{
		shadersources_header.push_back(UNIFORM_AMBIENT_TEXTURE);
		shadersources_body.push_back(AMBIENT_TEX_INSTRUCTIONS);
	}
	else if (material->hasAmbient() && mesh->hasVertices() && mesh->hasNormals())
	{
		shadersources_header.push_back(UNIFORM_AMBIENT);
		shadersources_body.push_back(AMBIENT_INSTRUCTIONS);
	}
	else
		shadersources_body.push_back(NO_AMBIENT_INSTRUCTIONS);

	if (material->hasSpecularTexture() && mesh->hasVertices() && mesh->hasNormals() && mesh->hasUVs())
	{
		shadersources_header.push_back(UNIFORM_SPECULAR_TEXTURE);
		if (mesh->hasExponent())
			shadersources_body.push_back(SPECULAR_TEX_INSTRUCTIONS_E);
		else
			shadersources_body.push_back(SPECULAR_TEX_INSTRUCTIONS);
	}
	else if (material->hasSpecular() && mesh->hasVertices() && mesh->hasNormals())
	{
		shadersources_header.push_back(UNIFORM_SPECULAR);
		if (material->hasExponent())
			shadersources_body.push_back(SPECULAR_INSTRUCTIONS_E);
		else
			shadersources_body.push_back(SPECULAR_INSTRUCTIONS);
	}
	shadersources_body.push_back(COLOR_INSTRUCTIONS);
	shadersources_body.push_back("}\n");
	return (MeshRenderer::assembleShaderSources(shadersources_header, shadersources_body));
}

void			MeshRenderer::Initialize(void)
{
	MeshFilter	*meshfilter;
	VBO			*vbo;

	if (!(meshfilter = this->_GameObject.getComponent<MeshFilter>()))
		return ;
	if (!(vbo = meshfilter->getVBO()))
		return ;
	this->_Vertex = new Shader(this->bakeVertexShader, SHD_VERTEX);
	this->_Fragment = new Shader(this->bakeFragmentShader, SHD_FRAGMENT);
	this->_Program = new Program(*this->_Vertex, *this->_Fragment, vbo->getData())
	return ;
}

void			MeshRenderer::Update(void)
{
	return ;
}
