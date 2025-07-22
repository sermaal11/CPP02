/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:54 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 23:55:36 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

// Función auxiliar: calcula el valor del determinante
static Fixed area(Point const& a, Point const& b, Point const& c)
{
	return Fixed((a.getX() * (b.getY() - c.getY()) +
	              b.getX() * (c.getY() - a.getY()) +
	              c.getX() * (a.getY() - b.getY())).toFloat() / 2.0f).abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a, b, c);
	Fixed A1 = area(point, b, c);
	Fixed A2 = area(a, point, c);
	Fixed A3 = area(a, b, point);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return false; // está en borde o vértice

	return (A == A1 + A2 + A3);
}

