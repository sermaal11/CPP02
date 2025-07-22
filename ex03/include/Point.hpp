/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:18:00 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 23:58:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <cmath>
#include "../include/Fixed.hpp"

class Point {
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point(); // (0, 0)
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other); // no cambia nada
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif // POINT_HPP
