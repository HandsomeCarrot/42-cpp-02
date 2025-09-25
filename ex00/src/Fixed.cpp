/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/25 13:45:01 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Default constructor for the Fixed class.
 *
 * Initializes the fixed-point number to 0. A message is printed to standard
 * output to indicate that the default constructor has been called.
 */
Fixed::Fixed(void) :
	m_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Copy constructor for the Fixed class.
 *
 * Creates a new Fixed object as a copy of an existing one. A message is
 * printed to standard output.
 *
 * @param other The Fixed object to copy from.
 */
Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Destructor for the Fixed class.
 *
 * Cleans up the Fixed object. A message is printed to standard output to
 * indicate that the destructor has been called.
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Copy assignment operator for the Fixed class.
 *
 * Assigns the value of another Fixed object to this one. A message is
 * printed to standard output.
 *
 * @param other The Fixed object to assign from.
 * @return A reference to the current object.
 */
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

/**
 * @brief Gets the raw value of the fixed-point number.
 *
 * @return The raw integer value of the fixed-point number.
 */
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_rawBits);
}

/**
 * @brief Sets the raw value of the fixed-point number.
 *
 * @param raw The new raw integer value to set.
 */
void	Fixed::setRawBits(int const raw)
{
	m_rawBits = raw;
}
