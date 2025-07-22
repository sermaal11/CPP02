/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:06:52 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 19:34:04 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _fixedPointNumber;
        static const int    _fractionaBits = 8;
    public:
        Fixed();                                // Constructor x defecto
        Fixed(const Fixed& other);              // Constructor x copia
        Fixed& operator=(const Fixed& other);   // Operador de asigancion
        ~Fixed();                               // Destructor x defecto
        
        void    setRawBits(int const raw);
        int     getRawBits(void) const;
};

#endif // FIXED_HPP
