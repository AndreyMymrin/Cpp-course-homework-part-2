#include <iostream>

int invert(int number) {
    static int InvNumber = 0;
    InvNumber = InvNumber * 10 +(number % 10);
    if (number / 10 != 0) { invert(number / 10); }
    return InvNumber;
}
int main()
{
    int number = 123456789;
    std::cout << invert(number);
}
