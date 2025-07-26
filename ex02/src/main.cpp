/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:01:59 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 20:50:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main(void)
{
    std::cout << "\n=== Constructores base ===\n";
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    std::cout << "\n=== Operadores de comparación ===\n";
    std::cout << std::boolalpha;
    std::cout << "b > c  = " << (b > c) << "\n";
    std::cout << "b >= c = " << (b >= c) << "\n";
    std::cout << "b < c  = " << (b < c) << "\n";
    std::cout << "b <= c = " << (b <= c) << "\n";
    std::cout << "b == d = " << (b == d) << "\n";
    std::cout << "b != c = " << (b != c) << "\n";

    std::cout << "\n=== Operadores aritméticos ===\n";
    Fixed sum  = b + c;
    Fixed diff = c - b;
    Fixed prod = b * c;
    Fixed div  = c / b;

    std::cout << "b + c = " << sum << "\n";
    std::cout << "c - b = " << diff << "\n";
    std::cout << "b * c = " << prod << "\n";
    std::cout << "c / b = " << div << "\n";

    std::cout << "\n=== Operadores de incremento y decremento ===\n";
    Fixed x(1.0f);
    Fixed y(2.0f);

    std::cout << "++x = " << ++x << "\n";
    std::cout << "x++ = " << x++ << " (después x = " << x << ")\n";
    std::cout << "--y = " << --y << "\n";
    std::cout << "y-- = " << y-- << " (después y = " << y << ")\n";

    std::cout << "\n=== Funciones estáticas min / max ===\n";
    Fixed m1 = Fixed::min(x, y);
    Fixed m2 = Fixed::max(x, y);
    std::cout << "min(x, y) = " << m1 << "\n";
    std::cout << "max(x, y) = " << m2 << "\n";

    const Fixed e(15);
    const Fixed f(15.5f);
    const Fixed& cm1 = Fixed::min(e, f);
    const Fixed& cm2 = Fixed::max(e, f);
    std::cout << "min(e, f) = " << cm1 << "\n";
    std::cout << "max(e, f) = " << cm2 << "\n";

    std::cout << "\n=== Fin de pruebas ===\n";
    return 0;
}
