/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshFilter.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:14:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/24 20:24:43 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESHFILTER_CLASS_HPP
# define MESHFILTER_CLASS_HPP

# include <vector>
# include <string>
# include <OpenGL/gl3.h>
# include "AComponent.class.hpp"


class Mesh;
class VBO;
class VAO;

class MeshFilter : public AComponent {

public:
	MeshFilter(const GameObject &gameobject);
	MeshFilter(const GameObject &gameobject, Mesh &mesh);
	MeshFilter(const MeshFilter &other);
	~MeshFilter(void);

	MeshFilter			&operator=(const MeshFilter &other);

	Mesh				*getMesh(void) const;
	VBO					*getVBO(void) const;
	VAO					*getVAO(void) const;

	void				setMesh(Mesh &mesh);

	void				Initialize(void);
	void				Update(void);

private:
	MeshFilter(void);

	Mesh				*_Mesh;
	VBO					*_VBO;
	VAO					*_VAO;


};

#endif
