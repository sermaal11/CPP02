/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:02:01 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 20:48:36 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << GREEN << "\t[Default constructor]" << RESET << "\n";
    _fixedPoint = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << CYAN << "\t[Copy constructor]" << RESET << "\n";
    _fixedPoint = other._fixedPoint;
}

Fixed::Fixed(const int value)
{
    std::cout << YELLOW << "\t[Int constructor]" << RESET 
              << " value=" << value << "\n";
    _fixedPoint = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << YELLOW << "\t[Float constructor]" << RESET 
              << " value=" << value << "\n";
    _fixedPoint = roundf(value * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << CYAN << "\t[Copy assignment]" << RESET << "\n";
    if (this != &other)
        _fixedPoint = other._fixedPoint;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << RED << "\t[Destructor]" << RESET << "\n";
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
    std::cout << MAGENTA << "\t[setRawBits]" << RESET 
              << " raw=" << raw << "\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << MAGENTA << "\t[getRawBits]" << RESET 
              << " raw=" << _fixedPoint << "\n";
    return _fixedPoint;
}

int Fixed::toInt(void) const
{
    int val = _fixedPoint >> _fractionalBits;
    std::cout << MAGENTA << "\t[toInt]" << RESET 
              << " value=" << val << "\n";
    return val;
}

float Fixed::toFloat(void) const
{
    float f = (float)_fixedPoint / (1 << _fractionalBits);
    std::cout << MAGENTA << "\t[toFloat]" << RESET 
              << " value=" << f << "\n";
    return f;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    float f = obj.toFloat();
    std::cout << MAGENTA << "\t[operator<<]" << RESET 
              << " value=" << f << "\n";
    os << f;
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    std::cout << CYAN << "\t[operator>]" << RESET << "\n";
    return _fixedPoint > other._fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const
{
    std::cout << CYAN << "\t[operator>=]" << RESET << "\n";
    return _fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const
{
    std::cout << CYAN << "\t[operator<]" << RESET << "\n";
    return _fixedPoint < other._fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const
{
    std::cout << CYAN << "\t[operator<=]" << RESET << "\n";
    return _fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const
{
    std::cout << CYAN << "\t[operator==]" << RESET << "\n";
    return _fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const
{
    std::cout << CYAN << "\t[operator!=]" << RESET << "\n";
    return _fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    int raw = _fixedPoint + other._fixedPoint;
    std::cout << CYAN << "\t[operator+]" << RESET << "\n";
    result.setRawBits(raw);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    int raw = _fixedPoint - other._fixedPoint;
    std::cout << CYAN << "\t[operator-]" << RESET << "\n";
    result.setRawBits(raw);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long tmp = (long)_fixedPoint * (long)other._fixedPoint;
    int raw = tmp >> _fractionalBits;
    std::cout << CYAN << "\t[operator*]" << RESET << "\n";
    result.setRawBits(raw);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    if (other._fixedPoint == 0)
    {
        std::cerr << RED << "\t[operator/] Division by zero!\n" << RESET;
        result.setRawBits(0);
        return result;
    }

    long tmp = ((long)_fixedPoint << _fractionalBits) / other._fixedPoint;
    std::cout << CYAN << "\t[operator/]" << RESET << "\n";
    result.setRawBits(tmp);
    return result;
}

Fixed& Fixed::operator++()
{
    std::cout << CYAN << "\t[pre-increment]" << RESET << "\n";
    _fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    std::cout << CYAN << "\t[post-increment]" << RESET << "\n";
    Fixed temp(*this);
    _fixedPoint += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    std::cout << CYAN << "\t[pre-decrement]" << RESET << "\n";
    _fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    std::cout << CYAN << "\t[post-decrement]" << RESET << "\n";
    Fixed temp(*this);
    _fixedPoint -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    std::cout << CYAN << "[min] " << RESET 
              << "Comparando " << a.toFloat() << " y " << b.toFloat() << "\n";
    if (a < b)
    {
        std::cout << CYAN << "[min] " << RESET << "Devuelve a\n";
        return a;
    }
    std::cout << CYAN << "[min] " << RESET << "Devuelve b\n";
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    std::cout << CYAN << "[min const] " << RESET 
              << "Comparando " << a.toFloat() << " y " << b.toFloat() << "\n";
    if (a < b)
    {
        std::cout << CYAN << "[min const] " << RESET << "Devuelve a\n";
        return a;
    }
    std::cout << CYAN << "[min const] " << RESET << "Devuelve b\n";
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    std::cout << CYAN << "[max] " << RESET 
              << "Comparando " << a.toFloat() << " y " << b.toFloat() << "\n";
    if (a > b)
    {
        std::cout << CYAN << "[max] " << RESET << "Devuelve a\n";
        return a;
    }
    std::cout << CYAN << "[max] " << RESET << "Devuelve b\n";
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    std::cout << CYAN << "[max const] " << RESET 
              << "Comparando " << a.toFloat() << " y " << b.toFloat() << "\n";
    if (a > b)
    {
        std::cout << CYAN << "[max const] " << RESET << "Devuelve a\n";
        return a;
    }
    std::cout << CYAN << "[max const] " << RESET << "Devuelve b\n";
    return b;
}