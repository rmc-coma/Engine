/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshRenderer.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 06:55:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/25 03:45:22 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESHRENDERER_CLASS_HPP
# define MESHRENDERER_CLASS_HPP

# include <vector>
# include <string>

# include <OpenGL/gl3.h>

# include "AComponent.class.hpp"
# include "Program.class.hpp"

class Shader;
class Program;

class MeshRenderer : public AComponent {
public:
	MeshRenderer(const GameObject &gameobject);
	MeshRenderer(const MeshRenderer &other);
	~MeshRenderer(void);

	MeshRenderer		&operator=(const MeshRenderer &other);

	void				Initialize(void);
	void				Update(void);

private:
	MeshRenderer(void);

	static std::string	assembleShaderSources(std::vector<std::string> header, std::vector<std::string> body);

	std::string			bakeVertexShader(void);
	std::string			bakeFragmentShader(void);
	
	Shader				*_Vertex;
	Shader				*_Fragment;			
	Program				*_Program;

};

#endif
