/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:26:37 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/05 14:01:35 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//ex00
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed	&Fixed::operator=(Fixed const &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
	return;
}

const int	Fixed::_fract = 8;

//ex01
Fixed::Fixed(const int nb) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb << _fract);
	return;
}
#include <cstdio>
Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(nb * (1 << _fract));
	return;
}

float	Fixed::toFloat(void) const {
	return (this->getRawBits() / (float)(1 << _fract));
}

int		Fixed::toInt( void ) const {
	return (this->getRawBits() >> _fract);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}
