// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Component.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 20:49:21 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 02:22:13 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMPONENT_CLASS_HPP
# define COMPONENT_CLASS_HPP

class GameObject;

class Component {

public:
	Component(const GameObject &gameobject);
	Component(const Component &other);
	~Component(void);

	Component	&operator=(const Component &other);

protected:
	const GameObject	&_GameObject;
private:
	Component(void);

};

#endif
