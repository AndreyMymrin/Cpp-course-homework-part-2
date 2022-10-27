#include <iostream>
#include <vector>
#include "figures.h"

int main()
{
    std::cout << "\tCircle\n";
    geometric_shapes::circle cir_1({ -3,0 }, 7);

    std::cout << "\tSquare\n";
    geometric_shapes::square squ_1({ 1,1 }, { 4,4 });
    geometric_shapes::square squ_2({ 0,2 }, { 10,0 });


    std::cout << "\tTriangle\n";
    geometric_shapes::triangle trian_1({ 0,0 },{ 30,0 }, { 0,4 } );
    

    for (auto i : trian_1.take_vertexes()) {
        std::cout << i << "\n";
    }
    
    trian_1.move({ 0.5, 2 });
    for (auto i : trian_1.take_vertexes()) {
        std::cout << i << "\n";
    }
    
}