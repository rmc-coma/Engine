// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MeshRenderer.class.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/21 06:55:11 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 09:35:58 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MESHRENDERER_CLASS_HPP
# define MESHRENDERER_CLASS_HPP

# include "Component.class.hpp"
# include <OpenGL/gl3.h>

# ifndef BUFFER_OFFSET
#  define BUFFER_OFFSET(offset) ((char*)NULL + (offset))
# endif

class Mesh;

class MeshRenderer : public Component {
public:
	MeshRenderer(const GameObject &gameobject);
	MeshRenderer(const MeshRenderer &other);
	~MeshRenderer(void);

	MeshRenderer		&operator=(const MeshRenderer &other);

	void				Initialize(void);
	void				Update(void);

private:
	MeshRenderer(void);

	GLuint				_VAO_ID;
};

#endif
