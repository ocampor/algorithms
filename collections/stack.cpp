//
// Created by Ricardo Ocampo on 10/22/19.
//

#include "stack.h"

template<typename Item>
void Stack<Item>::push(Item item) {
    list.append(item);
}

template<typename Item>
Item Stack<Item>::pop() {
    return list.pop();
}

template<typename Item>
bool Stack<Item>::isEmpty() {
    return list.isEmpty();
}

template<typename Item>
int Stack<Item>::size() {
    return list.size();
}

template<typename Item>
std::string Stack<Item>::toString() {
    return list.toString();
}
