/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:48:22 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 19:57:42 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();                                 // Constructor por defecto
    Fixed(const int value);                  // Constructor desde int
    Fixed(const float value);                // Constructor desde float
    Fixed(const Fixed& other);               // Constructor de copia
    Fixed& operator=(const Fixed& other);    // Operador de asignación
    ~Fixed();                                // Destructor

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;             // Conversión a float
    int     toInt(void) const;               // Conversión a int

private:
    int _value;                              // Valor entero con parte fraccional codificada
    static const int _fractionalBits = 8;    // Usamos 8 bits para la parte fraccional
};

// Sobrecarga del operador << para imprimir
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
