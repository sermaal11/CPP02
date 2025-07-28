/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:51 by sergio            #+#    #+#             */
/*   Updated: 2025/07/28 09:41:37 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point() {}

const Fixed& Point::getX() const
{
	return _x;
}

const Fixed& Point::getY() const
{
	return _y;
}