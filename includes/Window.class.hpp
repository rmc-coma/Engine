// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 03:25:06 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:05:43 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

# include <SDL2/SDL.h>
# include <OpenGL/gl3.h>

# define WINDOW_CONTEXT_MAJOR_VERSION	4
# define WINDOW_CONTEXT_MINOR_VERSION	1
# define WINDOW_PROFILE_MASK			SDL_GL_CONTEXT_PROFILE_CORE
# define WINDOW_DOUBLEBUFFER			1
# define WINDOW_ACCELERATION			1
# define WINDOW_DEPTH_SIZE				32

class Window {
public:
	Window(const char *const title, const int x, const int y,
		   const int width, const int height, const Uint32 flags);
	Window(const Window &other);
	~Window(void);

	Window			&operator=(const Window &other);

	const char		*getTitle(void) const;
	int				getX(void) const;
	int				getY(void) const;
	int				getWidth(void) const;
	int				getHeight(void) const;
	Uint32			getFlags(void) const;
	SDL_Window		*getSDLPtr(void) const;

private:
	Window(void);

	const char		*_Title;
	int				_X;
	int				_Y;
	int				_Width;
	int				_Height;
	Uint32			_Flags;
	SDL_Window		*_SDL_Ptr;
};

#endif
