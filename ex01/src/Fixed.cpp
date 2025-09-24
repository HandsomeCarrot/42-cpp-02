/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/24 10:59:11 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//----------ex00----------//

Fixed::Fixed(void) :
	m_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(old.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_rawBits);
}

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
	int 	full;
	float	fraction;

	std::cout << "Float constructor called" << std::endl;
	full = (int)number << 8;
	fraction = number - full;
	fraction *= 100000000;
	setRawBits(full + (int)fraction);
}

void	Fixed::operator<<(Fixed const &f)
{
	int	rawBits, full, fraction;

	rawBits = f.getRawBits();
	full = rawBits >> 8;
	fraction = 0;
}
