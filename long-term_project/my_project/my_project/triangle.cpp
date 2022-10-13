#include "triangle.h"


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

bool geometric_shapes::triangle::intersection_with_square(geometric_shapes::square* sq)
{
    int counter = 0;
    point pt;
    
    
    while (pow((pt-vertex_second).x,2) + pow((pt - vertex_second).y, 2) < 10e-3) {

        counter += is_point_inside(pt);
        pt += (vertex_second - vertex_first) * 10e-3;
    }


    if (counter != 0) { return 1; }
    else return 0;
}