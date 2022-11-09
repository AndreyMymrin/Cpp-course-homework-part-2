#include <iostream>
#include <string>
#include <vector>


struct student {
public:
    int year_of_birth, year_of_graduation_sch, year_of_entry_inst, year_of_graduation_inst;
    std::string name;
    std::string familia;
    std::string otchectvo;

    std::vector<std::string> errors_vect;
    
};
std::string create(int Y_Bth, int Y_GrSch, int Y_Entr, int Y_GrInst,
        std::string name, std::string familia, std::string otchectvo) {
    try{
        student Stud;
        if (Y_Bth < Y_GrSch && Y_GrSch <= Y_Entr && Y_Entr < Y_GrInst) {
            Stud.year_of_birth = Y_Bth;
            Stud.year_of_graduation_sch = Y_GrSch;
            Stud.year_of_entry_inst = Y_Entr;
            Stud.year_of_entry_inst = Y_GrInst;
            Stud.name = name;
            Stud.familia = familia;
            Stud.otchectvo = otchectvo;
        }
        else {
            throw "error";
        }
    }
    
    catch (...) { std::cout << "er\n"; }
    return "Hmmmmm";
}

int main()
{
    create(2002, 2004, 2006, 4003, "Andrey", "Mymrin", "Penrovich");

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