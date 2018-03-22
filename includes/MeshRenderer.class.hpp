/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshRenderer.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 06:55:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 09:24:32 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESHRENDERER_CLASS_HPP
# define MESHRENDERER_CLASS_HPP

# include <vector>
# include <string>

# include <OpenGL/gl3.h>

# include "Component.class.hpp"
# include "Program.class.hpp"

class MeshRenderer : public Component, public IRenderable {
public:
	MeshRenderer(const GameObject &gameobject);
	MeshRenderer(const MeshRenderer &other);
	~MeshRenderer(void);

	MeshRenderer		&operator=(const MeshRenderer &other);

	void				insertIntoScene(Scene &scene);

	void				Initialize(void);
	void				Update(void);
	void				Render(void);

private:
	MeshRenderer(void);
	

	Program							*_Program;

};

#endif
