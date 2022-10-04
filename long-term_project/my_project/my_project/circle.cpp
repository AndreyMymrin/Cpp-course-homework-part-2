#define _USE_MATH_DEFINES
#include "circle.h"

double circle::area() {
	return M_PI*radius*radius;
}
double circle::perimeter() {
	return 2 * M_PI * radius;
}
bool circle::is_point_inside(point p_t) {
	if (pow(centre_point.x - p_t.x, 2) + pow(centre_point.y - p_t.y, 2) <= radius * radius)
		return 1;
	else return 0;
}