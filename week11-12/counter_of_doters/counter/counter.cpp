#include <iostream>

class BaseClass {
public:

    static int number;
    BaseClass() { number++; }
};
int BaseClass::number = 0;

class DotClass1 : public  BaseClass{};
class DotClass2 : public  BaseClass{};

class DotDotClass2 : public  DotClass2 {};

int main()
{
    BaseClass BC;

    DotClass1 DC11;
    DotClass1 DC12;
    DotClass1 DC13;

    DotClass2 DC2;
    DotDotClass2 DD2;
    std::cout << BC.number;
}