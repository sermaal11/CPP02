/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:14:21 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 14:19:53 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
    _fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    this->_fixedPoint = other._fixedPoint;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPoint = other._fixedPoint;
    return *this;
}

Fixed::~Fixed(void)
{
        std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
    std::cout << "setRawBits member function called" << std::endl;

}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPoint;
}
