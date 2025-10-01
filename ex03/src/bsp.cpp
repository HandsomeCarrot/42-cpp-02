/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:26 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 14:25:54 by vpoka            ###   ########.fr       */
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
 * @brief Calculates the relative position of point p with respect to the directed line segment ab.
 *
 * This function computes the cross product of vectors AB and AP, where:
 *   - AB is the vector from point a to point b
 *   - AP is the vector from point a to point p
 * The sign of the result indicates which side of the line AB the point p lies on:
 *   - Positive: p is on one side of AB
 *   - Negative: p is on the other side of AB
 *   - Zero: p is colinear with AB
 *
 * @param a The starting point of the line segment.
 * @param b The ending point of the line segment.
 * @param p The point to test.
 * @return int The signed value indicating the side of p relative to AB.
 */
int	calcPointSide(Point const &a, Point const &b, Point const &p)
{
	Point	abVector = calcVector(a, b);
	Point	apVector = calcVector(a, p);

	return (calcCrossProduct(abVector, apVector).toInt());
}

/**
 * @param a, b, c	the vertices of our beloved triangle
 * @param point	the point to check
 * @return	True if the point is inside the triangle.
 * 			False otherwise. Thus, if the point is a vertex or on an edge,
 * 			it will return False
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	
}
