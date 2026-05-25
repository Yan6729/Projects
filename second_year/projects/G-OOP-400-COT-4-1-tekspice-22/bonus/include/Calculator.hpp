/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Calculator
*/

#ifndef CALCULATOR_HPP_
    #include "Button.hpp"
    #include "CoreEngine.hpp"
    #define CALCULATOR_HPP_
    using namespace reSf;

class Calculator {
    public:
        Calculator();
        ~Calculator();
        int launch(void);

    protected:
    private:
        list<Button> _btns;
        map<string, unique_ptr<Button>> _btn;
        CoreEngine _back;
        Font _font;
};

#endif /* !CALCULATOR_HPP_ */
