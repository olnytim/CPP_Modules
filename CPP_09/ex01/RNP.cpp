#include "RNP.hpp"

RNP::RNP() {}

RNP::RNP( const RNP &toCopy ) {
    *this = toCopy;
}

RNP &RNP::operator=(const RNP &toCopy) {
    if (this != &toCopy) {
        *this = toCopy;
    }
    return *this;
}

RNP::~RNP() {}

void RNP::parse( const string &expression ) {
    for (size_t i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i]))
            operands.push(expression[i] - '0');
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            operators.push(expression[i]);
        else if (expression[i] == ' ')
            continue;
        else
            throw InvalidExpression();
    }
    if (operators.size() != operands.size() - 1)
        throw InvalidExpression();
}

const char *RNP::InvalidExpression::what() const throw() {
    return "Error";
}

void RNP::polish() {
    while (true) {
        char op = operators.top();
        operators.pop();
        double op1 = operands.top();
        operands.pop();
        double op2 = operands.top();
        operands.pop();
        switch (op) {
            case '+':
                operands.push(op1 + op2);
                break;
            case '-':
                operands.push(op1 - op2);
                break;
            case '*':
                operands.push(op1 * op2);
                break;
            case '/':
                operands.push(op1 / op2);
                break;
        }
        if (operators.empty() || operands.empty())
            break;
    }
    cout << operands.top() << endl;
    operands.pop();
}