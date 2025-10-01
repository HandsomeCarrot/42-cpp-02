/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 16:32:49 by vpoka            ###   ########.fr       */
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
	setRawBits(number << m_fractionalBits);
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
	return (m_rawBits >> m_fractionalBits);
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

//----------ex02----------//

/**
 * @brief Greater than comparison operator for Fixed objects.
 *
 * Compares the current Fixed object with another Fixed object by comparing
 * their internal raw bit representations. This comparison is exact since
 * it uses the underlying integer representation.
 *
 * @param other A constant reference to the Fixed object to compare against.
 * @return true if the current object is greater than the other object,
 *         false otherwise.
 */
bool	Fixed::operator>(Fixed const &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

/**
 * @brief Less than comparison operator for Fixed objects.
 *
 * Compares the current Fixed object with another Fixed object by comparing
 * their internal raw bit representations. This comparison is exact since
 * it uses the underlying integer representation.
 *
 * @param other A constant reference to the Fixed object to compare against.
 * @return true if the current object is less than the other object,
 *         false otherwise.
 */
bool	Fixed::operator<(Fixed const &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

/**
 * @brief Greater than or equal to comparison operator for Fixed objects.
 *
 * Compares the current Fixed object with another Fixed object by comparing
 * their internal raw bit representations. This comparison is exact since
 * it uses the underlying integer representation.
 *
 * @param other A constant reference to the Fixed object to compare against.
 * @return true if the current object is greater than or equal to the other
 *         object, false otherwise.
 */
bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

/**
 * @brief Less than or equal to comparison operator for Fixed objects.
 *
 * Compares the current Fixed object with another Fixed object by comparing
 * their internal raw bit representations. This comparison is exact since
 * it uses the underlying integer representation.
 *
 * @param other A constant reference to the Fixed object to compare against.
 * @return true if the current object is less than or equal to the other
 *         object, false otherwise.
 */
bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

/**
 * @brief Equality comparison operator for Fixed objects.
 *
 * Compares the current Fixed object with another Fixed object by comparing
 * their internal raw bit representations. This comparison is exact since
 * it uses the underlying integer representation.
 *
 * @param other A constant reference to the Fixed object to compare against.
 * @return true if the current object is equal to the other object,
 *         false otherwise.
 */
bool	Fixed::operator==(Fixed const &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

/**
 * @brief Inequality comparison operator for Fixed objects.
 *
 * Compares the current Fixed object with another Fixed object by comparing
 * their internal raw bit representations. This comparison is exact since
 * it uses the underlying integer representation.
 *
 * @param other A constant reference to the Fixed object to compare against.
 * @return true if the current object is not equal to the other object,
 *         false otherwise.
 */
bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->getRawBits() != other.getRawBits());
}


/**
 * @brief Addition operator for Fixed objects.
 *
 * Performs addition of two Fixed objects by adding their internal raw bit
 * representations. Since both operands are in fixed-point format with the
 * same fractional bits, the addition is direct without need for alignment.
 *
 * @param other A constant reference to the Fixed object to add to the
 *              current object.
 * @return A new Fixed object containing the sum of the two operands.
 */
Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	sum;

	sum.setRawBits(this->getRawBits() + other.getRawBits());
	return (sum);
}

/**
 * @brief Subtraction operator for Fixed objects.
 *
 * Performs subtraction of two Fixed objects by subtracting their internal
 * raw bit representations. Since both operands are in fixed-point format
 * with the same fractional bits, the subtraction is direct without need
 * for alignment.
 *
 * @param other A constant reference to the Fixed object to subtract from
 *              the current object.
 * @return A new Fixed object containing the difference of the two operands.
 */
Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	difference;

	difference.setRawBits(this->getRawBits() - other.getRawBits());
	return (difference);
}

/**
 * @brief Multiplication operator for Fixed objects.
 *
 * Performs multiplication of two Fixed objects by multiplying their
 * internal raw bit representations and then adjusting the result by
 * shifting right by the number of fractional bits to maintain the correct
 * fixed-point scale.
 *
 * @param other A constant reference to the Fixed object to multiply with
 *              the current object.
 * @return A new Fixed object containing the product of the two operands.
 */
Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	product;
	int		newRawBits;

	newRawBits = this->getRawBits() * other.getRawBits();
	newRawBits = newRawBits >> this->m_fractionalBits;
	product.setRawBits(newRawBits);
	return (product);
}

/**
 * @brief Division operator for Fixed objects.
 *
 * Performs division of two Fixed objects by first checking for division by
 * zero, then performing the division operation with proper scaling to
 * maintain the fixed-point format. The numerator is shifted left to
 * increase precision before division.
 *
 * @param other A constant reference to the Fixed object to divide by.
 * @return A new Fixed object containing the quotient of the two operands.
 * @warning If the denominator is zero, an error message is printed and
 *          a Fixed object with value 0 is returned.
 */
Fixed	Fixed::operator/(Fixed const &other) const
{
	if (other.getRawBits() == 0)
	{
		std::cout << "ERROR: denominator is 0 in divison" << std::endl;
		return (Fixed(0));
	}

	Fixed	quotient;
	int		newRawBits;
	int		numerator;

	numerator = this->getRawBits() << this->m_fractionalBits;
	newRawBits = numerator / other.getRawBits();
	quotient.setRawBits(newRawBits);
	return (quotient);
}


/**
 * @brief Prefix increment operator for Fixed objects.
 *
 * Increments the Fixed object by the smallest representable unit (1 in
 * the raw bit representation) and returns a reference to the modified
 * object. This operation increases the value by 1/256 (since there are
 * 8 fractional bits).
 *
 * @return A reference to the current object after incrementing.
 */
Fixed	&Fixed::operator++(void)
{
	++m_rawBits;
	return (*this);
}

/**
 * @brief Postfix increment operator for Fixed objects.
 *
 * Increments the Fixed object by the smallest representable unit (1 in
 * the raw bit representation) but returns a copy of the object before the
 * increment. This operation increases the value by 1/256 (since there are
 * 8 fractional bits).
 *
 * @return A copy of the object before incrementing.
 */
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	m_rawBits++;
	return (temp);
}

/**
 * @brief Prefix decrement operator for Fixed objects.
 *
 * Decrements the Fixed object by the smallest representable unit (1 in
 * the raw bit representation) and returns a reference to the modified
 * object. This operation decreases the value by 1/256 (since there are
 * 8 fractional bits).
 *
 * @return A reference to the current object after decrementing.
 */
Fixed	&Fixed::operator--(void)
{
	--m_rawBits;
	return (*this);
}

/**
 * @brief Postfix decrement operator for Fixed objects.
 *
 * Decrements the Fixed object by the smallest representable unit (1 in
 * the raw bit representation) but returns a copy of the object before the
 * decrement. This operation decreases the value by 1/256 (since there are
 * 8 fractional bits).
 *
 * @return A copy of the object before decrementing.
 */
Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	m_rawBits--;
	return (temp);
}


/**
 * @brief Finds the minimum of two Fixed objects (non-const version).
 *
 * Compares two Fixed objects and returns a reference to the one with the
 * smaller value. This version operates on non-const references, allowing
 * modification of the returned object.
 *
 * @param a Reference to the first Fixed object to compare.
 * @param b Reference to the second Fixed object to compare.
 * @return A reference to the smaller of the two Fixed objects.
 */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

/**
 * @brief Finds the minimum of two Fixed objects (const version).
 *
 * Compares two Fixed objects and returns a reference to the one with the
 * smaller value. This version operates on const references, preventing
 * modification of the returned object.
 *
 * @param a Constant reference to the first Fixed object to compare.
 * @param b Constant reference to the second Fixed object to compare.
 * @return A constant reference to the smaller of the two Fixed objects.
 */
Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

/**
 * @brief Finds the maximum of two Fixed objects (non-const version).
 *
 * Compares two Fixed objects and returns a reference to the one with the
 * larger value. This version operates on non-const references, allowing
 * modification of the returned object.
 *
 * @param a Reference to the first Fixed object to compare.
 * @param b Reference to the second Fixed object to compare.
 * @return A reference to the larger of the two Fixed objects.
 */
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

/**
 * @brief Finds the maximum of two Fixed objects (const version).
 *
 * Compares two Fixed objects and returns a reference to the one with the
 * larger value. This version operates on const references, preventing
 * modification of the returned object.
 *
 * @param a Constant reference to the first Fixed object to compare.
 * @param b Constant reference to the second Fixed object to compare.
 * @return A constant reference to the larger of the two Fixed objects.
 */
Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

