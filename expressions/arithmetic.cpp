//
// Algorithms, Fourth Edition
// 1.3.51 Expression evaluation with precedence order. Extend Evaluate (page 129) to handle arithmetic expressions
// that are not fully parenthesized, using the standard precedence order for the operators +, -. *. and /.
//

#include "arithmetic.h"

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
            return a / b;
        default:
            throw runtime_error("Operator not recognized");
    }
}

float finalizeOperations(Stack<float> &literals, Stack<char> &operators) {
    while (!operators.isEmpty()) {
        char op{operators.pop()};
        float b{literals.pop()};
        float a{literals.pop()};
        literals.push(operation(op, a, b));
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
        } else if (c == ')') {
            finalizeOperations(literals, operators);
        }
    }

    finalizeOperations(literals, operators);

    return literals.pop();
}
