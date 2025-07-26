/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:06:52 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 14:13:06 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _fixedPoint;
        static const int    _fractionalBits = 8;
    public:
        Fixed();                                // Constructor x defecto;
        Fixed(const Fixed& other);              // Constructor x copia
        Fixed& operator=(const Fixed& other);   // Operador de asignacion;
        ~Fixed();                               // Destructor;
        
        void setRawBits(int const raw);
        int getRawBits(void) const;
};

#endif // FIXED_HPP
