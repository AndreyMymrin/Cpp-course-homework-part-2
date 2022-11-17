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
            << year_of_graduation_inst << "\n" << name << " " << familia << " " << otchectvo << "\n\n";

    }
};


class EnumerateOfErrors {
public:
    int number_err_years = 0;
    bool Error_at_name = 0;
    bool Error_at_familia = 0;
    bool Error_at_othestvo = 0;
    void print_all_errors() {
        if (number_err_years) { std::cout << "I find " << number_err_years << " errors in years\n"; }
        //else { std::cout << "No errors at years\n"; };

        if (Error_at_name != 0) { std::cout << "Error at name\n"; }
        //else { std::cout << "No errors at name\n"; };

        if (Error_at_familia != 0) { std::cout << "Error at familia\n"; }
        //else { std::cout << "No errors at familia\n"; };

        if (Error_at_othestvo != 0) { std::cout << "Error at othestvo\n"; }
        //else { std::cout << "No errors at othestvo\n"; };
        std::cout << std::endl;
    }
};

EnumerateOfErrors add(std::vector<student>* vect, int Y_Bth, int Y_GrSch, int Y_Entr, int Y_GrInst,
    std::string name, std::string familia, std::string otchectvo) {

    EnumerateOfErrors stud_errors;
    student Stud;
    if (Y_Bth < Y_GrSch && Y_GrSch <= Y_Entr && Y_Entr < Y_GrInst) {
        Stud.year_of_birth = Y_Bth;
        Stud.year_of_graduation_sch = Y_GrSch;
        Stud.year_of_entry_inst = Y_Entr;
        Stud.year_of_graduation_inst = Y_GrInst;
    }
    else {
        stud_errors.number_err_years = (Y_Bth >= Y_GrSch) + (Y_GrSch > Y_Entr) + (Y_Entr >= Y_GrInst);
    }

    if (65 <= (int)name[0] && (int)name[0] <= 90) {
        Stud.name = name;
    }
    else {
        stud_errors.Error_at_name = 1;
    }
    if (65 <= (int)familia[0] && (int)familia[0] <= 90) {
        Stud.familia = familia;
    }
    else {
        stud_errors.Error_at_familia = 1;
    }
    if (65 <= (int)otchectvo[0] && (int)otchectvo[0] <= 90) {
        Stud.otchectvo = otchectvo;
    }
    else {
        stud_errors.Error_at_othestvo = 1;
    }

    if (stud_errors.number_err_years + stud_errors.Error_at_name +
        stud_errors.Error_at_familia + stud_errors.Error_at_othestvo == 0) {
        vect->push_back(Stud);
    }

    stud_errors.print_all_errors();

    return stud_errors;
}

int main()
{
    std::vector<student>* vect_stud;
    vect_stud = new std::vector<student>;

    EnumerateOfErrors error1 =  add(vect_stud, 2005, 2004, 2006, 2008, "Andrey", "Mymrin", "Petrovich");

    add(vect_stud, 2, 3, 4, 5, "Andre", "Mym", "Petro");

    for (student i : *vect_stud) {
        i.print();
    }
    
    //error1.print_all_errors();

    delete vect_stud;
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