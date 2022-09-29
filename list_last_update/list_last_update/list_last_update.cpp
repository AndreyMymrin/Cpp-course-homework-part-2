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
    list() : first(nullptr), chosen_element(nullptr), last(nullptr) {
        std::cout << "I am new list!\n";
    };
    ~list();
};


bool is_list_empty(list& my_list) {

    if (my_list.first == nullptr) {
        return true;
    }
    return false;
}

void pushback(list& cur_list, int data) {
    list_item* p_tmp = new list_item(data);

    if (is_list_empty(cur_list)) {
        cur_list.first = p_tmp;
        cur_list.last = p_tmp;
        cur_list.first->previosly = nullptr;
        cur_list.chosen_element = p_tmp;
        std::cout << "New data in list = " << data << std::endl;
        return;
    }
    p_tmp->previosly = cur_list.last;
    cur_list.last->next = p_tmp;
    cur_list.last = p_tmp;
    std::cout << "New data in list = " << data << std::endl;
};

void print_list(list& cur_list) {
    list_item* p_tmp = cur_list.first;
    std::cout << "Lets print all list!" << std::endl;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << std::endl;
        p_tmp = p_tmp->next;
    }
};

void print_list_inverse(list& cur_list) {
    list_item* p_tmp = cur_list.last;
    std::cout << "Lets print list inversly" << std::endl;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << std::endl;
        p_tmp = p_tmp->previosly;
    }
};

void delete_last(list& cur_list) {
    list_item* p_tmp = cur_list.last;
    p_tmp->previosly->next = nullptr;
    cur_list.last = p_tmp->previosly;
    delete p_tmp;
    std::cout << "I delete last struct" << std::endl;
};

void delete_first(list& cur_list) {
    std::cout << "I delete first struct" << std::endl;
    list_item* p_tmp = cur_list.first;
    p_tmp->next->previosly = nullptr;
    cur_list.first = p_tmp->next;
    delete p_tmp;
};

void delete_all_list(list& cur_list) {
    std::cout << "I delete all list!" << std::endl;
    list_item* p_tmp = cur_list.last;
    while (p_tmp->previosly != nullptr) {
        p_tmp = p_tmp->previosly;
        delete(p_tmp->next);
        p_tmp->next = nullptr;
    }
    delete (p_tmp);
    cur_list.first = nullptr;
    cur_list.last = nullptr;
};

void move_forvard(list& cur_list) {
    if (cur_list.chosen_element->next != nullptr) {
        cur_list.chosen_element = cur_list.chosen_element->next;
    }
};

void move_backvard(list& cur_list) {
    if (cur_list.chosen_element->previosly != nullptr) {
        cur_list.chosen_element = cur_list.chosen_element->previosly;
    }
};

void print_chosen_element(list& cur_list) {
    std::cout << "I print chosen element" << std::endl;
    std::cout << (cur_list.chosen_element->data) << std::endl;
};

void print_list_with_move_f(list& cur_list) {
    cur_list.chosen_element = cur_list.first;
    std::cout << "Lets print list using moving forvard" << std::endl;
    while (cur_list.chosen_element->next != nullptr) {
        print_chosen_element(cur_list);
        move_forvard(cur_list);
    }
    print_chosen_element(cur_list);
};

void delete_chosen_element(list& cur_list) {
    std::cout << "I delete chosen element" << std::endl;
    if (cur_list.chosen_element == cur_list.first) {
        delete_first(cur_list);
    }
    else if (cur_list.chosen_element == cur_list.last) {
        delete_last(cur_list);
    }
    else {
        list_item* p_tmp = cur_list.chosen_element->previosly;
        cur_list.chosen_element->previosly->next = cur_list.chosen_element->next;
        cur_list.chosen_element = cur_list.chosen_element->next;
        delete cur_list.chosen_element->previosly;
        cur_list.chosen_element->previosly = p_tmp;
    }
}

void add_ahead_chosen_element(list& cur_list, int data) {
    list_item* p_tmp = new list_item(data);
    p_tmp->previosly = cur_list.chosen_element;
    std::cout << "I add new data ahead chosen element = " <<data << std::endl;
    if (cur_list.chosen_element->next != nullptr) {

        p_tmp->next = cur_list.chosen_element->next;
        cur_list.chosen_element->next = p_tmp;
        p_tmp->next->previosly = p_tmp;
    }
    else {
        p_tmp->next = nullptr;
        cur_list.chosen_element->next = p_tmp;
    }
}

void splitting_into_two(list& cur_list, list& copy_list) {
    if (cur_list.chosen_element == cur_list.last || cur_list.chosen_element == cur_list.first || cur_list.chosen_element == nullptr) {
        std::cout << "The pointer points to the last/first element\nI can't do anything\n";
    }
    else {
        std::cout << "Lets split our list into two" << std::endl;
        list_item* p_tmp = cur_list.chosen_element;
        copy_list.chosen_element = cur_list.chosen_element->next;
        copy_list.chosen_element->previosly = nullptr;
        copy_list.first = copy_list.chosen_element;
        move_forvard(cur_list);

        while (cur_list.chosen_element->next != nullptr) {
            copy_list.chosen_element->data = cur_list.chosen_element->data;
            move_forvard(cur_list);
            copy_list.chosen_element = cur_list.chosen_element;
        }
        add_ahead_chosen_element(copy_list, cur_list.chosen_element->data);
        copy_list.last = copy_list.chosen_element;
        copy_list.last->next = nullptr;
        cur_list.chosen_element = p_tmp;
        cur_list.chosen_element->next = nullptr;
    }
}

void comb_lists_ahead_chosen_element(list& first_list, list& second_list) {
    if ((is_list_empty(first_list)) || (is_list_empty(second_list))) {
        std::cout << "One or more list is empty";
        return;
    }
    else {
        std::cout << "Lets combine two lists" << std::endl;
        second_list.chosen_element = second_list.first;
        while (second_list.chosen_element->next != nullptr) {
            add_ahead_chosen_element(first_list, second_list.chosen_element->data);
            move_forvard(second_list);
            move_forvard(first_list);
        }
        add_ahead_chosen_element(first_list, second_list.chosen_element->data);
    }
}

void combining_two_lists(list& first_list, list& second_list) {
    first_list.chosen_element = first_list.last;
    comb_lists_ahead_chosen_element(first_list, second_list);
    first_list.last = second_list.last;
}

list::~list() {
    std::cout << "You shall not pass!!!\tI am deconstructor!\n";
    if (!(is_list_empty(*this))) {
        delete_all_list(*this);
    }
}

int main()
{
    list l_copy;
    list l;
    std::cout << "Empty list" << std::endl;
    print_list(l);
    std::cout << "Is this list really empty? " << is_list_empty(l) << std::endl;
    std::cout << "Lets add smth" << std::endl;
    pushback(l, 11);
    pushback(l, 22);
    pushback(l, 33);
    pushback(l, 44);
    pushback(l, 55);
    pushback(l, 66);
    print_list(l);
    std::cout << "Is this list really empty now? " << is_list_empty(l) << std::endl;
    
    delete_last(l);
    print_list(l);

    print_chosen_element(l);
    std::cout << "Move chosen element forward twise and backward once" << std::endl;
    move_forvard(l);
    move_forvard(l);
    print_chosen_element(l);
    move_backvard(l);
    print_chosen_element(l);
    add_ahead_chosen_element(l, 123);
    print_list_with_move_f(l);
    delete_chosen_element(l);
    print_list_inverse(l);

    pushback(l_copy, 111);
    pushback(l_copy, 222);
    pushback(l_copy, 333);
    pushback(l_copy, 444);

    combining_two_lists(l, l_copy);
    print_list(l);

    move_backvard(l);
    move_backvard(l);
    move_backvard(l);
    move_backvard(l);

    print_chosen_element(l);

    splitting_into_two(l, l_copy);
    std::cout << "First part:\n";
    print_list(l);
    std::cout << "Second part:\n";
    print_list(l_copy);

    move_backvard(l);
    move_backvard(l);
    move_backvard(l);
    move_backvard(l);
    print_chosen_element(l);

    comb_lists_ahead_chosen_element(l, l_copy);
    print_list(l);

    return 0;
}    
/*
    pushback(l, 11);
    add_ahead_chosen_element(l, 666);
    move_forvard(l);
    move_backvard(l);

    delete_chosen_element(l);
    delete_all_list(l);
    delete_last(l);
    delete_first(l);

    print_chosen_element(l);
    print_list_with_move_f(l);
    print_list(l);
    print_list_inverse(l);

    splitting_into_two(l, l_copy);
    combining_two_lists(l, l_copy);
    comb_lists_ahead_chosen_element(l, l_copy);
 */