//
// Created by Ricardo Ocampo on 11/6/19.
//

#include "arithmetic.h"
#include "../collections/stack.h"
#include <iostream>
#include <set>

using namespace std;
using namespace collections;

int parseInt(char c) {
    return static_cast<int>(c) - '0';
}

float operation(char op, float a, float b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            cout << "The division is" << a / b << endl;
            return a / b;
    }
}

float evaluate(const std::string &expression) {
    Stack<float> literals{};
    Stack<char> operators{};

    for (char c: expression) {
        if (isdigit(c)) {
            literals.push(parseInt(c));
            if (!operators.isEmpty() && (operators.peek() == '/' || operators.peek() == '*')) {
                float b{literals.pop()};
                float a{literals.pop()};
                literals.push(operation(operators.pop(), a, b));
            }
        } else if (c == '*' || c == '/' || c == '+' || c == '-') {
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {
        char op{operators.pop()};
        float b{literals.pop()};
        float a{literals.pop()};
        literals.push(operation(op, a, b));
    }

    return literals.pop();
}
