// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameObject.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/17 00:40:35 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:41:57 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEOBJECT_CLASS_HPP
# define GAMEOBJECT_CLASS_HPP

# include "Transform.hpp"

class GameObject {

public:

	GameObject(void);
	GameObject(const GameObject &other);
	~GameObject(void);

	GameObject	&operator=(GameObject const &other);

protected:

	Transform	_Transform;

private:

};

#endif
