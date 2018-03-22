/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 05:25:33 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:34:17 by rmc-coma         ###   ########.fr       */
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
# include "IRenderable.class.hpp"

class GameObject;

class Scene : public IRenderable{
public:
	Scene(const Window &window);
	Scene(const Scene &other);
	virtual ~Scene(void);

	Scene	&operator=(const Scene &other);

	void			addGameObject(GameObject &gameobject);

	void			addInitializable(IInitializable &initializable);
	void			addUpdatable(IUpdatable &updatable);
	void			addRenderable(IRenderable &renderable);

	void			removeInitializable(IInitializable &initializable)
	void			removeUpdatable(IUpdatable &updatable)
	void			removeRenderable(IRenderable &renderable)

	SDL_GLContext   getGLContextPtr(void) const;

	void			Initialize(void);
	void			Update(void);
	void			Render(void);

private:
	Scene(void);

	SDL_GLContext					_GLContext_Ptr;
	std::vector<GameObject *>		_GameObjects;
	std::vector<IInitializable *>	_Initializables;
	std::vector<IUpdatabales *>		_Updatables;
	std::vector<IRenderable *>		_Renderables;
};

#endif
