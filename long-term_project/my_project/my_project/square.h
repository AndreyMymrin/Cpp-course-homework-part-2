#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include "my_point.h"
//#include "triangle.h"





namespace geometric_shapes {

	class triangle;

	class square
	{
	private:
		point vertex_first;
		point vertex_second;
		point vertex_third;
		point vertex_fourth;
		
	public:

	friend bool triangle::intersection_with_square(square& sq );
		std::vector<point> SquarePointsVector = { vertex_first,vertex_second,
			vertex_third, vertex_fourth};
		square(point v1, point v3) :
			vertex_first(v1), vertex_third(v3) {
			if (area() == 0) {
				std::cout << "Something wrong in square's vertexes\n";
			}
		}
		void take_vertexes(std::vector<point>* spv);
		double area();
		double perimeter();
		void print_vertexes();
		bool is_point_inside(point p_t);
		void move(point rad_vec);

		
	};
}

/*
point vertex_second = { 0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y),
					    0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x) };
point vertex_fourth = { 0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
						0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x) };
*/