/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:08 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/30 17:58:15 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Default constructor for Point class.
 *
 * Initializes a Point object at the origin (0, 0) using Fixed-point
 * coordinates. Both x and y coordinates are set to Fixed(0).
 */
Point::Point(void) :
	m_x(0),
	m_y(0)
{}

/**
 * @brief Parameterized constructor for Point class.
 *
 * Creates a Point object with specified Fixed-point coordinates.
 * The coordinates are stored as constant members and cannot be
 * modified after construction.
 *
 * @param x A constant reference to the Fixed-point value for the
 *          x-coordinate.
 * @param y A constant reference to the Fixed-point value for the
 *          y-coordinate.
 */
Point::Point(Fixed const &x, Fixed const &y) :
	m_x(x),
	m_y(y)
{}

/**
 * @brief Copy constructor for Point class.
 *
 * Creates a new Point object as a copy of an existing Point object.
 * The new point will have the same coordinates as the source point.
 *
 * @param other A constant reference to the Point object to copy from.
 */
Point::Point(Point const &other) :
	m_x(other.m_x),
	m_y(other.m_y)
{}

/**
 * @brief Destructor for Point class.
 *
 * Cleans up the Point object. Since the class uses const Fixed-point
 * members that manage their own resources, no explicit cleanup is
 * required. The destructor is provided for completeness.
 */
Point::~Point(void)
{}

Fixed const	&Point::getX(void) const
{
	return (m_x);
}

Fixed const	&Point::getY(void) const
{
	return (m_y);
}

Point const	&Point::minX(Point const &p1, Point const &p2) const
{
	return (p1.getX() < p2.getX() ? p1 : p2);
}

Point const	&Point::maxX(Point const &p1, Point const &p2) const
{
	return (p1.getX() > p2.getX() ? p1 : p2);
}

Point const	&Point::minY(Point const &p1, Point const &p2) const
{
	return (p1.getY() < p2.getY() ? p1 : p2);
}

Point const	&Point::maxY(Point const &p1, Point const &p2) const
{
	return (p1.getY() > p2.getY() ? p1 : p2);
}
