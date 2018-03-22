/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 05:26:43 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:38:33 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <algorithm>

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
	this->_Initializables.push_back(&gameobject);
	this->_Updatables.push_back(&gameobject);
	this->_Renderables.push_back(&gameobject);
}

void			Scene::addInitializable(IInitializable &initializable)			{ this->_Initializables.push_back(&initializable); }
void			Scene::addUpdatable(IUpdatable &updatable)						{ this->_Updatables.push_back(&updatable); }
void			Scene::addRenderable(IRenderable &renderable)					{ this->_Renderables.push_back(&renderable); }

void			Scene::removeInitializable(const IInitializable &initializable)	{ this->_Initializables.erase(std::remove(this->_Initializables.begin(), this->_Initializables.end(), &initializable), this->_Initializables.end()); }
void			Scene::removeUpdatable(const IUpdatable &updatable)				{ this->_Updatables.erase(std::remove(this->_Updatables.begin(), this->_Updatables.end(), &updatable), this->_Updatables.end()); }
void			Scene::removeRenderable(const IRenderable &renderable)			{ this->_Renderables.erase(std::remove(this->_Renderables.begin(), this->_Renderables.end(), &renderable), this->_Renderables.end()); }

SDL_GLContext	Scene::getGLContextPtr(void) const	{ return (this->_GLContext_Ptr); }

void			Scene::Render(void)
{
	for (auto it = this->_GameObjects.begin(); it != this->_GameObjects.end(); ++it)
		
}