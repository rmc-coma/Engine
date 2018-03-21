// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MeshFilter.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 21:14:20 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 09:34:39 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MESHFILTER_CLASS_HPP
# define MESHFILTER_CLASS_HPP

# include "Component.class.hpp"
# include <OpenGL/gl3.h>

class Mesh;

class MeshFilter : public Component {

public:
	MeshFilter(const GameObject &gameobject);
	MeshFilter(const GameObject &gameobject, Mesh &mesh);
	MeshFilter(const MeshFilter &other);
	~MeshFilter(void);

	MeshFilter			&operator=(const MeshFilter &other);

	Mesh				*getMesh(void) const;
	GLuint				getVBOID(void) const;

	void				setMesh(Mesh &mesh);

	void				Initialize(void);
	void				Update(void);

private:
	MeshFilter(void);

	Mesh				*_Mesh;
	GLuint				_VBO_ID;

};

#endif
