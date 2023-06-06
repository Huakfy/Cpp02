/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:12:53 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/06 10:29:18 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	return;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return;
}

Point::Point(const Point &src) {
	*this = src;
	return;
}

Point::~Point() {
	return;
}

Point	&Point::operator=(const Point &src) {
	this->_x = src._x;
	this->_y = src._y;
	return *this;
}

Fixed	Point::getX() {
	return (this->_x);
}

Fixed	Point::getY() {
	return (this->_y);
}
