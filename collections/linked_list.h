//
// Created by Ricardo Ocampo on 10/15/19.
//

#ifndef ALGORITHMS_LINKED_LIST_H
#define ALGORITHMS_LINKED_LIST_H

#include <iostream>

namespace collections {
    template<typename Item>
    struct LinkedList {
        struct Node {
            Node *next;
            Node *previous;
            Item item;
        };

        bool isEmpty();

        int size();

        void append(Item item);

        Item pop();

        std::string toString();

    private:
        Node *first;
        Node *last;
        int N{0};
    };
}

#import "linked_list.cpp"

#endif //ALGORITHMS_LINKED_LIST_H
