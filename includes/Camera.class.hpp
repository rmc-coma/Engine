/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:43:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/23 04:57:30 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_CLASS_HPP
# define CAMERA_CLASS_HPP

# include "AComponent.class.hpp"

# include <OpenGL/gl3.h>

class Camera : public AComponent {
public:
	Camera(const GameObject &gameobject);
	Camera(const GameObject &gameobject, const GLfloat fov, const GLfloat near,
		   const GLfloat far, const GLuint viewportx, const GLuint viewporty,
		   const GLuint viewportwidth, const GLuint viewportheight);
	Camera(const Camera &other);
	~Camera(void);

	Camera	&operator=(const Camera &other);

	void	Initialize(void);
	void	Update(void);

private:
	Camera(void);

	GLfloat		_FOV;
	GLfloat		_Near;
	GLfloat		_Far;
	GLuint		_ViewportX;
	GLuint		_ViewportY;
	GLuint		_ViewportWidth;
	GLuint		_ViewportHeight;
};

#endif
