/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:26 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 16:33:49 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Calculates the 2D cross product (also known as the vector product) of two vectors.
 *
 * This function computes the scalar value of the cross product between two 2D vectors,
 * represented as Point objects. The result is useful for determining the orientation
 * of the vectors (e.g., clockwise or counterclockwise) and for area calculations.
 *
 * @param vectorA The first vector as a Point object.
 * @param vectorB The second vector as a Point object.
 * @return Fixed The scalar value of the cross product.
 */
static Fixed	calcCrossProduct(Point const &vectorA, Point const &vectorB)
{
	return (Fixed((vectorA.getX() * vectorB.getY()) - (vectorA.getY() * vectorB.getX())));
}

/**
 * @brief Calculates the vector from point a to point b.
 *
 * Given two points a and b, this function computes the vector (as a Point)
 * that represents the displacement from a to b by subtracting the coordinates
 * of a from those of b.
 *
 * @param a The starting point.
 * @param b The ending point.
 * @return Point The vector from a to b.
 */
static Point	calcVector(Point const &a, Point const &b)
{
	Fixed	x, y;

	x = b.getX() - a.getX();
	y = b.getY() - a.getY();

	return (Point(x, y));
}

/**
 * @brief Determines the relative position of point p with respect to the directed line segment ab.
 *
 * Calculates the side on which point p lies relative to the directed line from point a to point b.
 * Uses the cross product of vectors ab and ap to determine the orientation:
 *   - Returns 1 if p is to the left of ab,
 *   - Returns -1 if p is to the right of ab,
 *   - Returns 0 if p is colinear with ab.
 *
 * @param a The starting point of the directed line segment.
 * @param b The ending point of the directed line segment.
 * @param p The point to test.
 * @return int 1 if p is to the left, -1 if to the right, 0 if colinear.
 */
int	calcPointSide(Point const &a, Point const &b, Point const &p)
{
	Point	abVector = calcVector(a, b);
	Point	apVector = calcVector(a, p);

	Fixed	pointSide = calcCrossProduct(abVector, apVector).toInt();
	return ((pointSide > Fixed(0)) - (pointSide < Fixed(0)));
}

/**
 * @brief Determines if a point lies inside the triangle defined by points a, b, and c.
 *
 * This function uses the concept of point side calculation to check if the given point
 * is strictly inside the triangle (not on the edge or vertex). It returns true if the
 * point is inside, and false otherwise.
 *
 * @param a First vertex of the triangle.
 * @param b Second vertex of the triangle.
 * @param c Third vertex of the triangle.
 * @param point The point to test for inclusion within the triangle.
 * @return true if the point is inside the triangle, false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	pointSide;

	pointSide = calcPointSide(a, b, point);
	if (!pointSide)
		return (false);
	if (calcPointSide(b, c, point) != pointSide)
		return (false);
	if (calcPointSide(c, a, point) != pointSide)
		return (false);
	return (true);
}
