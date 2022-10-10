#define _USE_MATH_DEFINES
#include "circle.h"

void geometric_shapes::circle::move(point rad_vec) {
	centre_point += rad_vec;
}
point geometric_shapes::circle::central_point() {
	return { centre_point };
}
double geometric_shapes::circle::area() {
	return M_PI*radius*radius;
}
double geometric_shapes::circle::perimeter() {
	return 2 * M_PI * radius;
}

namespace geometric_shapes {
	bool circle::is_point_inside(point p_t) {
		if (pow(centre_point.x - p_t.x, 2) + pow(centre_point.y - p_t.y, 2) <= radius * radius)
			return 1;
		else return 0;
	}
}