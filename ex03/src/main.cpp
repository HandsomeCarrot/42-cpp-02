/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:43:56 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 15:24:54 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.cpp"

void	checkCase(Point const &a, Point const &b, Point const &c, Point const &p)
{
	int static	testCounter = 1;

	std::cout << "===Test " << testCounter++ << "===" << std::endl;

	std::cout << "Point (" << p;
	if (bsp(a, b, c, p))
		std::cout << ") IS ";
	else
		std::cout << ") is NOT ";
	std::cout << "in triangle: " << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << std::endl;
}

int main(void)
{
	checkCase(Point(1, 1), Point(1, 2), Point(2, 1), Point(1.33f, 1.33f));
	checkCase(Point(1, 1), Point(1, 2), Point(2, 1), Point(0, 0));
	checkCase(Point(1, 1), Point(1, 2), Point(2, 1), Point(1, 1));
	checkCase(Point(0, 10), Point(10, 0), Point(10, 10), Point(6, 6));
	checkCase(Point(0, 10), Point(10, 0), Point(0, 0), Point(6, 6));
	checkCase(Point(0, 10), Point(10, 0), Point(0, 0), Point(5.1f, 5.1f));
	return (0);
}
