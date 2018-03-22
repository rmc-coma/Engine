/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Material.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 01:08:11 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 01:09:07 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_CLASS_HPP
# define MATERIAL_CLASS_HPP

class Material {
public:
    Material(void);
    Material(const Material &other);
    ~Material(void);

    Material &operator=(const Material &other);

};

#endif