/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Material.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 01:07:55 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 01:10:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Material.class.hpp"

Material::Material(void)
{
    return ;
}

Material::Material(const Material &other)
{
    *this = other;
    return ;
}

Material::~Material(void)
{
    return ;
}

Material    &Material::operator=(const Material &other)
{
    (void)other;
    return (*this);
}