#include <iostream>
int fibonacci_numbers(int number) {
    int time_nmb;
    static int f_number = 1;
    static int previous_f_number = 0;
    static int counter = 1;
    if (counter == 1) {
        f_number = 1;
        previous_f_number = 0;
    }
    //std::cout << f_number << ' ';
    if (counter < number) {
        time_nmb = f_number;
        f_number += previous_f_number;
        previous_f_number = time_nmb;
        counter++;
        fibonacci_numbers(number);
    }
    counter = 1;
    int a = f_number;

    return a;
}
int main()
{
    int number;
    while (true) {
        std::cout << "Enter the number of the Fibonacci number"
            "or 0 to close\n";
        std::cin >> number;
        if (number == 0) break;
        std::cout << "Your Fibonacci number is " 
            << fibonacci_numbers(number) << "\n\n";
    }
}