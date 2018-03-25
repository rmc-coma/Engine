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

class AComponent : public IInitializable, public IUpdatable {

public:
	AComponent(const AComponent &other);
	virtual ~AComponent(void);

	AComponent				&operator=(const AComponent &other);

	virtual void			Initialize(void);
	virtual void			Update(void);

protected:
	AComponent(const GameObject &gameobject);

	const GameObject		&_GameObject;

private:	AComponent(void);

};

#endif
