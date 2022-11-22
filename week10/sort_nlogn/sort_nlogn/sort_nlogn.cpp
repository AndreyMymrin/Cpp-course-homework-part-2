#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
template<class Type>
void sort_qsort(Type* items, int left, int right);

template<class Type>
void print(Type* items, int n) {
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

template<class Type>
bool compare_bolshe(Type left_item, Type right_item) {
	if (left_item.size() > right_item.size()) return 1;
	else return 0;

	// (left_item > right_item)
	// (abs(left_item) > abs(right_item))
}

int main()
{
    srand(time(NULL));

    const int n = 5;
    std::string a[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = std::string(rand() % 9 +1, 'A');
        //a[i] = pow(-1,rand())*(rand() % 100);
    }
    print(&a[0], n);

    sort_qsort<std::string>(&a[0], 0, n - 1);

    print(&a[0], n);

    return(0);
}


template<class Type>
void sort_qsort(Type* items, int left, int right)
{
    int i, j;
    Type x, y;
    i = left;
    j = right;
    x = items[(left + right) / 2];
    do
    {
        while (compare_bolshe<Type>(x, items[i]) && (i < right)) { i++; }
        while (compare_bolshe<Type>(items[j], x) && (j > left)) { j--; }

        if (i <= j)
        {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
        }

    } while (i <= j);


    if (left < j) sort_qsort<Type>(items, left, j);
    if (i < right) sort_qsort<Type>(items, i, right);
}