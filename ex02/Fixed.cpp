/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:26:37 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/05 15:55:53 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//ex00
Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed	&Fixed::operator=(Fixed const &fixed) {
	//std::cout << "Copy assignment operator called" << std::endl;
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
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nb << _fract);
	return;
}
#include <cstdio>
Fixed::Fixed(const float nb) {
	//std::cout << "Float constructor called" << std::endl;
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

//ex02
//>, <, >=, <=, == et !=
bool	Fixed::operator>(Fixed const &fixed) {
	if (this->getRawBits() > fixed.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator<(Fixed const &fixed) {
	if (this->getRawBits() < fixed.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator>=(Fixed const &fixed) {
	if (this->getRawBits() >= fixed.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator<=(Fixed const &fixed) {
	if (this->getRawBits() < fixed.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator==(Fixed const &fixed) {
	if (this->getRawBits() == fixed.getRawBits())
		return 1;
	return 0;
}

bool	Fixed::operator!=(Fixed const &fixed) {
	if (this->getRawBits() != fixed.getRawBits())
		return 1;
	return 0;
}

//+, -, *, et /
float	Fixed::operator+(Fixed const &fixed) {
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed const &fixed) {
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed const &fixed) {
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed const &fixed) {
	return (this->toFloat() / fixed.toFloat());
}

//++ --
Fixed&	Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed&	Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	--*this;
	return temp;
}

//min max
Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a.operator<(b))
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a.operator>(b))
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}
