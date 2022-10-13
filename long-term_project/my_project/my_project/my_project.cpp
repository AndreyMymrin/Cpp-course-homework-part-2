#include <iostream>
#include <vector>
#include "triangle.h"
#include "square.h"
#include "circle.h"

namespace geometric_shapes {
    class triangle;
    class square;
    class circle;
};

int main()
{
    
    std::cout << "\tCircle\n";
    geometric_shapes::circle cir_1({ 3,3 }, 1);
    
    std::cout << "\tSquare\n";
    geometric_shapes::square squ_1({ 1,1 }, { 4,4 });
  
    std::cout << "\tTriangle\n";
    geometric_shapes::triangle trian_1({ 0,0 }, { 6,6 }, { 7,8 });

    std::cout << trian_1.intersection_with_square(&squ_1);

}