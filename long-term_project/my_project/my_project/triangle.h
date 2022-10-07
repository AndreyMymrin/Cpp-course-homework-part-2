#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <iostream>
#include "my_point.h"

namespace geometric_shapes {
	class triangle
	{
	private:
		point vertex_first;
		point vertex_second;
		point vertex_third;

	public:
		std::vector<point> TrianPointsVector = { vertex_first,vertex_second,vertex_third };

		double area();
		double perimeter();
		void print_vertexes();
		bool is_point_inside(point p_t);

		triangle(point v1, point v2, point v3) :
			vertex_first(v1), vertex_second(v2), vertex_third(v3) {
			if (area() == 0) {
					std::cout << "Something wrong in triangle's vertexes\n";
			}
			if ((vertex_first.x - vertex_second.x) * (vertex_first.y - vertex_third.y) -
				(vertex_first.y - vertex_second.y) * (vertex_first.x - vertex_third.x) > 0) {
				TrianPointsVector = { vertex_first, vertex_third,vertex_second };
			}
			else {
				TrianPointsVector = { vertex_first, vertex_second, vertex_third };
			}
		};
	};
}
