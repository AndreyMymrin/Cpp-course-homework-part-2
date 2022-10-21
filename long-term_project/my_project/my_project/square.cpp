#include "figures.h"


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


bool geometric_shapes::square::intersection_with_square(geometric_shapes::square& sq) {

	SquarePointsVector[1] = {	 0.5 * (vertex_first.x + vertex_first.x + vertex_first.y - vertex_third.y),
								0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x) };
	SquarePointsVector[3] = {	0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
								0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x) };
	for (auto i : this->SquarePointsVector) {
		if (sq.is_point_inside(i)) return 1;
	}
	sq.SquarePointsVector[1] = { 0.5 * (sq.vertex_first.x + sq.vertex_first.x + sq.vertex_first.y - sq.vertex_third.y),
								 0.5 * (sq.vertex_third.y + sq.vertex_third.x + sq.vertex_first.y - sq.vertex_first.x) };
	sq.SquarePointsVector[3] = { 0.5 * (sq.vertex_third.x + sq.vertex_first.x - sq.vertex_first.y + sq.vertex_third.y),
								 0.5 * (sq.vertex_third.y - sq.vertex_third.x + sq.vertex_first.y + sq.vertex_first.x) };
	for (auto i : sq.SquarePointsVector) {
		if (is_point_inside(i)) return 1;
	}

	for (int sq1_coun = 0; sq1_coun <= 3; sq1_coun++) {
		for (int sq2_coun = 0; sq2_coun <= 3; sq2_coun++) {
			if (is_cross(SquarePointsVector[sq1_coun], SquarePointsVector[(sq1_coun + 1) % 4],
				sq.SquarePointsVector[sq2_coun], sq.SquarePointsVector[(sq2_coun + 1) % 4])) return 1;
		}
	}
	return 0;
}

/*
bool geometric_shapes::square::intersection_with_triangle(geometric_shapes::triangle& tr) {
	return tr.intersection_with_square(*this);
}
*/