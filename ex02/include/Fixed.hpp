/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:02:05 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 21:08:35 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int					_rawBits;
        static const int	_fractionalBits = 8;

    public:
	    // Orthodox Canonical Form
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

	    // Constructores personalizados
        Fixed(const int value);
        Fixed(const float value);

	    // Métodos públicos
        int		getRawBits() const;
        void	setRawBits(int const raw);
        float	toFloat() const;
        int		toInt() const;

	    // Comparadores
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

	    // Operadores aritméticos
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

	    // Incremento/Decremento
	    Fixed& operator++();			// pre-incremento
	    Fixed operator++(int);			// post-incremento
	    Fixed& operator--();			// pre-decremento
	    Fixed operator--(int);			// post-decremento

	    // Min / Max
        static Fixed&		min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&		max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Inserción en stream
std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif // FIXED_HPP
