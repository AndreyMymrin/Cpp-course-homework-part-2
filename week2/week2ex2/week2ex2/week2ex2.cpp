#include <iostream>
#include <vector>


int main() // BUBBLE
{
    srand(time(0));

    std::vector<int> v;
    int n;
    std::cout << "Bubble sort\nEnter the size of vector\n";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(rand()%100);
    }

    std::cout << "\nv = { ";
    for (int n : v) {
        std::cout << n << ", ";
    }
    std::cout << "}; \n";
    
    int i, j, time_variable;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v.at(j) > v.at(j + 1))
            {
                time_variable = v.at(j + 1);
                v.at(j + 1) = v.at(j);
                v.at(j) = time_variable;
            }
        }
    }

    std::cout << "\nv = { ";
    for (int n : v) {
        std::cout << n << ", ";
    }
    std::cout << "}; \n";
}