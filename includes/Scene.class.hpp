/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 05:25:33 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/24 15:21:21 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_CLASS_HPP
# define SCENE_CLASS_HPP

// Standard includes
# include <vector>

// Libraries includes
# include <SDL2/SDL.h>
# include <OpenGL/gl3.h>

// Local includes
# include "Window.class.hpp"
# include "IInitializable.class.hpp"
# include "IUpdatable.class.hpp"

class GameObject;

class Scene : public IInitializable, public IUpdatable {
public:
	Scene(const Window &window);
	Scene(const Scene &other);
	virtual ~Scene(void);

	Scene	&operator=(const Scene &other);

	void			addGameObject(GameObject &gameobject);

	SDL_GLContext   getGLContextPtr(void) const;

	void			Initialize(void);
	void			Update(void);

private:
	Scene(void);

	SDL_GLContext					_GLContext_Ptr;
	std::vector<GameObject *>		_GameObjects;
};

#endif
