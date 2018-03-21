// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 03:16:07 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 23:57:07 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include "Engine.hpp"
#include <iostream>

#include "Window.class.hpp"
#include "Scene.class.hpp"
#include "GameObject.class.hpp"

int		main(void)
{
	Window	MyWindow("It's alive !", SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED, 800, 600,
				   SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	Scene	MyScene(MyWindow);

	GameObject	MyGameObject;

	MyScene.addGameObject(MyGameObject);

	std::cout << "Hello World!" << std::endl;
	return (0);
}
