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
    try{
        
        if (Y_Bth < Y_GrSch && Y_GrSch <= Y_Entr && Y_Entr < Y_GrInst) {
            student Stud;

            Stud.year_of_birth = Y_Bth;
            Stud.year_of_graduation_sch = Y_GrSch;
            Stud.year_of_entry_inst = Y_Entr;
            Stud.year_of_graduation_inst = Y_GrInst;
            Stud.name = name;
            Stud.familia = familia;
            Stud.otchectvo = otchectvo;

            vect->push_back(Stud);
        }
        else {
            throw "error";
        }
    }
    
    catch (...) { std::cout << "error\n"; }
    return *vect;
}

int main()
{
    std::vector<student>* vect_stud;
    vect_stud =  new std::vector<student>;
    add(vect_stud, 2002, 2004, 2006, 4003, "Andrey", "Mymrin", "Penrovich");
    add(vect_stud, 2, 3, 4, 5, "Andre", "Mym", "Penro");

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