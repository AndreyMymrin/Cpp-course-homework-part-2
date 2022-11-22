#include <iostream>
template <class T>
struct list_item {
    T data;
    list_item<T>* previosly;
    list_item<T>* next;
    list_item(T _data) : data(_data), previosly(nullptr), next(nullptr) {};
};
template <class T>
struct list {

    list_item<T>* first;
    list_item<T>* chosen_element;
    list_item<T>* last;
    list() : first(nullptr), chosen_element(nullptr), last(nullptr) {
        std::cout << "I am new list!\n";
    };
    ~list();
};

template <class T>
bool is_list_empty(list<T>& my_list) {

    if (my_list.first == nullptr) {
        return true;
    }
    return false;
}

template <class T>
void pushback(list<T>& cur_list, T data) {
    list_item<T>* p_tmp = new list_item<T>(data);

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
template <class T>
void print_list(list<T>& cur_list) {
    list_item<T>* p_tmp = cur_list.first;
    std::cout << "Lets print all list!" << std::endl;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << std::endl;
        p_tmp = p_tmp->next;
    }
};
template <class T>
void print_list_inverse(list<T>& cur_list) {
    list_item<T>* p_tmp = cur_list.last;
    std::cout << "Lets print list inversly" << std::endl;
    while (p_tmp != nullptr) {
        std::cout << p_tmp->data << std::endl;
        p_tmp = p_tmp->previosly;
    }
};
template <class T>
void delete_last(list<T>& cur_list) {
    std::cout << "I delete last struct" << std::endl;
    if (cur_list.last == cur_list.chosen_element) cur_list.chosen_element = cur_list.last->previosly;
    list_item<T>* p_tmp = cur_list.last;
    p_tmp->previosly->next = nullptr;
    cur_list.last = p_tmp->previosly;
    delete p_tmp;
};
template <class T>
void delete_first(list<T>& cur_list) {
    std::cout << "I delete first struct" << std::endl;
    if (cur_list.first == cur_list.chosen_element) cur_list.chosen_element = cur_list.first->next;
    list_item<T>* p_tmp = cur_list.first;
    p_tmp->next->previosly = nullptr;
    cur_list.first = p_tmp->next;
    delete p_tmp;
};
template <class T>
void delete_all_list(list<T>& cur_list) {
    std::cout << "I delete all list!" << std::endl;
    list_item<T>* p_tmp = cur_list.last;
    while (p_tmp->previosly != nullptr) {
        p_tmp = p_tmp->previosly;
        delete(p_tmp->next);
        p_tmp->next = nullptr;
    }
    delete (p_tmp);
    cur_list.first = nullptr;
    cur_list.last = nullptr;
};
template <class T>
void move_forvard(list<T>& cur_list) {
    if (cur_list.chosen_element->next != nullptr) {
        cur_list.chosen_element = cur_list.chosen_element->next;
    }
};
template <class T>
void move_backvard(list<T>& cur_list) {
    if (cur_list.chosen_element->previosly != nullptr) {
        cur_list.chosen_element = cur_list.chosen_element->previosly;
    }
};
template <class T>
void print_chosen_element(list<T>& cur_list) {
    std::cout << "I print chosen element" << std::endl;
    std::cout << (cur_list.chosen_element->data) << std::endl;
};
template <class T>
void print_list_with_move_f(list<T>& cur_list) {
    cur_list.chosen_element = cur_list.first;
    std::cout << "Lets print list using moving forvard" << std::endl;
    while (cur_list.chosen_element->next != nullptr) {
        print_chosen_element(cur_list);
        move_forvard(cur_list);
    }
    print_chosen_element(cur_list);
};
template <class T>
void delete_chosen_element(list<T>& cur_list) {
    std::cout << "I delete chosen element" << std::endl;
    if (cur_list.chosen_element == cur_list.first) {
        delete_first(cur_list);
    }
    else if (cur_list.chosen_element == cur_list.last) {
        delete_last(cur_list);
    }
    else {
        list_item<T>* p_tmp = cur_list.chosen_element->previosly;
        cur_list.chosen_element->previosly->next = cur_list.chosen_element->next;
        cur_list.chosen_element = cur_list.chosen_element->next;
        delete cur_list.chosen_element->previosly;
        cur_list.chosen_element->previosly = p_tmp;
    }
}
template <class T>
void add_ahead_chosen_element(list<T>& cur_list, T data) {
    list_item<T>* p_tmp = new list_item<T>(data);
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
template <class T>
void splitting_into_two(list<T>& cur_list, list<T>& copy_list) {
    if (cur_list.chosen_element == cur_list.last || cur_list.chosen_element == cur_list.first || cur_list.chosen_element == nullptr) {
        std::cout << "The pointer points to the last/first element\nI can't do anything\n";
    }
    else {
        std::cout << "Lets split our list into two" << std::endl;
        list_item<T>* p_tmp = cur_list.chosen_element;
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
template <class T>
void comb_lists_ahead_chosen_element(list<T>& first_list, list<T>& second_list) {
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
template <class T>
void combining_two_lists(list<T>& first_list, list<T>& second_list) {
    first_list.chosen_element = first_list.last;
    comb_lists_ahead_chosen_element(first_list, second_list);
    first_list.last = second_list.last;
}
template <class T>
list<T>::~list<T>() {
    std::cout << "You shall not pass!!!\tI am deconstructor!\n";
    if (!(is_list_empty(*this))) {
        delete_all_list(*this);
    }
}

int main()
{
    list<std::string> l_copy;
    list<std::string> l;
    std::cout << "Empty list" << std::endl;
    print_list(l);
    std::cout << "Is this list really empty? " << is_list_empty(l) << std::endl;
    std::cout << "Lets add smth" << std::endl;
    pushback(l, (std::string)"aaaa");
    pushback(l, (std::string)"22.2");
    pushback(l, (std::string)"33.5");
    pushback(l, (std::string)"44.6");
    pushback(l, (std::string)"55.1");
    pushback(l, (std::string)"66.a");
    print_list(l);
    std::cout << "Is this list really empty now? " << is_list_empty(l) << std::endl;
    
    delete_last(l);
    delete_first(l);
    //print_list(l);
    
    print_chosen_element(l);
    std::cout << "Move chosen element forward twise and backward once" << std::endl;
    move_forvard(l);
    move_forvard(l);
    move_backvard(l);
    print_chosen_element(l);


    add_ahead_chosen_element(l, (std::string)"a123");
    print_list(l);

    print_list_with_move_f(l);
    delete_chosen_element(l);
    print_list_inverse(l);
    
    pushback(l_copy, (std::string)"111");
    pushback(l_copy, (std::string)"222");
    pushback(l_copy, (std::string)"333");
    pushback(l_copy, (std::string)"444");

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

    delete_all_list(l);
    

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