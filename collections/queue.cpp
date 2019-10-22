//
// Created by Ricardo Ocampo on 10/23/19.
//

#include "queue.h"

template<typename Item>
void Queue<Item>::enqueue(Item item) {
    list.append(item);
}

template<typename Item>
Item Queue<Item>::dequeue() {
    return list.removeFirst();
}

template<typename Item>
bool Queue<Item>::isEmpty() {
    return list.isEmpty();
}

template<typename Item>
int Queue<Item>::size() {
    return list.size();
}

template<typename Item>
std::string Queue<Item>::toString() {
    return list.toString();
}
