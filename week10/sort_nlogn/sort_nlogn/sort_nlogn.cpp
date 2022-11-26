#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
template<class Type>
bool compare_bolshe(Type left_item, Type right_item) {
    if (left_item > right_item) return 1;
    else return 0;
    //(left_item.size() > right_item.size())
    // 
    // (abs(left_item) > abs(right_item))
}

template<class Type>
void sort_qsort(Type* items, int left, int right, bool(*compare)(Type, Type) = compare)
{
    int i, j;
    Type x, y;
    i = left;
    j = right;
    x = items[(left + right) / 2];
    do
    {
        while (compare(x, items[i]) && (i < right)) { i++; }
        while (compare(items[j], x) && (j > left)) { j--; }

        if (i <= j)
        {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) sort_qsort<Type>(items, left, j, compare);
    if (i < right) sort_qsort<Type>(items, i, right, compare);
}




template <class Type, int N>
void qsort(Type(&arr)[N]) {
    sort_qsort<Type>(arr, 0, N-1, &compare_bolshe);
}

template<class Type>
void print(Type* items, int n) {
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    srand(time(NULL));

    const int n = 10;
    std::string a[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = std::string(rand() % 9 +1, 'A');
        //a[i] = pow(-1,rand())*(rand() % 100);
    }
    print(&a[0], n);

    qsort<std::string>(a);

    print(&a[0], n);

    return(0);
}
