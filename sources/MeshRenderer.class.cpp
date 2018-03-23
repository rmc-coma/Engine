/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshRenderer.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 06:57:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/23 06:04:36 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MeshRenderer.class.hpp"
#include "GameObject.class.hpp"

MeshRenderer::MeshRenderer(void) : AComponent(*(new GameObject(*(new Scene(*(new Window("kek", 0, 0, 0, 0, 0)))), "kek")), CMP_MESHRENDERER)
{
	return ;
}

MeshRenderer::MeshRenderer(const GameObject &gameobject) : AComponent(gameobject, CMP_MESHRENDERER)
{
	return ;
}

MeshRenderer::MeshRenderer(const MeshRenderer &other) : AComponent(other._GameObject, CMP_MESHRENDERER)
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

void			MeshRenderer::insertIntoScene(Scene &scene)
{
	scene.addInitializable(this);
	scene.addUpdatable(this);
	scene.addRenderable(this);
}

void			MeshRenderer::Initialize(void)
{
	return ;
}

void			MeshRenderer::Update(void)
{
	return ;
}
