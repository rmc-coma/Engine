/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRenderable.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:00:12 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 08:44:58 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRENDERABLE_CLASS_HPP
# define IRENDERABLE_CLASS_HPP

class IRenderable {
public:
    virtual         ~IRenderable(void) {};
    virtual void    Render(void) const = 0;
};

#endif