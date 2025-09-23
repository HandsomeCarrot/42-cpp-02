/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:15:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/23 19:57:59 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:

	//-----ex00-----//

	int					m_rawBits;
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
	
	float	operator<<(Fixed const &f);

	float	toFloat(void) const;
	int		toInt(void) const;
};

#endif