/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:48 by sergio            #+#    #+#             */
/*   Updated: 2025/07/28 10:35:02 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Fixed::Fixed()
{
    _fixedPoint = 0;
}

Fixed::Fixed(const Fixed& other)
{
    _fixedPoint = other._fixedPoint;
}

Fixed::Fixed(const int value)
{
    _fixedPoint = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _fixedPoint = roundf(value * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _fixedPoint = other._fixedPoint;
    return *this;
}

Fixed::~Fixed() {}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}

int Fixed::getRawBits(void) const
{
    return _fixedPoint;
}

int Fixed::toInt(void) const
{
    int val = _fixedPoint >> _fractionalBits;
    return val;
}

float Fixed::toFloat(void) const
{
    float f = (float)_fixedPoint / (1 << _fractionalBits);
    return f;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    float f = obj.toFloat();
    os << f;
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return _fixedPoint > other._fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return _fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const
{
    return _fixedPoint < other._fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return _fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const
{
    return _fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return _fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    int raw = _fixedPoint + other._fixedPoint;
    result.setRawBits(raw);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    int raw = _fixedPoint - other._fixedPoint;
    result.setRawBits(raw);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long tmp = (long)_fixedPoint * (long)other._fixedPoint;
    int raw = tmp >> _fractionalBits;
    result.setRawBits(raw);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    if (other._fixedPoint == 0)
    {
        result.setRawBits(0);
        return result;
    }

    long tmp = ((long)_fixedPoint << _fractionalBits) / other._fixedPoint;
    result.setRawBits(tmp);
    return result;
}

Fixed& Fixed::operator++()
{
    _fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fixedPoint += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    _fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fixedPoint -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}
