/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:16:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 07:41:55 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Engine.hpp"
#include <iostream>

#include "Window.class.hpp"
#include "Scene.class.hpp"
#include "GameObject.class.hpp"
#include "Mesh.class.hpp"

int		main(void)
{
	Window	MyWindow("It's alive !", SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED, 800, 600,
				   SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	Scene	MyScene(MyWindow);

	GameObject	MyGameObject(MyScene, "MyObject");
	Mesh	MyMesh("/Users/rmc-coma/Work/Engine_Github/assets/Models/42/42.obj");

	MyScene.addGameObject(MyGameObject);

	std::cout << "Hello World!" << std::endl;
	return (0);
}
