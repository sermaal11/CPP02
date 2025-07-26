/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:48:49 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 19:01:09 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << GREEN << "[Default constructor] " << RESET
              << "Object at [" << this << "] created, _fixedPoint=0" << std::endl;
    _fixedPoint = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << CYAN << "[Copy constructor] " << RESET
              << "Object at [" << this << "] copying from [" << &other << "]" << std::endl;
    this->_fixedPoint = other._fixedPoint;
}

Fixed::Fixed(const int value)
{
    std::cout << YELLOW << "[Int constructor] " << RESET
              << "Object at [" << this << "], value=" << value << std::endl;
    _fixedPoint = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << YELLOW << "[Float constructor] " << RESET
              << "Object at [" << this << "], value=" << value << std::endl;
    _fixedPoint = roundf(value * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << CYAN << "[Copy assignment] " << RESET
              << "Object at [" << this << "] assigned from [" << &other << "]" << std::endl; 
    if (this != &other)
        this->_fixedPoint = other._fixedPoint;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << RED << "[Destructor] " << RESET
              << "Object at [" << this << "] destroyed" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
    std::cout << MAGENTA << "[setRawBits] " << RESET
              << "Object at [" << this << "], new raw=" << raw << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << MAGENTA << "[getRawBits] " << RESET
              << "Object at [" << this << "], returning raw=" << this->_fixedPoint << std::endl;
    return this->_fixedPoint;
}

int Fixed::toInt(void) const
{
    std::cout << MAGENTA << "[toInt] " << RESET
              << "Object at [" << this << "], value=" << (_fixedPoint >> _fractionalBits) << std::endl;
    return _fixedPoint >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
    float f = (float)_fixedPoint / (1 << _fractionalBits);
    std::cout << MAGENTA << "[toFloat] " << RESET
              << "Object at [" << this << "], value=" << f << std::endl;
    return f;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    float f = obj.toFloat();
    std::cout << MAGENTA << "[operator<<] " << RESET
              << "Printing object at [" << &obj << "], toFloat=" << f << std::endl;
    os << f;
    return os;
}