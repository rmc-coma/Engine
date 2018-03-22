/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInitializable.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:45:23 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/22 08:46:33 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IINITIALIZABLE_CLASS_HPP
# define IINITIALIZABLE_CLASS_HPP

class IInitializable {
public:
    virtual         ~Initializable(void);
    virtual void    Initialize(void) const = 0;
};

#endif