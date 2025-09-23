/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:15:07 by vpoka             #+#    #+#             */
/*   Updated: 2025/09/23 18:33:50 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:

	int					rawBits;
	static const int	fractionalBits = 8;

public:

	Fixed(void);
	Fixed(Fixed &fixed);
	~Fixed(void);

	Fixed	&operator=(const Fixed &) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif