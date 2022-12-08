#include <iostream>

template <int wide, int hight, class T>
class matrix {
public:
    T Matr[wide][hight];

    matrix<wide, hight, T> operator * (int coefficient) {
        for (int i = 0; i < wide; i++) {
            for (int j = 0; j < hight; j++) {
                Matr[i][j] *= coefficient;
            }
        }
        return *this;
    }
    matrix<wide, hight, T> operator + (matrix<wide, hight, T> M2) {
        for (int i = 0; i < wide; i++) {
            for (int j = 0; j < hight; j++) {
                Matr[i][j] += M2.Matr[i][j];
            }
        }
        return *this;
    }
    matrix<wide, hight, T> operator - (matrix<wide, hight, T> M2) {
        for (int i = 0; i < wide; i++) {
            for (int j = 0; j < hight; j++) {
                Matr[i][j] -= M2.Matr[i][j];
            }
        }
        return *this;
    }
    
};

template <int wide, int hight, class T>
void rand_add(matrix<wide, hight, T>& a) {

    for (int i = 0; i < wide; i++) {
        for (int j = 0; j < hight; j++) {
            a.Matr[i][j] = rand()%100;
        }
    }
}

template <int wide, int hight, class T>
void print(matrix<wide, hight, T>& a) {

    for (int i = 0; i < hight; i++) {
        std::cout << "|";
        for (int j = 0; j < wide; j++) {
            std::cout.width(3);
            std::cout << a.Matr[i][j] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

template <int wide, int hight, class T>
T take(int i, int j, matrix<wide, hight, T>& a) {
    return a.Matr[j][i];
}

int main()
{
    matrix<6, 5, double> Mat;
    matrix<6, 5, double> Mat2;
    rand_add(Mat);
    print(Mat);
    rand_add(Mat2);
    print(Mat2);

    Mat + Mat2;
    print(Mat);

    std::cout << take(3, 4, Mat) << "\n";
}