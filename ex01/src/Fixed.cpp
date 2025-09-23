/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/23 21:40:15 by vpoka            ###   ########.fr       */
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

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
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
	int num, fraction;

	std::cout << "Float constructor called" << std::endl;
	num = (int)number << 8;
	fraction = 0;
	setRawBits(num);
}
