/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:02:42 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/30 17:01:55 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:

	Fixed const	m_x;
	Fixed const	m_y;

public:

	Point(void);
	Point(Fixed const &x, Fixed const &y);
	Point(Point const &other);

	//Point	&operator=(Point const &other); //should it be here? vars are const, so you can not assign new values.

	~Point(void);

};
#endif