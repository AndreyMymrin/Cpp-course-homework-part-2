#pragma once
template <class T, int first_dimention, int ... size>
class matrix {
public:
    matrix<T, size...> Matr[first_dimention];
    /*template<int ... other>
    T take(int first, int ... other) {
        return Matr[first].take(other...);
    }*/

    matrix<T, first_dimention, size...> operator + (matrix<T, first_dimention, size...> Matr2) {
        for (int i = 0; i < first_dimention; i++) {
            Matr[i] + Matr2.Matr[i];
        }
        return *this;
    }
    matrix<T, first_dimention, size...> operator - (matrix<T, first_dimention, size...> Matr2) {
        for (int i = 0; i < first_dimention; i++) {
            Matr[i] - Matr2.Matr[i];
        }
        return *this;
    }

};

template<class T, int wide, int size>
class matrix<T,wide,size> {
public:
    T Matr[wide][size];
    /*T take(int first, int size) {
        return Matr[size][first];
    }*/
    matrix<T,wide, size> operator + (matrix<T, wide, size >Matr2) {
        for (int i = 0; i < wide; i++) {
            for (int j = 0; j < size; j++) {
                Matr[i][j] += Matr2.Matr[i][j];
            }
        }
        return *this;
    }
    matrix<T, wide, size> operator - (matrix<T, wide, size >Matr2) {
        for (int i = 0; i < wide; i++) {
            for (int j = 0; j < size; j++) {
                Matr[i][j] -= Matr2.Matr[i][j];
            }
        }
        return *this;
    }
};
template<class T,int size>
class matrix<T, size> {
public:
    T Matr[size];
    /*T take(int first, int size) {
        return Matr[size][first];
    }*/
    matrix<T,size> operator + (matrix<T, size >Matr2) {
        for (int j = 0; j < size; j++) {
            Matr[j] += Matr2.Matr[j];
        }
        return *this;
    }
    matrix<T,size> operator - (matrix<T, size >Matr2) {
        for (int j = 0; j < size; j++) {
            Matr[j] -= Matr2.Matr[j];
        }
        
        return *this;
    }
};

template <class T, int first_dimention, int ... size>
void rand_add(matrix<T,first_dimention, size... >& MomMatr) {
    for (int i = 0; i < first_dimention; i++) {
        rand_add(MomMatr.Matr[i]);
    }
}
template<class T, int wide, int size>
void rand_add(matrix<T, wide, size>& MomMatr) {

    for (int i = 0; i < wide; i++) {
        for (int j = 0; j < size; j++) {
            MomMatr.Matr[i][j] = rand() % 100;
        }
    }
}

template<class T, int size>
void rand_add(matrix<T, size>& MomMatr) {
    for (int j = 0; j < size; j++) {
        MomMatr.Matr[j] = rand() % 100;
    }
}

template <class T, int first_dimention, int ... size>
void print(matrix<T, first_dimention, size... >& MomMatr) {
    std::cout << "\tMatrix:\n";
    for (int i = 0; i < first_dimention; i++) {
        print(MomMatr.Matr[i]);
        std::cout << "\n";
    }
}

template<class T, int wide, int size>
void print(matrix<T, wide, size>& MomMatr) {
    for (int i = 0; i < size; i++) {
        std::cout << "|";
        for (int j = 0; j < wide; j++) {
            std::cout.width(3);
            std::cout << MomMatr.Matr[j][i] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

template<class T,int size>
void print(matrix<T,size>& MomMatr) {
    std::cout << "|";
    for (int j = 0; j < size; j++) {
        std::cout.width(3);
        std::cout << MomMatr.Matr[j] << " ";
    }
    std::cout << "|\n";
    std::cout << "\n";
}