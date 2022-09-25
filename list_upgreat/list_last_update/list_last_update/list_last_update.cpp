#include <iostream>

struct list_item {
    int data;
    list_item* previosly;
    list_item* next;
    list_item(int _data) : data(_data), previosly(nullptr), next(nullptr) {};
};

struct list {
    list_item* first;
    list_item* chosen_element;
    list_item* last;
    list() : first(nullptr), chosen_element(nullptr), last(nullptr) {};
};


bool is_list_empty(list* my_list) {
    if (my_list->first == nullptr) {
        return true;
    }
    return false;
}

void pushback(list* cur_list, int data) {
    list_item* p_tmp = new list_item(data);
    if (is_list_empty(cur_list)) {
        cur_list->first = p_tmp;
        cur_list->last = p_tmp;
        cur_list->first->previosly = nullptr;
        cur_list->chosen_element = p_tmp;
        return;
    }
    p_tmp->previosly = cur_list->last;
    cur_list->last->next = p_tmp;
    cur_list->last = p_tmp;
};

void print_list(list* cur_list) {
    list_item* p_tmp = cur_list->first;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << std::endl;
        p_tmp = p_tmp->next;
    }
};

void print_list_inverse(list* cur_list) {
    list_item* p_tmp = cur_list->last;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << std::endl;
        p_tmp = p_tmp->previosly;
    }
};

void delete_last(list* cur_list) {
    list_item* p_tmp = cur_list->last;
    p_tmp->previosly->next = nullptr;
    cur_list->last = p_tmp->previosly;
    delete p_tmp;
};

void delete_first(list* cur_list) {
    list_item* p_tmp = cur_list->first;
    p_tmp->next->previosly = nullptr;
    cur_list->first = p_tmp->next;
    delete p_tmp;
};

void delete_all_list(list* cur_list) {
    list_item* p_tmp = cur_list->last;
    while (p_tmp->previosly != nullptr) {
        p_tmp = p_tmp->previosly;
        delete(p_tmp->next);
        p_tmp->next = nullptr;
    }
    delete (p_tmp);
    cur_list->first = nullptr;
    cur_list->last = nullptr;
};

void move_forvard(list* cur_list) {
    if (cur_list->chosen_element->next != nullptr) {
        cur_list->chosen_element = cur_list->chosen_element->next;
    }
};

void move_backvard(list* cur_list) {
    if (cur_list->chosen_element->previosly != nullptr) {
        cur_list->chosen_element = cur_list->chosen_element->previosly;
    }
};

void print_chosen_element(list* cur_list) {
    std::cout << (cur_list->chosen_element->data) << std::endl;
};

void print_list_with_move_f(list* cur_list) {
    cur_list->chosen_element = cur_list->first;
    while (cur_list->chosen_element->next != nullptr) {
        print_chosen_element(cur_list);
        move_forvard(cur_list);
    }
    print_chosen_element(cur_list);
};

void delete_chosen_element(list* cur_list) {
    if (cur_list->chosen_element == cur_list->first) {
        delete_first(cur_list);
    }
    else if (cur_list->chosen_element == cur_list->last) {
        delete_last(cur_list);
    }
    else {
        list_item* p_tmp = cur_list->chosen_element->previosly;
        cur_list->chosen_element->previosly->next = cur_list->chosen_element->next;
        cur_list->chosen_element = cur_list->chosen_element->next;
        delete cur_list->chosen_element->previosly;
        cur_list->chosen_element->previosly = p_tmp;
    }
}

void add_ahead_chosen_element(list* cur_list, int data) {
    list_item* p_tmp = new list_item(data);
    p_tmp->previosly = cur_list->chosen_element;
    if (cur_list->chosen_element->next != nullptr) {

        p_tmp->next = cur_list->chosen_element->next;
        cur_list->chosen_element->next = p_tmp;
        p_tmp->next->previosly = p_tmp;
    }
    else {
        p_tmp->next = nullptr;
        cur_list->chosen_element->next = p_tmp;
    }
}

int main()
{
    list l;

    pushback(&l, 11);
    pushback(&l, 22);
    pushback(&l, 33);
    pushback(&l, 44);
    pushback(&l, 55);
    pushback(&l, 66);
    pushback(&l, 77);
    pushback(&l, 88);

    print_list(&l);
    std::cout << "-------\n";



    /*
    pushback(&l, 11);
    add_ahead_chosen_element(&l, 666);

    move_forvard(&l);
    move_backvard(&l);

    delete_chosen_element(&l);
    delete_all_list(&l);
    delete_last(&l);
    delete_first(&l);

    print_chosen_element(&l);
    print_list_with_move_f(&l);
    print_list(&l);
    print_list_inverse(&l);
    */
    return 0;
}