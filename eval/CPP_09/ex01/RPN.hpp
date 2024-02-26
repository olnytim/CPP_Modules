#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <stack>
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::stack;

class RNP {
private:
    stack<int> operands;

public:
    RNP();
    RNP( const RNP &toCopy );
    RNP &operator=( const RNP &toCopy );
    ~RNP();

    void parse( const string &expression );
    void polish( const char &op );
    class InvalidExpression: public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif
