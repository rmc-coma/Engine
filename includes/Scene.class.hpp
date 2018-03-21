// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Scene.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 05:25:33 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:11:55 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCENE_CLASS_HPP
# define SCENE_CLASS_HPP

// Standard includes
# include <vector>

// Libraries includes
# include <SDL2/SDL.h>
# include <OpenGL/gl3.h>

// Local includes
# include "Window.class.hpp"

class GameObject;

class Scene {
public:
	Scene(const Window &window);
	Scene(const Scene &other);
	~Scene(void);

	Scene	&operator=(const Scene &other);

	void			addGameObject(GameObject &gameobject);

	SDL_GLContext   getGLContextPtr(void) const;

private:
	Scene(void);

	SDL_GLContext				_GLContext_Ptr;
	std::vector<GameObject *>	_GameObjects;
};

#endif
