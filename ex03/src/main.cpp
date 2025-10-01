/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:43:56 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 14:57:13 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.cpp"

int main(void)
{
	Point	a1(1, 1);
	Point	b1(1, 2);
	Point	c1(2, 1);
	Point	p1(1.33f, 1.33f);

	std::cout << "Point: " << p1;
	if (bsp(a1, b1, c1, p1))
		std::cout << "IS ";
	else
		std::cout << "is NOT ";
	std::cout << "in triangle: " << std::endl;
	std::cout << "a: " << a1 << std::endl;
	std::cout << "b: " << b1 << std::endl;
	std::cout << "c: " << c1 << std::endl;

	std::cout << std::endl;
	return (0);
}
