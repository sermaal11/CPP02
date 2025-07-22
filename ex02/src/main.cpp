/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:01:59 by sergio            #+#    #+#             */
/*   Updated: 2025/07/22 21:03:36 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main(void)
{
    Fixed a; 
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); 
    
    std::cout << a << std::endl; 
    std::cout << ++a << std::endl; 
    std::cout << a << std::endl; 
    std::cout << a++ << std::endl; 
    std::cout << a << std::endl; 
    std::cout << b << std::endl; 
    std::cout << Fixed::max( a, b ) << std::endl; 
    return 0; 
}
