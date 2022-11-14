#include <iostream>
#include <vector>
#include "figures.h"

using namespace geometric_shapes;

int main()
{
    circle cir_1({ 3,0 }, 2);

    square squ_1({ 1,1 }, { 4,4 });
    square squ_2({ 0,-2 }, { 1,0 });

    triangle trian_1({ 0,0 }, { 3,0 }, { 0,4 });

    
    
    std::vector<shapes*> shapes_vector = { dynamic_cast<shapes*>(&squ_1), dynamic_cast<shapes*>(&squ_2),
                                           dynamic_cast<shapes*>(&trian_1), dynamic_cast<shapes*>(&cir_1)};

    for (auto i : shapes_vector) {
        i->move({ 1,1 });
    }
    for (auto i : shapes_vector) {
        std::cout << *i << std::endl;
    }
    return 0;
};