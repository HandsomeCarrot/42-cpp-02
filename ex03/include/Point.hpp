/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:02:42 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 15:43:38 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
private:

	Fixed const	m_x;
	Fixed const	m_y;

public:

	Point(void);
	Point(Fixed const &x, Fixed const &y);
	Point(Point const &other);

	~Point(void);

	//Point	&operator=(Point const &other); //should it be here? vars are const, so you can not assign new values.

	Fixed const	&getX(void) const;
	Fixed const	&getY(void) const;
};

std::ostream	&operator<<(std::ostream &os, Point const &p);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif