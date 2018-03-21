// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 03:29:12 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:11:03 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Window.class.hpp"
#include <stdexcept>

Window::Window(void) : _Title("NULL"),
					   _X(0),
					   _Y(0),
					   _Width(0),
					   _Height(0),
					   _Flags(0),
					   _SDL_Ptr(0)
{
	return ;
}

Window::Window(const char *const title, const int x, const int y,
			   const int width, const int height, const Uint32 flags) : _Title(title),
																		_X(x),
																		_Y(y),
																		_Width(width),
																		_Height(height),
																		_Flags(flags),
																		_SDL_Ptr(0)
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
	if (!(this->_SDL_Ptr = SDL_CreateWindow(title, x, y, width, height, flags)))
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
	SDL_DestroyWindow(this->_SDL_Ptr);
	SDL_Quit();
	return ;
}

Window			&Window::operator=(const Window &other)
{
	this->_Title = other._Title;
	this->_X = other._X;
	this->_Y = other._Y;
	this->_Width = other._Width;
	this->_Height = other._Height;
	this->_Flags = other._Flags;
	this->_SDL_Ptr = other._SDL_Ptr;
	return (*this);
}

const char		*Window::getTitle(void) const	{ return (this->_Title); }
int				Window::getX(void) const		{ return (this->_X); }
int				Window::getY(void) const		{ return (this->_Y); }
int				Window::getWidth(void) const	{ return (this->_Width); }
int				Window::getHeight(void) const	{ return (this->_Height); }
Uint32			Window::getFlags(void) const	{ return (this->_Flags); }
SDL_Window		*Window::getSDLPtr(void) const	{ return (this->_SDL_Ptr); }
