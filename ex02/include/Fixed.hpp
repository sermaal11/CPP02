/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:02:05 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 20:47:35 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPoint;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        void setRawBits(int const raw);
        int getRawBits(void) const;

        int toInt(void) const;
        float toFloat(void) const;

        bool operator>(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP