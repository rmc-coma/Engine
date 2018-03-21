// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scene.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 05:26:43 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:11:47 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>

#include "Scene.class.hpp"
#include "GameObject.class.hpp"

Scene::Scene(void) : _GLContext_Ptr(0)
{
	return ;
}

Scene::Scene(const Window &window)
{
	if (!(this->_GLContext_Ptr = SDL_GL_CreateContext(window.getSDLPtr())))
	{
		SDL_Quit();
		throw std::runtime_error("Failed to create GL context");
	}
	SDL_GL_SetSwapInterval(SDL_TRUE);
	glEnable(GL_DEPTH_TEST);
}

Scene::Scene(const Scene &other)
{
	*this = other;
	return ;
}

Scene::~Scene(void)
{
	SDL_GL_DeleteContext(this->_GLContext_Ptr);
	return ;
}

Scene	&Scene::operator=(const Scene &other)
{
	this->_GLContext_Ptr = other._GLContext_Ptr;
	return (*this);
}

void			Scene::addGameObject(GameObject &gameobject)
{
	this->_GameObjects.push_back(&gameobject);
}

SDL_GLContext	Scene::getGLContextPtr(void) const	{ return (this->_GLContext_Ptr); }

