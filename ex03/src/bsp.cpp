/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:54 by sergio            #+#    #+#             */
/*   Updated: 2025/07/28 10:44:37 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

// ✅ Calcula el área de un triángulo a partir de 3 puntos
static float triangleArea(Point const& p1, Point const& p2, Point const& p3)
{
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    float area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    if (area < 0)
        area = -area;

	float result = area / 2.0f;

	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = triangleArea(a, b, c);
    float areaPAB = triangleArea(point, a, b);
    float areaPBC = triangleArea(point, b, c);
    float areaPCA = triangleArea(point, c, a);

    float sum = areaPAB + areaPBC + areaPCA;
    float diff = areaABC - sum;
    if (diff < 0)
        diff = -diff;
    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return false;

    bool inside = (diff < 0.0001f);
    return inside;
}
