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

    point A = { 1,2 };
    point B = { 3,4 };
    
    std::cin >> cir_1;
    std::cout << trian_1 << "\n" << cir_1 << "\n" << squ_1;

}