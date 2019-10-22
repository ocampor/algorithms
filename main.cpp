#include <iostream>
#include "collections/linked_list.h"

int main() {
    collections::LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.removeLast();

    std::cout << list.toString() << "size:" << list.size() << std::endl;
    return 0;
}
