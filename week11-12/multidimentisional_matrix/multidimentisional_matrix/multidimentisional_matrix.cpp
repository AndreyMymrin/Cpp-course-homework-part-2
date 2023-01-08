#include <iostream>
#include "Header.h"


int main()
{
    matrix<int,2,3,2,3> Mat, Mat2;
    rand_add(Mat);
    print(Mat);
    rand_add(Mat2);
    print(Mat2);
    Mat + Mat2;
    print(Mat);
}
