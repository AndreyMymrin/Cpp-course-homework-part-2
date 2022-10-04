#pragma once
#include <cmath>
#include <iostream>
#include "my_point.h"
class triangle
{
	point vertex_first;
	point vertex_second;
	point vertex_third;
public:
	triangle(point v1, point v2, point v3) :
		vertex_first(v1), vertex_second(v2), vertex_third(v3) {
		if (square() == 0) {
			std::cout << "Something wrong in triangle's vertexes\n";
		}
	}

	double square();
	double perimeter();
	void print_vertexes();
	bool is_point_inside(point p_t);

};

