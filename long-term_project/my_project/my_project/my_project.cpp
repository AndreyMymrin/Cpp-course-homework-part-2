#include <iostream>
#include "triangle.h"
namespace geometric_shapes {
    class triangle;
    class square;
    class circle;
};

int main()
{
    triangle trian_1;
    trian_1.new_vertexes({ 0,0 }, { 4,0 }, { 0,3 });


    std::cout <<"square: " <<  trian_1.square() <<
        "\nperimeter: " << trian_1.perimeter() << std::endl;
}
