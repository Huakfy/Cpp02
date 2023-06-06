/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:06:48 by mjourno           #+#    #+#             */
/*   Updated: 2023/06/06 11:30:53 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

//https://stackoverflow.com/questions/17692922/check-is-a-point-x-y-is-between-two-points-drawn-on-a-straight-line
float	distance(Point p1, Point p2) {
	return sqrt(pow(p2.getX().toFloat() - p1.getX().toFloat(), 2) + pow(p2.getY().toFloat() - p1.getY().toFloat(), 2) * 1.0);
}

bool	pointIsOnEdge(Point v1, Point v2, Point pt) {
	if (distance(v1, v2) == (distance(v1, pt) + distance(v2, pt)))
		return (true);
	return (false);
}

//https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
Fixed	sign(Point p1, Point p2, Point p3) {
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool	bsp(Point const v1, Point const v2, Point const v3, Point const pt) {
	Fixed	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = sign(pt, v1, v2);
	d2 = sign(pt, v2, v3);
	d3 = sign(pt, v3, v1);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	if (pointIsOnEdge(v1, v2, pt) || pointIsOnEdge(v1, v3, pt) || pointIsOnEdge(v2, v3,pt))
		return (false);

	return !(has_neg && has_pos);
}
