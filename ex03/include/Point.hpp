/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:18:00 by sergio            #+#    #+#             */
/*   Updated: 2025/07/28 09:40:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <cmath>
#include "../include/Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
};

#endif // POINT_HPP
