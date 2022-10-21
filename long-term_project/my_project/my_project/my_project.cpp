#include <iostream>
#include <vector>
#include "figures.h"

int main()
{
    std::cout << "\tCircle\n";
    geometric_shapes::circle cir_1({ -3,0 }, 2);

    std::cout << "\tSquare\n";
    geometric_shapes::square squ_1({ 1,1 }, { 4,4 });

    std::cout << "\tTriangle\n";
    geometric_shapes::triangle trian_1({ 0,0 },{ 30,0 }, { 0,4 } );

    std::cout << trian_1.intersection_with_circle(cir_1);
}