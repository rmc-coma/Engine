// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Component.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 20:49:21 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 08:47:18 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMPONENT_CLASS_HPP
# define COMPONENT_CLASS_HPP

# include "Component.class.hpp"

class GameObject;

typedef	enum	e_component_type
{
	CMP_DEFAULT = 0,
	CMP_MESHFILTER,
	CMP_MESHRENDERER,
	CMP_CAMERA
}				t_component_type;

class Component {

public:
	Component(const GameObject &gameobject, const t_component_type type);
	Component(const Component &other);
	virtual ~Component(void);

	Component				&operator=(const Component &other);

	t_component_type		getType(void) const;

	virtual void			Initialize(void);
	virtual void			Update(void);

protected:
	const GameObject		&_GameObject;
	const t_component_type	_Type;

private:
	Component(void);

};

#endif
