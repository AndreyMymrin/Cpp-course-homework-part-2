#include <iostream>
#include<string.h>
struct cars {
    int max_speed;
    int number_of_sits;
    int cost;
    bool elecrocar;
    bool is_it_can_fly;
    std::string name_of_company;
    std::string colour;

    std::string is_for_family(){

        if (max_speed < 90 && cost < 1000000 && number_of_sits >= 4) {
            return "Yes";
        }
        else {
            return "No";
        }
    };

    int how_cool_is_the_car() {
        int points = 0;
        if (name_of_company == "LADA") { points += 50; }
        else if (elecrocar == 1) { points += 25; }

        if (colour == "red") { max_speed += 50;}
        points += max_speed % 10;
        points -= number_of_sits;
        points += cost / 1000000;
        if (is_it_can_fly == 1) { points += 100;}
        return points;
    };
};

int main()
{
    cars car_1 = {2000, 4, 20000, 0, 0, "LADA", "red"};
    cars car_2 = { 100, 2, 50000000, 1, 0, "Tesla", "black" };
    cars car_3 = { 50, 6, 10000,0,1,"MIPT", "white" };
    
    std::cout << "Points of car_1: " << car_1.how_cool_is_the_car() << std::endl;
    std::cout << "Points of car_2: " << car_2.how_cool_is_the_car() << std::endl;
    std::cout << "Points of car_3: " << car_3.how_cool_is_the_car() << std::endl;

    std::cout << "Is car_1 for family: " << car_1.is_for_family() << std::endl;
    std::cout << "Is car_2 for family: " << car_2.is_for_family() << std::endl;
    std::cout << "Is car_3 for family: " << car_3.is_for_family() << std::endl;

    return 0;
}
