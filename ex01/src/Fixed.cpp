/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/26 13:27:39 by vpoka            ###   ########.fr       */
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

/**
 * @brief Constructor that initializes the Fixed object from an integer.
 *
 * Converts the provided integer to the internal fixed-point representation
 * by shifting the value left by the number of fractional bits (8). A
 * message is printed to standard output to indicate that the integer
 * constructor has been called.
 *
 * @param number The integer value to convert to fixed-point format.
 */
Fixed::Fixed(int const number)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(number << 8);
}

/**
 * @brief Constructor that initializes the Fixed object from a float.
 *
 * Converts the provided floating-point number to the internal fixed-point
 * representation by multiplying by 2^fractionalBits and rounding to the
 * nearest integer. A message is printed to standard output to indicate
 * that the float constructor has been called.
 *
 * @param number The floating-point value to convert to fixed-point format.
 */
Fixed::Fixed(float const number)
{
	int	rawBits;

	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(number * (1 << m_fractionalBits));
	setRawBits(rawBits);
}

/**
 * @brief Converts the fixed-point value to a floating-point number.
 *
 * Transforms the internal fixed-point representation back to a
 * floating-point value by dividing the raw bits by 2^fractionalBits.
 * This provides the decimal representation of the stored value.
 *
 * @return The floating-point representation of the fixed-point number.
 */
float	Fixed::toFloat(void) const
{
	return ((float)m_rawBits / (1 << m_fractionalBits));
}

/**
 * @brief Converts the fixed-point value to an integer.
 *
 * Transforms the internal fixed-point representation back to an integer
 * value by shifting the raw bits right by the number of fractional bits
 * (8). This effectively discards the fractional part and returns only
 * the integer portion.
 *
 * @return The integer representation of the fixed-point number.
 */
int	Fixed::toInt(void) const
{
	return (m_rawBits >> 8);
}

/**
 * @brief Stream insertion operator for the Fixed class.
 *
 * Overloads the << operator to allow Fixed objects to be directly
 * inserted into output streams. The Fixed object is converted to its
 * floating-point representation before being inserted into the stream.
 *
 * @param os A reference to the output stream to write to.
 * @param f A constant reference to the Fixed object to be output.
 * @return A reference to the output stream for chaining operations.
 */
std::ostream	&operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}

