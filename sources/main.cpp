// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 03:16:07 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 05:51:30 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include "Engine.hpp"
#include <iostream>

#include "Window.class.hpp"
#include "Scene.class.hpp"

int		main(void)
{
	try {
	Window	MyWindow("It's alive !", SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED, 800, 600,
				   SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	Scene	MyScene(MyWindow);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Hello World!" << std::endl;
	return (0);
}
