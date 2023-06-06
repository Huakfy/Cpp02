/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:06:56 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/06 11:33:51 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef POINT_HPP
# define POINT_HPP

class Point {
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		~Point();
		Point	&operator=(const Point &src);
		Fixed	getX();
		Fixed	getY();
};

bool	bsp(Point const v1, Point const v2, Point const v3, Point const pt);

#endif
