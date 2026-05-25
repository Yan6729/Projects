/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Stack
*/

#ifndef STACK_HPP_
    #include <iostream>
    #include <stack>
    #define STACK_HPP_

class Stack {
    public:
        Stack();
        ~Stack();
        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();
        class Error : public std::exception {
            public:
                Error(std::string error);
                virtual const char *what() const noexcept override;
            private:
                std::string _msg;
        };

    private:
        std::stack<double> _stack;
};

#endif /* !STACK_HPP_ */
