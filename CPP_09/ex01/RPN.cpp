#include "RPN.hpp"

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
        if (isdigit(expression[i]) && (expression[i + 1] == ' ' || expression[i + 1] == '\0'))
            operands.push(expression[i] - '0');
        else if ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*'
                || expression[i] == '/') && (expression[i + 1] == ' ' || expression[i + 1] == '\0'))
            polish(expression[i]);
        else if (expression[i] == ' ')
            continue;
        else
            throw InvalidExpression();
    }
    if (operands.size() != 1)
        throw InvalidExpression();
    cout << operands.top() << endl;
    operands.pop();
}

const char *RNP::InvalidExpression::what() const throw() {
    return "Error";
}

void RNP::polish(const char &op) {
    if (operands.size() > 1) {
        int op1 = operands.top();
        operands.pop();
        int op2 = operands.top();
        operands.pop();
        switch (op) {
            case '+':
                operands.push(op2 + op1);
                break;
            case '-':
                operands.push(op2 - op1);
                break;
            case '*':
                operands.push(op2 * op1);
                break;
            case '/':
                operands.push(op2 / op1);
                break;
        }
    }
    else
        throw InvalidExpression();
}