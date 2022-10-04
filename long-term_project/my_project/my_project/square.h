#pragma once
#include <cmath>
#include <iostream>
#include "my_point.h"
class square
{
	point vertex_first;
	point vertex_third;
	point vertex_second = { 0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y),
			0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x) };
	point vertex_fourth = { 0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
		0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x) };

public:
	square(point v1, point v3) :
		vertex_first(v1), vertex_third(v3) {}

	double area();
	double perimeter();
	void print_vertexes();
	bool is_point_inside(point p_t);
};

