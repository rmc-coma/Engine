/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IUpdatable.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:47:55 by rmc-coma          #+#    #+#             */
/*   Updated: 2018/03/24 15:20:22 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IUPDATABLE_CLASS_HPP
# define IUPDATABLE_CLASS_HPP

class IUpdatable {
public:
    virtual         ~IUpdatable(void);
    virtual void    Update(void);
};

#endif