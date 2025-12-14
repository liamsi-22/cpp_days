#include "RPN.hpp"
#include <iostream>

RPN::RPN(){}
RPN::RPN(const RPN &){}
RPN &RPN::operator=(const RPN &){
    return (*this);
}

int RPN::evalRPN(const std::string &arg)
{
        std::stack<int> stack;
        std::stringstream ss(arg);
        std::string character;

        while (ss >> character)
        {
            if (character == "+" || character == "-" || character == "*" || character == "/")
            {
                if (stack.size() < 2)
                    throw std::runtime_error("Error: wrong input!");

                int num2 = stack.top();stack.pop();
                int num1 = stack.top();stack.pop();

                if (character == "+")
                    stack.push(num1 + num2);
                else if (character == "-")
                    stack.push(num1 - num2);
                else if (character == "*")
                    stack.push(num1 * num2);
                else{
                    if (num2 == 0)
                        throw std::runtime_error("Error: can't divide by 0 !");
                    stack.push(num1 / num2);
                }
            }
            else{
                if ((character.length() == 2 && (character[0] != '-' || !std::isdigit(character[1]))) || (character.length() == 1 && !std::isdigit(character[0])) || character.length() > 2)
                    throw std::runtime_error("Error: unvalid operand or operator !");
                else
                    stack.push(atoi(character.c_str()));
            }
        }
        if (stack.size() != 1)
            throw std::runtime_error("Error: wrong input !");

        int result = stack.top();
        stack.pop();
        return result;
}

RPN::~RPN(){}