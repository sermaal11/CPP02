/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:48:22 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 19:07:42 by sergio           ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP