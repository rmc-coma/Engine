// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MeshFilter.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/20 21:14:20 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/21 01:25:18 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MESHFILTER_CLASS_HPP
# define MESHFILTER_CLASS_HPP

# include "Component.class.hpp"

class Mesh;

class MeshFilter : public Component {

public:
	MeshFilter(const GameObject &gameobject);
	MeshFilter(const GameObject &gameobject, Mesh &mesh);
	MeshFilter(const MeshFilter &other);
	~MeshFilter(void);

	MeshFilter	&operator=(const MeshFilter &other);

private:
	MeshFilter(void);

	Mesh	*_Mesh;

};

#endif
