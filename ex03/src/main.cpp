/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:46 by sergio            #+#    #+#             */
/*   Updated: 2025/07/28 10:46:14 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

extern bool bsp(Point const a, Point const b, Point const c, Point const point);

static void drawTriangle(Point const& a, Point const& b, Point const& c, Point const& p)
{
    const int size = 20;
    char canvas[size][size];
	
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            canvas[y][x] = '.';
    
	for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            Point cell((float)x, (float)y);
            if (bsp(a, b, c, cell))
                canvas[y][x] = '#';
        }
    }

	canvas[a.getY().toInt()][a.getX().toInt()] = 'A';
    canvas[b.getY().toInt()][b.getX().toInt()] = 'B';
    canvas[c.getY().toInt()][c.getX().toInt()] = 'C';

    canvas[p.getY().toInt()][p.getX().toInt()] = 'P';

    std::cout << "\n=== Triángulo ===\n";
    for (int y = size - 1; y >= 0; y--)
    {
        for (int x = 0; x < size; x++)
            std::cout << canvas[y][x] << ' ';
        std::cout << '\n';
    }
}

int main()
{
    Point a(2, 2);
    Point b(15, 2);
    Point c(2, 15);

    Point inside(5, 5);
    Point outside(16, 5);
    Point edge(8, 2);

    std::cout << "\n--- Caso: Punto dentro ---\n";
    drawTriangle(a, b, c, inside);
    std::cout << (bsp(a, b, c, inside) ? "✅ Dentro\n" : "❌ Fuera\n");

    std::cout << "\n--- Caso: Punto fuera ---\n";
    drawTriangle(a, b, c, outside);
    std::cout << (bsp(a, b, c, outside) ? "✅ Dentro\n" : "❌ Fuera\n");

    std::cout << "\n--- Caso: Punto en el borde ---\n";
    drawTriangle(a, b, c, edge);
    std::cout << (bsp(a, b, c, edge) ? "✅ Dentro\n" : "❌ Fuera\n");

    return 0;
}

