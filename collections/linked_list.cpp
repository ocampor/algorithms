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
Item LinkedList<Item>::removeLast() {
    Node *tmp = last;
    if (isEmpty()) {
        throw std::out_of_range("The list is empty.");
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

//TODO: Refactor this and removeLast to share the same code
template<typename Item>
Item LinkedList<Item>::removeFirst() {
    Node *tmp = first;
    if (isEmpty()) {
        throw std::out_of_range("The list is empty.");
    } else if (N == 1) {
        first = nullptr;
        last = nullptr;
    } else {
        first = tmp->next;
    }

    N--;
    return tmp->item;
}

template<typename Item>
std::string LinkedList<Item>::toString() {
    std::string concat{};
    for (Node *current = first; current != nullptr; current = current->next) {
        concat += std::to_string(current->item) + ",";
    }

    return concat;
}
