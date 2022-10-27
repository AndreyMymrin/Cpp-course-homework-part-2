#include "figures.h"

double geometric_shapes::oblique_multiplication(point p_1, point p_2, point p_3)
{
	return (p_2 - p_1).x * (p_3 - p_1).y - (p_2 - p_1).y * (p_3 - p_1).x;
}
bool geometric_shapes::is_cross(point p_1, point p_2, point p_3, point p_4)
{
	if (oblique_multiplication(p_1, p_2, p_3) * oblique_multiplication(p_1, p_2, p_4) <= 0 &&
		oblique_multiplication(p_3, p_4, p_1) * oblique_multiplication(p_3, p_4, p_2) <= 0)
		return 1;
	else return 0;
}



void geometric_shapes::triangle::move(point rad_vec) {
    vertex_first += rad_vec;
    vertex_second += rad_vec;
    vertex_third += rad_vec;
}
std::vector<point> geometric_shapes::triangle::take_vertexes() {
    if ((vertex_first.x - vertex_second.x) * (vertex_first.y - vertex_third.y) -
        (vertex_first.y - vertex_second.y) * (vertex_first.x - vertex_third.x) > 0) {
        return { vertex_first, vertex_third,vertex_second };
    }
    else return { vertex_first, vertex_second, vertex_third };
}

double geometric_shapes::triangle::perimeter() {
    double size_12, size_23, size_13;
    size_12 = (vertex_first - vertex_second).distance();

    size_23 = (vertex_third - vertex_second).distance();

    size_13 = (vertex_first - vertex_third).distance();
    return size_12 + size_23 + size_13;
}
double geometric_shapes::triangle::area() {
    double size_12, size_23, size_13;
    size_12 = (vertex_first - vertex_second).distance();

    size_23 = (vertex_third - vertex_second).distance();

    size_13 = (vertex_first - vertex_third).distance();

    double p = 0.5 * (size_12 + size_23 + size_13);

    return sqrt(p * (p - size_12) * (p - size_23) * (p - size_13));
}

bool geometric_shapes::triangle::is_point_inside(point p_t) {
    triangle tr1(vertex_first, vertex_second, p_t);
    triangle tr2(vertex_second, vertex_third, p_t);
    triangle tr3(vertex_first, vertex_third, p_t);
    if (tr1.area() + tr2.area() + tr3.area() - area() < 10e-5)
        return 1;
    else return 0;
}
bool geometric_shapes::triangle::is_intersection(square& sq)
{
    std::vector<point> SquarePointsVector = sq.take_vertexes();
    std::vector<point> TrianPointsVector = take_vertexes();
    for (auto i : TrianPointsVector) {
        if (sq.is_point_inside(i)) return 1;
    }

    for (auto i : SquarePointsVector) {
        if (is_point_inside(i)) return 1;
    }

    for (int tr_coun = 0; tr_coun <= 2; tr_coun++) {
        for (int sq_coun = 0; sq_coun <= 3; sq_coun++) {
            if (is_cross(TrianPointsVector[tr_coun], TrianPointsVector[(tr_coun + 1) % 3],
                SquarePointsVector[sq_coun], SquarePointsVector[(sq_coun + 1) % 4])) return 1;
        }
    }
    return 0;
}
bool geometric_shapes::triangle::is_intersection(triangle& tr)
{
    std::vector<point> TrianPointsVector1 = take_vertexes();
    std::vector<point> TrianPointsVector2 = tr.take_vertexes();
    for (auto i : TrianPointsVector1) {
        if (tr.is_point_inside(i)) return 1;
    }

    for (auto i : TrianPointsVector2) {
        if (is_point_inside(i)) return 1;
    }

    for (int tr1_coun = 0; tr1_coun <= 2; tr1_coun++) {
        for (int tr2_coun = 0; tr2_coun <= 2; tr2_coun++) {
            if (is_cross(TrianPointsVector1[tr1_coun], TrianPointsVector1[(tr1_coun + 1) % 3],
                         TrianPointsVector2[tr2_coun], TrianPointsVector2[(tr2_coun + 1) % 3])) {
                return 1;
            }
        }
    }
    return 0;
}
bool geometric_shapes::triangle::is_intersection(circle& circ)
{
    std::vector<point> TrianPointsVector = take_vertexes();
    for (auto i : TrianPointsVector) {
        if (circ.is_point_inside(i)) return 1;
    }
    if (is_point_inside(circ.centre_point)) return 1;

    for (int i = 0; i <= 2; i++) {
        point p_1 = TrianPointsVector[i];
        point p_2 = TrianPointsVector[(i + 1) % 3];
        geometric_shapes::triangle t_trian(p_1, p_2, circ.centre_point);
        if ((circ.centre_point - p_2).distance() <= sqrt(circ.radius * circ.radius + (p_1 - p_2).distance() * (p_1 - p_2).distance()) &&
            (circ.centre_point - p_1).distance() <= sqrt(circ.radius * circ.radius + (p_1 - p_2).distance() * (p_1 - p_2).distance()) &&
            (t_trian.area() / (p_1 - p_2).distance() < circ.radius)) return 1;
    }
    return 0;
}



#define M_PI 3.1415


void geometric_shapes::circle::move(point rad_vec) {
    centre_point += rad_vec;
}
point geometric_shapes::circle::central_point() {
    return { centre_point };
}

double geometric_shapes::circle::area() {
    return M_PI * radius * radius;
}
double geometric_shapes::circle::perimeter() {
    return 2 * M_PI * radius;
}


bool geometric_shapes::circle::is_point_inside(point p_t) {
    if (pow(centre_point.x - p_t.x, 2) + pow(centre_point.y - p_t.y, 2) <= radius * radius)
        return 1;
    else return 0;
}
bool geometric_shapes::circle::is_intersection(circle& circ) {
    geometric_shapes::circle t_cir(centre_point, radius + circ.radius);
    return t_cir.is_point_inside(circ.centre_point);
}
bool geometric_shapes::circle::is_intersection(square& sq) {
    std::vector<point> SquarePointsVector = sq.take_vertexes();
    
    for (auto i : SquarePointsVector) {
        if (is_point_inside(i)) return 1;
    }
    if (sq.is_point_inside(centre_point)) return 1;

    for (int i = 0; i <= 3; i++) {
        point p_1 = SquarePointsVector[i];
        point p_2 = SquarePointsVector[(i + 1) % 4];
        geometric_shapes::triangle t_trian(p_1, p_2, centre_point);
        if ((centre_point - p_2).distance() <= sqrt(radius * radius + (p_1 - p_2).distance() * (p_1 - p_2).distance()) &&
            (centre_point - p_1).distance() <= sqrt(radius * radius + (p_1 - p_2).distance() * (p_1 - p_2).distance()) &&
            (t_trian.area() / (p_1 - p_2).distance() < radius)) return 1;
    }
    return 0;
}
bool geometric_shapes::circle::is_intersection(triangle& tr)
{
    return tr.is_intersection(*this);
}



void geometric_shapes::square::move(point rad_vec) {
    vertex_first += rad_vec;
    vertex_third += rad_vec;
}

std::vector<point> geometric_shapes::square::take_vertexes() {
    return {
        vertex_first,
        {0.5 * (vertex_third.x + vertex_first.x + vertex_first.y - vertex_third.y),
        0.5 * (vertex_third.y + vertex_third.x + vertex_first.y - vertex_first.x)},
        vertex_third,
        {0.5 * (vertex_third.x + vertex_first.x - vertex_first.y + vertex_third.y),
        0.5 * (vertex_third.y - vertex_third.x + vertex_first.y + vertex_first.x)}
    };
}

double geometric_shapes::square::area() {
    return 0.5 * (pow((vertex_first - vertex_third).distance(), 2));
}
double geometric_shapes::square::perimeter() {
    return 4 * sqrt(area());
}

bool geometric_shapes::square::is_point_inside(point p_t) {
    std::vector<point> SquarePointsVector = take_vertexes();
    triangle sq1({ SquarePointsVector[0], SquarePointsVector[1], p_t});
    triangle sq2({ SquarePointsVector[2], SquarePointsVector[1], p_t});
    triangle sq3({ SquarePointsVector[2], SquarePointsVector[3], p_t});
    triangle sq4({ SquarePointsVector[0], SquarePointsVector[3], p_t});
    if (abs(sq1.area() + sq2.area() + sq3.area() + sq4.area() - area()) < 10e-5)
        return 1;
    else return 0;
}
bool geometric_shapes::square::is_intersection(circle& circ)
{
    return circ.is_intersection(*this);
}
bool geometric_shapes::square::is_intersection(triangle& tr)
{
    return tr.is_intersection(*this);

}
bool geometric_shapes::square::is_intersection(square& sq) {
    std::vector<point> SquarePointsVector1 = take_vertexes();
    std::vector<point> SquarePointsVector2 = sq.take_vertexes();


    for (auto i : SquarePointsVector1) {
        if (sq.is_point_inside(i)) return 1;
    }

    for (auto i : SquarePointsVector2) {
        if (is_point_inside(i)) return 1;
    }

    for (int sq1_coun = 0; sq1_coun <= 3; sq1_coun++) {
        for (int sq2_coun = 0; sq2_coun <= 3; sq2_coun++) {
            if (is_cross(SquarePointsVector1[sq1_coun], SquarePointsVector1[(sq1_coun + 1) % 4],
                SquarePointsVector2[sq2_coun], SquarePointsVector2[(sq2_coun + 1) % 4])) return 1;
        }
    }
    return 0;
}
