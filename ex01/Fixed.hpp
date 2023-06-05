/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:28:58 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/05 12:37:57 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_value;
		static const int	_fract;
	public:
		//ex00
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);

		Fixed	&operator=(Fixed const &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//ex01
		Fixed(const int nb);
		Fixed(const float nb);

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
