#include "figures.h"


void geometric_shapes::triangle::move(point rad_vec) {
    vertex_first += rad_vec;
    vertex_second += rad_vec;
    vertex_third += rad_vec;
}

void geometric_shapes::triangle::take_vertexes(std::vector<point>* tpv){
    if ((vertex_first.x - vertex_second.x) * (vertex_first.y - vertex_third.y) -
        (vertex_first.y - vertex_second.y) * (vertex_first.x - vertex_third.x) > 0) {
        *tpv = {vertex_first, vertex_third,vertex_second};
    }
    else {
        *tpv = { vertex_first, vertex_second, vertex_third };
    }
}

bool geometric_shapes::triangle::is_point_inside(point p_t) {
    triangle tr1(vertex_first, vertex_second, p_t);
    triangle tr2(vertex_second, vertex_third, p_t);
    triangle tr3(vertex_first, vertex_third, p_t);
    if (tr1.area() + tr2.area() + tr3.area() - area() < 10e-5) 
        return 1;
    else return 0;
}

void geometric_shapes::triangle::print_vertexes() {
   // [v1v2;v1v3] <> 0
    if ((vertex_first.x - vertex_second.x) * (vertex_first.y - vertex_third.y) -
        (vertex_first.y - vertex_second.y) * (vertex_first.x - vertex_third.x) > 0) {
        std::cout << 
            "(" << vertex_first.x << ";" << vertex_first.y << ") " <<
            "(" << vertex_third.x << ";" << vertex_third.y << ") " <<
            "(" << vertex_second.x << ";" << vertex_second.y << ") " << std::endl;
    }
    else {
        std::cout << 
            "(" << vertex_first.x << ";" << vertex_first.y << ") " <<
            "(" << vertex_second.x << ";" << vertex_second.y << ") " <<
            "(" << vertex_third.x << ";" << vertex_third.y << ") " << std::endl;
    }
}

double geometric_shapes::triangle::perimeter() {
    double size_12, size_23, size_13;
    size_12 = sqrt(pow(vertex_first.x - vertex_second.x, 2) +
        pow(vertex_first.y - vertex_second.y, 2));

    size_23 = sqrt(pow(vertex_third.x - vertex_second.x, 2)
        + pow(vertex_third.y - vertex_second.y, 2));

    size_13 = sqrt(pow(vertex_first.x - vertex_third.x, 2)
        + pow(vertex_first.y - vertex_third.y, 2));
    return size_12 + size_23 + size_13;
}


double geometric_shapes::triangle::area(){
    double size_12, size_23, size_13;
    size_12 = sqrt(pow(vertex_first.x - vertex_second.x, 2) +
        pow(vertex_first.y - vertex_second.y, 2));

    size_23 = sqrt(pow(vertex_third.x - vertex_second.x, 2)
        + pow(vertex_third.y - vertex_second.y, 2));

    size_13 = sqrt(pow(vertex_first.x - vertex_third.x, 2)
        + pow(vertex_first.y - vertex_third.y, 2));

    double p = 0.5 * (size_12 + size_23 + size_13);

    return sqrt(p*(p-size_12)*(p-size_23)*(p-size_13));
}

bool geometric_shapes::triangle::intersection_with_square(geometric_shapes::square& sq)
{
    for (auto i : this->TrianPointsVector) {
        if (sq.is_point_inside(i)) return 1;
    }
    sq.SquarePointsVector[1] = { 0.5 * (sq.vertex_first.x + sq.vertex_first.x + sq.vertex_first.y - sq.vertex_third.y),
                                 0.5 * (sq.vertex_third.y + sq.vertex_third.x + sq.vertex_first.y - sq.vertex_first.x)};
    sq.SquarePointsVector[3] = { 0.5 * (sq.vertex_third.x + sq.vertex_first.x - sq.vertex_first.y + sq.vertex_third.y),
                                 0.5 * (sq.vertex_third.y - sq.vertex_third.x + sq.vertex_first.y + sq.vertex_first.x)};
    for (auto i : sq.SquarePointsVector) {
        if (is_point_inside(i)) return 1;
    }

    for (int tr_coun = 0; tr_coun <= 2; tr_coun++) {
        for (int sq_coun = 0; sq_coun <= 3; sq_coun++) {
            if (is_cross(TrianPointsVector[tr_coun], TrianPointsVector[(tr_coun + 1) % 3],
                sq.SquarePointsVector[sq_coun], sq.SquarePointsVector[(sq_coun + 1) % 4])) return 1;
        }
    }
    return 0;
}

bool geometric_shapes::triangle::intersection_with_triangle(triangle& tr)
{
    for (auto i : TrianPointsVector) {
        if (tr.is_point_inside(i)) return 1;
    }
    
    for (auto i : tr.TrianPointsVector) {
        if (is_point_inside(i)) return 1;
    }

    for (int tr1_coun = 0; tr1_coun <= 2; tr1_coun++) {
        for (int tr2_coun = 0; tr2_coun <= 2; tr2_coun++) {
            if (is_cross(TrianPointsVector[tr1_coun], TrianPointsVector[(tr1_coun + 1) % 3],
                tr.TrianPointsVector[tr2_coun], tr.TrianPointsVector[(tr2_coun + 1) % 3])) {
                std::cout << tr2_coun;  return 1;
            }
        }
    }
    return 0;
}

bool geometric_shapes::triangle::intersection_with_circle(circle& circ)
{
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

