/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:15:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/25 13:45:26 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

	Fixed(void);
	Fixed(Fixed const &other);
	~Fixed(void);

	Fixed	&operator=(Fixed const &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif