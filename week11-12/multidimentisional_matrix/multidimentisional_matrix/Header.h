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


template<class T, int size>
void rand_add(matrix<T, size>& MomMatr) {
    for (int j = 0; j < size; j++) {
        MomMatr.Matr[j] = rand() % 100;
    }
}

template <class T, int first_dimention, int ... size>
void print(matrix<T, first_dimention, size... >& MomMatr) {
    std::cout << "\t\n";
    for (int i = 0; i < first_dimention; i++) {
        print(MomMatr.Matr[i]);
    }
}

template<class T,int size>
void print(matrix<T,size>& MomMatr) {
    std::cout << "|";
    for (int j = 0; j < size; j++) {
        std::cout.width(3);
        std::cout << MomMatr.Matr[j] << " ";
    }
    std::cout << "|\n";
}