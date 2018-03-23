/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAComponent.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:49:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/23 04:53:29 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AComponent_CLASS_HPP
# define AComponent_CLASS_HPP

# include "IInitializable.class.hpp"
# include "IUpdatable.class.hpp"

class GameObject;

typedef	enum	e_AComponent_type
{
	CMP_DEFAULT = 0,
	CMP_MESHFILTER,
	CMP_MESHRENDERER,
	CMP_CAMERA
}				t_AComponent_type;

class AComponent : public IInitializable, public IUpdatable {

public:
	virtual ~AComponent(void);

	AComponent				&operator=(const AComponent &other);

	t_AComponent_type		getType(void) const;

	virtual void			Initialize(void);
	virtual void			Update(void);

protected:
	AComponent(const GameObject &gameobject, const t_AComponent_type type);
	AComponent(const AComponent &other);

	const GameObject		&_GameObject;
	const t_AComponent_type	_Type;

private:	AComponent(void);

};

#endif
