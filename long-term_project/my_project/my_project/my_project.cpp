#include <iostream>
#include "triangle.h"
#include "square.h"
#include "my_point.h"
#include "circle.h"

namespace geometric_shapes {
    class triangle;
    class square;
    class circle;
};

int main()
{
    circle cir_1({ 3,3 }, 1);
    std::cout << "\tCircle\nArea: " << cir_1.area() <<
        "\nPerimeter: " << cir_1.perimeter() <<
        "\nIs inside: " << cir_1.is_point_inside({ 2.5,2.5 }) <<
        "\n ";

    square squ_1({ 3,1 }, { 1,3 });
    std::cout << "\tSquare\n";
    squ_1.print_vertexes();
    std::cout <<
        "Area: " << squ_1.area() <<
        "\nPerimeter: " << squ_1.perimeter() <<
        "\nIs inside: " << squ_1.is_point_inside({ 2,2 }) <<
        "\n ";
    
    std::cout << "\tTriangle\n";
    triangle trian_1({ 1,1 }, { 1,4 }, { 5,1 });
    trian_1.print_vertexes();
    std::cout << 
        "Area: " << trian_1.area() <<
        "\nPerimeter: " << trian_1.perimeter() <<
        "\nIs inside: " << trian_1.is_point_inside({ 2,2 }) <<
        "\n";
}