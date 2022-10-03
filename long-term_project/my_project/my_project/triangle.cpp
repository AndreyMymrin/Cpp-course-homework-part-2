#include "triangle.h"

void triangle::new_vertexes(point v1, point v2, point v3) { 
    vertex_first = v1;
    vertex_second = v2;
    vertex_third = v3;
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
