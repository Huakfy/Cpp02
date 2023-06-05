/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:28:58 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/05 11:53:20 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_fract;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);

		Fixed	&operator=(Fixed const &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
