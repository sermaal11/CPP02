/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:17:46 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 23:59:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(2.0f, 2.0f);
	Point edge(0.0f, 0.0f);
	Point outside(20.0f, 20.0f);

	std::cout << "Inside?  " << bsp(a, b, c, inside) << std::endl;  // 1
	std::cout << "On edge? " << bsp(a, b, c, edge) << std::endl;   // 0
	std::cout << "Outside? " << bsp(a, b, c, outside) << std::endl; // 0

	return 0;
}

