//
// Created by Ricardo Ocampo on 10/22/19.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#import "linked_list.h"

template<typename Item>
class Stack {
public:
    Stack() {
        list = LinkedList<Item>();
    }

    void push(Item item);

    Item pop();

    Item peek();

    bool isEmpty();

    int size();

    std::string toString();

private:
    LinkedList<Item> list;
};

#import "stack.cpp"

#endif //ALGORITHMS_STACK_H
