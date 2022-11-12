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
            throw (std::string)"years error";
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
        if (counter != 0) { vect->push_back(Stud); }
    }
    catch (std::string str) { std::cout << str << std::endl; }
    return *vect;
}

int main()
{
    std::vector<student>* vect_stud;
    vect_stud =  new std::vector<student>;
    add(vect_stud, 2002, 2004, 2006, 4003, "Andrey", "Mymrin", "Petrovich");
    add(vect_stud, 2, 3, 4, 5, "andre", "Mym", "Petro");

    for (student i : *vect_stud) {
        i.print();
    }

    return 0;
}



/*
Продемонстрируйте обработку ошибок функции при помощи кодов возврата на примере программы создающей
и добавляющей в вектор структуры данных хранящей данные о человеке : Год рождения, ФИО, год окончания школы,
год поступления в университет, год окончания университета, объект enumerate.
Элементы структуры данных должны создаваться при помощи специальной функции(конструктор писать не нужно),
проверяющей корректность введенных  данных,
функция должна возвращать объект enumerate отвечающий за корректность введенных данных.
Валидные объекты следует добавить в вектор и вывести на экран их список после заполнения вектора.
В случае введения некорректного объекта вывести сообщение об ошибке.
*/