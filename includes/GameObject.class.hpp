// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameObject.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/17 00:40:35 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 00:18:34 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEOBJECT_CLASS_HPP
# define GAMEOBJECT_CLASS_HPP

# include "Transform.class.hpp"

# include <vector>
# include <string>

class Component;

class GameObject {

public:
	GameObject(void);
	GameObject(const std::string &name);
	GameObject(const GameObject &other);
	~GameObject(void);

	GameObject	&operator=(GameObject const &other);

	void		addChild(GameObject &child);
	void		addComponent(Component &component);

protected:

	Transform					_Transform;

private:

	std::string					_Name;
	std::vector<GameObject *>	_Children;
	std::vector<Component *>	_Components;

};

#endif
