/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:51 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 23:55:08 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}
Point::~Point() {}

Point& Point::operator=(const Point& other) {
	(void) other;
	return *this; // no hace nada porque x e y son const
}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
