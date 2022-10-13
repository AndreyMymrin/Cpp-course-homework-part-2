#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <iostream>
#include "my_point.h"
//#include "square.h"





namespace geometric_shapes {

	class square;
	class circle;
	class triangle
	{
	private:
		point vertex_first;
		point vertex_second;
		point vertex_third;
		
	public:
		std::vector<point> TrianPointsVector = { vertex_first,vertex_second,vertex_third };
		triangle(point v1, point v2, point v3) :
			vertex_first(v1), vertex_second(v2), vertex_third(v3) {
			if (area() == 0) {
				std::cout << "Something wrong in triangle's vertexes\n";
			}
		}

		void take_vertexes(std::vector<point>* tpv);
		double area();
		double perimeter();
		void print_vertexes();
		bool is_point_inside(point p_t);
		void move(point rad_vec);

		bool intersection_with_square(square& sq);
		bool intersection_with_circle(circle& circ);
	};
}
