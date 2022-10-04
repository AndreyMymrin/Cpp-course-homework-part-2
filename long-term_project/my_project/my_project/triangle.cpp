#include "triangle.h"

bool triangle::is_point_inside(point p_t) {
    triangle tr1(vertex_first, vertex_second, p_t);
    triangle tr2(vertex_second, vertex_third, p_t);
    triangle tr3(vertex_first, vertex_third, p_t);
    if (tr1.square() + tr2.square() + tr3.square() - square() < 10e-5) 
        return 1;
    else return 0;
}

void triangle::print_vertexes() {
   // [v1v2;v1v3] <> 0
    if ((vertex_first.x - vertex_second.x) * (vertex_first.y - vertex_third.y) -
        (vertex_first.y - vertex_second.y) * (vertex_first.x - vertex_third.x) > 0) {
        std::cout << 
            "(" << vertex_first.x << ";" << vertex_first.y << ") " <<
            "(" << vertex_third.x << ";" << vertex_third.y << ") "<<
            "(" << vertex_second.x << ";" << vertex_second.y << ") " << std::endl;
    }
    else {
        std::cout << 
            "(" << vertex_first.x << ";" << vertex_first.y << ") " <<
            "(" << vertex_second.x << ";" << vertex_second.y << ") " <<
            "(" << vertex_third.x << ";" << vertex_third.y << ") " << std::endl;
    }
}

double triangle::perimeter() {
    double size_12, size_23, size_13;
    size_12 = sqrt(pow(vertex_first.x - vertex_second.x, 2) +
        pow(vertex_first.y - vertex_second.y, 2));

    size_23 = sqrt(pow(vertex_third.x - vertex_second.x, 2)
        + pow(vertex_third.y - vertex_second.y, 2));

    size_13 = sqrt(pow(vertex_first.x - vertex_third.x, 2)
        + pow(vertex_first.y - vertex_third.y, 2));
    return size_12 + size_23 + size_13;
}


double triangle::square(){
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
