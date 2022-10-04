#include "square.h"

void square::print_vertexes() {
	std::cout << 
		"(" << vertex_first.x << ";" << vertex_first.y << ") " <<
		"(" << vertex_second.x << ";" << vertex_second.y << ") " <<
		"(" << vertex_third.x << ";" << vertex_third.y << ") " <<
		"(" << vertex_fourth.x << ";" << vertex_fourth.y << ") " << std::endl;
}

double square::area() {
	return 0.5 * (pow(vertex_first.x - vertex_third.x, 2) +
		pow(vertex_first.y - vertex_third.y, 2));
}
double square::perimeter() {
	return 4 * sqrt(area());
}

bool square::is_point_inside(point p_t) {
	square sq1(vertex_first, p_t);
	square sq2(vertex_second, p_t);
	square sq3(vertex_third, p_t);
	square sq4(vertex_fourth, p_t);
	if (sq1.area() + sq2.area() + sq3.area() + sq4.area() - area() < 10e-5)
		return 1;
	else return 0;
}