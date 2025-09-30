/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:15:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/30 13:35:09 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/**
 * @brief Represents a fixed-point number.
 *
 * The Fixed class encapsulates a fixed-point number. It provides basic
 * functionality such as constructors, a destructor, and an assignment
 * operator, while logging these operations to the standard output.
 */
class Fixed
{
private:

	//-----ex00-----//

	/**
	 * @brief The raw value of the fixed-point number.
	 */
	int					m_rawBits;

	/**
	 * @brief The number of fractional bits.
	 * @note This is a constant static member, set to 8.
	 */
	int static const	m_fractionalBits = 8;

public:

	//-----ex00-----//

	Fixed(void);
	Fixed(Fixed const &other);
	~Fixed(void);

	Fixed	&operator=(Fixed const &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	//-----ex01-----//

	Fixed(int const number);
	Fixed(float const number);

	float	toFloat(void) const;
	int		toInt(void) const;

	//-----ex02-----//

	bool	operator>(Fixed const &other) const;
	bool	operator<(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;
	bool	operator==(Fixed const &other) const;
	bool	operator!=(Fixed const &other) const;

	Fixed	operator+(Fixed const &other) const;
	Fixed	operator-(Fixed const &other) const;
	Fixed	operator*(Fixed const &other) const;
	Fixed	operator/(Fixed const &other) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);
};

//-----ex01-----//

std::ostream	&operator<<(std::ostream &os, Fixed const &f);

#endif