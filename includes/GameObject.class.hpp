/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 00:40:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/24 20:21:59 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_CLASS_HPP
# define GAMEOBJECT_CLASS_HPP

# include "Transform.class.hpp"
# include "AComponent.class.hpp"
# include "Scene.class.hpp"
# include "IInitializable.class.hpp"
# include "IUpdatable.class.hpp"

# include <vector>
# include <string>

class GameObject : public IInitializable, public IUpdatable {

public:
	GameObject(Scene &scene, const std::string &name);
	GameObject(const GameObject &other);
	virtual ~GameObject(void);

	GameObject		&operator=(GameObject const &other);

	void			addChild(GameObject &child);

	template<typename T>
	T				*createComponent(void);
	template<typename T>
	T				*getComponent(void) const;

	virtual void	Initialize(void);
	virtual void	Update(void);

protected:

	Transform					_Transform;

private:
	GameObject(void);

	Scene						&_Scene;
	std::string					_Name;
	GameObject					*_Parent;
	std::vector<GameObject *>	_Children;
	std::vector<AComponent *>	_AComponents;

};

#endif
