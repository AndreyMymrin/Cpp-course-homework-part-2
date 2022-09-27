#include <iostream>
enum class animals {
    dog,
    cat,
    cow,
    bird,
    fish,
    man
};

void WhatDoesTheFoxSay(animals WhyAreYou) {
    switch (WhyAreYou){
        case animals::dog: {std::cout << "gavgav" << std::endl; break;}
        case animals::cat: {std::cout << "maymay" << std::endl; break;}
        case animals::cow: {std::cout << "mymymy" << std::endl; break;}
        case animals::bird:{std::cout << "aaaa!!" << std::endl; break;}
        case animals::fish:{std::cout << "......" << std::endl; break;}
        case animals::man: {std::cout << "Hallo Word!" << std::endl; break;}

        default: {std::cout << "New animal? Eate it!" << std::endl; break;}
    }
}

int main()
{
    WhatDoesTheFoxSay(animals::cow);
    return(0);
}