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
    point A = { 1,2 };
    point B = { 4,5 };
    std::cout << "A + B = ";
    (A + B).print();
    std::cout << "A - B = ";
    (A - B).print();
    A += B;
    std::cout << "A += B;\nA = ";
    A.print();
    A -= B;
    std::cout << "A += B;\nA = ";
    A.print();

    
    std::cout << "\tCircle\n";
    geometric_shapes::circle cir_1({ 3,3 }, 1);
    std::cout << 
        "Area: " << cir_1.area() <<
        "\nPerimeter: " << cir_1.perimeter() <<
        "\nIs inside: " << cir_1.is_point_inside({ 2.5,2.5 }) <<
        "\n";
    cir_1.move({ 2,2 });
    cir_1.central_point().print();
    
    std::cout << "\tSquare\n";
    geometric_shapes::square squ_1({ 3,1 }, { 1,3 });
    squ_1.print_vertexes();
    std::cout <<
        "Area: " << squ_1.area() <<
        "\nPerimeter: " << squ_1.perimeter() <<
        "\nIs inside: " << squ_1.is_point_inside({ 2,2 }) <<
        "\n";
    squ_1.take_vertexes(&squ_1.SquarePointsVector);
    for (auto i : squ_1.SquarePointsVector)
    {
        std::cout << "(" << i.x << ";" << i.y << ") ";
    }
    std::cout << "--------------------------\n";
    squ_1.move({ 2,2 });
    squ_1.take_vertexes(&squ_1.SquarePointsVector);
    for (auto i : squ_1.SquarePointsVector)
    {
        std::cout << "(" << i.x << ";" << i.y << ") ";
    }
    
    std::cout << "\n\tTriangle\n";
    geometric_shapes::triangle trian_1({ 1,1 }, { 5,1 }, { 1,4 });

    trian_1.print_vertexes();
    std::cout << 
        "Area: " << trian_1.area() <<
        "\nPerimeter: " << trian_1.perimeter() <<
        "\nIs inside: " << trian_1.is_point_inside({ 2,2 }) <<
        "\n";
    trian_1.take_vertexes(&trian_1.TrianPointsVector);
    for (auto i : trian_1.TrianPointsVector)
    {
        std::cout<< "(" << i.x << ";" << i.y << ") ";
    }
    std::cout << "--------------------------\n";
    trian_1.move({ 2,2 });
    trian_1.take_vertexes(&trian_1.TrianPointsVector);
    for (auto i : trian_1.TrianPointsVector)
    {
        std::cout << "(" << i.x << ";" << i.y << ") ";
    }
}