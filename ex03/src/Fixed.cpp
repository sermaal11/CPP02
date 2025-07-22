/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:48 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 23:59:09 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

// Orthodox Canonical Form
Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}
Fixed::~Fixed() {}

// Constructores personalizados
Fixed::Fixed(const int value) {
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _fractionalBits));
}

// Métodos públicos
int Fixed::getRawBits() const { return _rawBits; }
void Fixed::setRawBits(int const raw) { _rawBits = raw; }

float Fixed::toFloat() const {
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _rawBits >> _fractionalBits;
}

Fixed Fixed::abs() const {
	return Fixed(toFloat() < 0 ? -toFloat() : toFloat());
}

// Comparadores
bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

// Aritmética
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Incremento / Decremento
Fixed& Fixed::operator++() {
	++_rawBits;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_rawBits;
	return temp;
}
Fixed& Fixed::operator--() {
	--_rawBits;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_rawBits;
	return temp;
}

// Min / Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}

// Stream output
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}
