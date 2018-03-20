// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scene.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 05:25:33 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:49:41 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCENE_CLASS_HPP
# define SCENE_CLASS_HPP

# include <SDL2/SDL.h>
# include <OpenGL/gl3.h>
# include "Window.class.hpp"

class Scene {
public:
	Scene(const Window &window);
	Scene(const Scene &other);
	~Scene(void);

	Scene	&operator=(const Scene &other);

	SDL_GLContext   getGLContextPtr(void) const;

private:
	Scene(void);

	SDL_GLContext	glcontext_ptr;
};

#endif
