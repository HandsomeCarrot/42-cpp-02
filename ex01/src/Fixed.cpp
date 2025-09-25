/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/25 13:50:05 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//----------ex00----------//

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
 * @param old The Fixed object to assign from.
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

//----------ex01----------//

Fixed::Fixed(int const number)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(number << 8);
}

Fixed::Fixed(float const number)
{
	int	rawBits;

	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(number * (1 << m_fractionalBits)); 
	setRawBits(rawBits);
}

float	Fixed::toFloat(void) const
{
	float	inFloat;

	inFloat = m_rawBits;
	inFloat /= (1 << m_fractionalBits);
	return (inFloat);
}

int	Fixed::toInt(void) const
{
	return (m_rawBits >> 8);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}
