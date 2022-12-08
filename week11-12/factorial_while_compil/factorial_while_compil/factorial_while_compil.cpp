#include <iostream>

template<int n>
class fact {
public:
    static const int number = fact<n - 1>::number * n;
};

template<>
class fact<0> {
public:
    static const int number = 1;
};

int main() {
    int n = 5;
    std::cout << n << "! = " << fact<5>::number;
    
}