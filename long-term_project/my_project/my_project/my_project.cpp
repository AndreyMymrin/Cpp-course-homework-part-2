#include <iostream>
#include <vector>
#include "triangle.h"
#include "square.h"
#include "circle.h"



int main()
{

    std::cout << "\tCircle\n";
    geometric_shapes::circle cir_1({ 3,3 }, 1);
    
    std::cout << "\tSquare\n";
    geometric_shapes::square squ_1({ 1,1 }, { 4,4 });
  
    std::cout << "\tTriangle\n";
    geometric_shapes::triangle trian_1({ 0,0 },{ -3,8 }, { 6,4 } );

    std::cout << trian_1.intersection_with_circle(cir_1);


}