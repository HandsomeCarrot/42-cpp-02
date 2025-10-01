/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:43:56 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 15:43:52 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Tests if a point lies inside a triangle.
 *
 * This function prints the result of checking if point p is inside
 * the triangle formed by points a, b, and c using the bsp function.
 * It outputs the test number, the coordinates of the point being
 * tested, whether it is inside the triangle, and the coordinates of
 * the triangle's vertices.
 *
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param p The point to test for inclusion within the triangle.
 *
 * @note This function maintains an internal static counter to number
 *       each test case sequentially.
 *
 * @see bsp()
 */
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

/**
 * @brief Entry point of the triangle point inclusion test program.
 *
 * This function runs a series of test cases to demonstrate the bsp
 * function's ability to determine whether points lie inside, outside,
 * or on the boundaries of triangles defined by three vertices.
 *
 * @return Always returns 0 to indicate successful program termination.
 *
 * @see checkCase()
 * @see bsp()
 */
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
