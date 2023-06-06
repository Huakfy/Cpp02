/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:28:58 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/05 15:59:35 by mjourno          ###   ########.fr       */
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

		//ex02
		bool	operator>(Fixed const &fixed);
		bool	operator<(Fixed const &fixed);
		bool	operator>=(Fixed const &fixed);
		bool	operator<=(Fixed const &fixed);
		bool	operator==(Fixed const &fixed);
		bool	operator!=(Fixed const &fixed);

		Fixed	operator+(Fixed const &fixed);
		Fixed	operator-(Fixed const &fixed);
		Fixed	operator*(Fixed const &fixed);
		Fixed	operator/(Fixed const &fixed);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
