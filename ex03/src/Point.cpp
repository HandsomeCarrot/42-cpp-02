/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:08 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/30 15:56:39 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) :
	m_x(0),
	m_y(0)
{}

Point::Point(Fixed const &x, Fixed const &y) :
	m_x(x),
	m_y(y)
{}

Point::Point(Point const &other) :
	m_x(other.m_x),
	m_y(other.m_y)
{}

Point	&Point::operator=(Point const &other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
	return (*this);
}

Point::~Point(void)
{}
