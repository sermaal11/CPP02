/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:08:13 by sergio            #+#    #+#             */
/*   Updated: 2025/07/26 14:16:50 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main( void )
{
    Fixed a; 
    Fixed b(a); 
    Fixed c;
     
    c = b;
     
    std::cout << a.getRawBits() << std::endl; 
    std::cout << b.getRawBits() << std::endl; 
    std::cout << c.getRawBits() << std::endl; 
    return 0; 
}
