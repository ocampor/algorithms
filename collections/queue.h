//
// Created by Ricardo Ocampo on 10/23/19.
//

#ifndef ALGORITHMS_QUEUE_H
#define ALGORITHMS_QUEUE_H

#import "linked_list.h"

template<typename Item>
class Queue {
public:
    Queue() {
        list = LinkedList<Item>();
    }

    void enqueue(Item item);

    Item dequeue();

    bool isEmpty();

    int size();

    std::string toString();

private:
    LinkedList<Item> list;
};

#import "queue.cpp"

#endif //ALGORITHMS_QUEUE_H
