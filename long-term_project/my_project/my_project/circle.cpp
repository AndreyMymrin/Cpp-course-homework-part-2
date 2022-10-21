#define _USE_MATH_DEFINES
#include "figures.h"


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


bool geometric_shapes::circle::is_point_inside(point p_t) {
	if (pow(centre_point.x - p_t.x, 2) + pow(centre_point.y - p_t.y, 2) <= radius * radius)
		return 1;
	else return 0;
}

bool geometric_shapes::circle::intersection_with_circle(circle& circ){
	geometric_shapes::circle t_cir(centre_point, radius + circ.radius);
	return t_cir.is_point_inside(circ.centre_point);
}

bool geometric_shapes::circle::intersection_with_square(square& sq){
	sq.SquarePointsVector[1] = { 0.5 * (sq.vertex_first.x + sq.vertex_first.x + sq.vertex_first.y - sq.vertex_third.y),
								 0.5 * (sq.vertex_third.y + sq.vertex_third.x + sq.vertex_first.y - sq.vertex_first.x) };
	sq.SquarePointsVector[3] = { 0.5 * (sq.vertex_third.x + sq.vertex_first.x - sq.vertex_first.y + sq.vertex_third.y),
								 0.5 * (sq.vertex_third.y - sq.vertex_third.x + sq.vertex_first.y + sq.vertex_first.x) };
	for (auto i : sq.SquarePointsVector) {
		if (is_point_inside(i)) return 1;
	}
	if (sq.is_point_inside(centre_point)) return 1;

	for (int i = 0; i <= 3; i++) {
		point p_1 = sq.SquarePointsVector[i];
		point p_2 = sq.SquarePointsVector[(i + 1) % 4];
		geometric_shapes::triangle t_trian(p_1, p_2, centre_point);
		if ((centre_point - p_2).distance() <= sqrt(radius * radius + (p_1 - p_2).distance()*(p_1 - p_2).distance()) &&
			(centre_point - p_1).distance() <= sqrt(radius * radius + (p_1 - p_2).distance()*(p_1 - p_2).distance()) &&
			(t_trian.area()/(p_1-p_2).distance()< radius)) return 1;
	}
	return 0;
}