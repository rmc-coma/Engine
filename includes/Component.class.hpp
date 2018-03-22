/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Component.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:49:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:30:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_CLASS_HPP
# define COMPONENT_CLASS_HPP

# include "Component.class.hpp"
# include "IInitializable.class.hpp"
# include "IUpdatable.class.hpp"

class GameObject;

typedef	enum	e_component_type
{
	CMP_DEFAULT = 0,
	CMP_MESHFILTER,
	CMP_MESHRENDERER,
	CMP_CAMERA
}				t_component_type;

class Component : public IInitializable, public IUpdatable {

public:
	Component(const GameObject &gameobject, const t_component_type type);
	Component(const Component &other);
	virtual ~Component(void);

	Component				&operator=(const Component &other);

	t_component_type		getType(void) const;

	virtual void			insertIntoScene(Scene &scene);
	virtual void			removeFromScene(Scene &scene);

	virtual void			Initialize(void);
	virtual void			Update(void);

protected:
	const GameObject		&_GameObject;
	const t_component_type	_Type;

private:
	Component(void);

};

#endif
