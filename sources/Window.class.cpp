// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 03:29:12 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:46:20 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Window.class.hpp"
#include <stdexcept>

Window::Window(void) : title("NULL"),
					   x(0),
					   y(0),
					   width(0),
					   height(0),
					   flags(0),
					   sdl_ptr(0)
{
	return ;
}

Window::Window(const char *const title, const int x, const int y,
			   const int width, const int height, const Uint32 flags) : title(title),
																		x(x),
																		y(y),
																		width(width),
																		height(height),
																		flags(flags),
																		sdl_ptr(0)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		throw std::runtime_error("Failed to initialize SDL");
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, WINDOW_CONTEXT_MAJOR_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, WINDOW_CONTEXT_MINOR_VERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, WINDOW_PROFILE_MASK);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, WINDOW_DOUBLEBUFFER);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, WINDOW_ACCELERATION);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, WINDOW_DEPTH_SIZE);
	if (!(this->sdl_ptr = SDL_CreateWindow(title, x, y, width, height, flags)))
	{
		SDL_Quit();
		throw std::runtime_error("Failed to open SDL Window");
	}
//	SDL_GL_SetSwapInterval(SDL_TRUE);
	glEnable(GL_DEPTH_TEST);
}

Window::Window(const Window &other)
{
	*this = other;
	return ;
}

Window::~Window(void)
{
	SDL_DestroyWindow(this->sdl_ptr);
	SDL_Quit();
	return ;
}

Window			&Window::operator=(const Window &other)
{
	this->title = other.title;
	this->x = other.x;
	this->y = other.y;
	this->width = other.width;
	this->height = other.height;
	this->flags = other.flags;
	this->sdl_ptr = other.sdl_ptr;
	return (*this);
}

const char		*Window::getTitle(void) const	{ return (this->title); }
int				Window::getX(void) const		{ return (this->x); }
int				Window::getY(void) const		{ return (this->y); }
int				Window::getWidth(void) const	{ return (this->width); }
int				Window::getHeight(void) const	{ return (this->height); }
Uint32			Window::getFlags(void) const	{ return (this->flags); }
SDL_Window		*Window::getSDLPtr(void) const	{ return (this->sdl_ptr); }
