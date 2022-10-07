#pragma once
#include <cmath>
#include <iostream>
#include "my_point.h"


namespace geometric_shapes {
	class circle
	{
	private:
		point centre_point;
		int radius;
	public:
		circle(point centre, int R) : centre_point(centre), radius(R) {
			if (radius == 0)
				std::cout << "Radius equals zero! ERROR\n";
		}

		double area();
		double perimeter();
		bool is_point_inside(point p_t);

	};

}