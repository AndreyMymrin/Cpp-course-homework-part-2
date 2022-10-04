#include <iostream>
#include "triangle.h"
#include "square.h"
#include "my_point.h"

namespace geometric_shapes {
    class triangle;
    class square;
    class circle;
};

int main()
{
    square squ_1({ 3,1 }, { 1,3 });
    squ_1.print_vertexes();
    std::cout << "\narea: " << squ_1.area() <<
        "\nperimeter: " << squ_1.perimeter() <<
        "\nis inside?: " << squ_1.is_point_inside({ 2,2 }) <<
        "\n ";

    
    triangle trian_1({ 1,1 }, { 1,4 }, { 5,1 });

    std::cout << "\narea: " << trian_1.area() <<
        "\nperimeter: " << trian_1.perimeter() <<
        "\nis inside?: " << trian_1.is_point_inside({ 2,2 }) <<
        "\n";
    trian_1.print_vertexes();
    
}