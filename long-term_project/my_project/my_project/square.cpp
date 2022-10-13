#include "triangle.h"
#include "square.h"


void geometric_shapes::square::move(point rad_vec) {
	vertex_first += rad_vec;
	vertex_third += rad_vec;
}

void geometric_shapes::square::take_vertexes(std::vector<point>* spv) {
	*spv = {
		vertex_first,
		{0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y),
		0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x)},
		vertex_third,
		{0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
		0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x)} 
	};
}

void geometric_shapes::square::print_vertexes() {
	std::cout << 
		"(" << vertex_first.x << ";" << vertex_first.y << ") " <<
		"(" << 0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y) << ";"
			<< 0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x) << ") " <<
		"(" << vertex_third.x << ";" << vertex_third.y << ") " <<
		"(" << 0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y)<< ";" 
			<< 0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x) << ") " << std::endl;
}

double geometric_shapes::square::area() {
	return 0.5 * (pow((vertex_first - vertex_third).distance(), 2));
}
double geometric_shapes::square::perimeter() {
	return 4 * sqrt(area());
}

bool geometric_shapes::square::is_point_inside(point p_t) {
	triangle sq1({ vertex_first,
				{ 0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y),
				0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x) }, p_t });
	triangle sq2({ vertex_third,
				{ 0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y),
				0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x) }, p_t });
	triangle sq3({ vertex_third,
				{ 0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
				0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x) }, p_t });
	triangle sq4({ vertex_first,
				{ 0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
				0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x) }, p_t });
	if (abs(sq1.area() + sq2.area() + sq3.area() + sq4.area() - area()) < 10e-5 )
		return 1;
	else return 0;
}