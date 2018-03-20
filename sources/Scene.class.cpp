// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scene.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 05:26:43 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:49:39 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Scene.class.hpp"
#include <stdexcept>

Scene::Scene(void) : glcontext_ptr(0)
{
	return ;
}

Scene::Scene(const Window &window)
{
	if (!(this->glcontext_ptr = SDL_GL_CreateContext(window.getSDLPtr())))
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
	SDL_GL_DeleteContext(this->glcontext_ptr);
	return ;
}

Scene	&Scene::operator=(const Scene &other)
{
	this->glcontext_ptr = other.glcontext_ptr;
	return (*this);
}

SDL_GLContext	Scene::getGLContextPtr(void) const	{ return (this->glcontext_ptr); }