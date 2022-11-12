#include <iostream>
#include <string>
#include <vector>


struct student {
public:
    int year_of_birth, year_of_graduation_sch, year_of_entry_inst, year_of_graduation_inst;
    std::string name;
    std::string familia;
    std::string otchectvo;
    void print() {
        std::cout << year_of_birth << " " << year_of_graduation_sch << " " << year_of_entry_inst << " " 
            << year_of_graduation_inst << "\n" << name << " " << familia << " " << otchectvo << "\n";

    }
};

class my_error : public std::exception {
public:
    int lifetime;
    my_error(int l) : lifetime(l) {}

};

std::vector<student> add(std::vector<student>* vect, int Y_Bth, int Y_GrSch, int Y_Entr, int Y_GrInst,
        std::string name, std::string familia, std::string otchectvo) {

    try {
        int counter = 1;
        student Stud;
        if (Y_Bth < Y_GrSch && Y_GrSch <= Y_Entr && Y_Entr < Y_GrInst && counter != 0) {
            Stud.year_of_birth = Y_Bth;
            Stud.year_of_graduation_sch = Y_GrSch;
            Stud.year_of_entry_inst = Y_Entr;
            Stud.year_of_graduation_inst = Y_GrInst;
        }
        else {
            int number_of_errors = (Y_Bth >= Y_GrSch) + (Y_GrSch > Y_Entr) + (Y_Entr >= Y_GrInst);
            throw (int)number_of_errors;

            counter *= 0;
        }

        if (65 <= (int)name[0] && (int)name[0] <= 90 && counter != 0) {
            Stud.name = name;
        }
        else {
            
            throw (std::string)"Error at name " + name;
            counter *= 0;
        }
        if (65 <= (int)familia[0] && (int)familia[0] <= 90 && counter != 0) {
            Stud.familia = familia;
        }
        else {
            throw (std::string)"Error at familia " + familia;
            counter *= 0;
        }
        if (65 <= (int)otchectvo[0] && (int)otchectvo[0] <= 90 && counter != 0) {
            Stud.otchectvo = otchectvo;
        }
        else {
            throw (std::string)"Error at othestvo" + otchectvo;
            counter *= 0;
        }
        if (Y_GrInst - Y_Bth > 100) {
            my_error m_e(Y_GrInst - Y_Bth);
            throw (m_e);
        }

        if (counter != 0) { vect->push_back(Stud); }
    }

    catch (std::string str) { std::cout << str << std::endl; }
    catch (int number_of_errors) { std::cout << "I find " << number_of_errors << " errors in years\n"; }
    catch (my_error m_e) { std::cout << "Nobody can leave " << m_e.lifetime << " years!\n"; }
    return *vect;
}

int main()
{
    std::vector<student>* vect_stud;
    vect_stud =  new std::vector<student>;
    add(vect_stud, 2002, 2004, 2006, 2008, "Andrey", "Mymrin", "Petrovich");
    add(vect_stud, 2, 3, 4, 5, "Andre", "Mym", "Petro");

    for (student i : *vect_stud) {
        i.print();
    }
    
    delete vect_stud;
    return 0;
}

/*
Продемонстрируйте перехват исключений различных типов, генерируемых программой,
а также перехват пользовательского типа исключения, унаследованного от стандартного типа std.

Продемонстрируйте обработку ошибок функции при помощи кодов возврата на примере программы создающей
и добавляющей в вектор структуры данных хранящей данные о человеке : Год рождения, ФИО, год окончания школы,
год поступления в университет, год окончания университета, объект enumerate.
Элементы структуры данных должны создаваться при помощи специальной функции(конструктор писать не нужно),
проверяющей корректность введенных  данных,
функция должна возвращать объект enumerate отвечающий за корректность введенных данных.
Валидные объекты следует добавить в вектор и вывести на экран их список после заполнения вектора.
В случае введения некорректного объекта вывести сообщение об ошибке.


std::exception
*/
