// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MeshFilter.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 21:14:19 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 01:25:19 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MeshFilter.class.hpp"
#include "GameObject.class.hpp"

MeshFilter::MeshFilter(void) : Component(*(new GameObject())),
							   _Mesh(NULL)
{
	return ;
}

MeshFilter::MeshFilter(const GameObject &gameobject) : Component(gameobject),
													   _Mesh(NULL)
{
	return ;
}

MeshFilter::MeshFilter(const GameObject &gameobject, Mesh &mesh) : Component(gameobject),
																   _Mesh(&mesh)
{
	return ;
}

MeshFilter::MeshFilter(const MeshFilter &other) : Component(other._GameObject)
{
	*this = other;
	return ;
}

MeshFilter::~MeshFilter(void)
{
	return ;
}

MeshFilter	&MeshFilter::operator=(const MeshFilter &other)
{
	this->_Mesh = other._Mesh;
	return (*this);
}
