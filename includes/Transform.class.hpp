// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Transform.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/16 21:09:34 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:44:32 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TRANSFORM_CLASS_HPP
# define TRANSFORM_CLASS_HPP

# include <OpenGL/gl3.h>
# include "QuickMaths.class.hpp"

class Transform {

public:
	Transform(void);
	Transform(const qm::vec4<GLfloat> &Position,
			  const qm::vec4<GLfloat> &Rotation,
			  const qm::vec3<GLfloat> &Scale);
	Transform(const Transform &other);
	virtual ~Transform(void);

	Transform	&operator=(Transform const &other);

	qm::vec4<GLfloat>	getPosition(void) const;
	qm::vec4<GLfloat>	getRotation(void) const;
	qm::vec3<GLfloat>	getScale(void) const;

	void				setPosition(const qm::vec4<GLfloat> &Position);
	void				setRotation(const qm::vec4<GLfloat> &Rotation);
	void				setScale(const qm::vec3<GLfloat> &Scale);

protected:

private:

	qm::vec4<GLfloat>	Position;
	qm::vec4<GLfloat>	Rotation;
	qm::vec3<GLfloat>	Scale;

};

#endif
