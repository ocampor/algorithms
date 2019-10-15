//
// Created by Ricardo Ocampo on 10/15/19.
//

#include "linked_list.h"
#include <iostream>

using namespace collections;

template<typename Item>
bool LinkedList<Item>::isEmpty() {
    return first == nullptr;
}

template<typename Item>
int LinkedList<Item>::size() {
    return N;
}

template<typename Item>
void LinkedList<Item>::append(Item item) {
    Node *n = new Node();
    n->item = item;

    if (isEmpty()) {
        first = n;
        last = n;
    } else {
        last->next = n;
        n->previous = last;
        last = n;
    }

    N++;
}

template<typename Item>
Item LinkedList<Item>::pop() {
    Node *tmp = last;
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return NULL;
    } else if (N == 1) {
        first = nullptr;
        last = nullptr;
    } else {
        last->previous->next = nullptr;
        last = last->previous;
    }

    N--;
    return tmp->item;
}

template<typename Item>
std::string LinkedList<Item>::toString() {
    std::string concat{};
    for (Node *current = first; current != NULL; current = current->next) {
        concat += std::to_string(current->item) + ",";
    }

    return concat;
}
