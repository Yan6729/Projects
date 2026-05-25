/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Shell
*/

#ifndef SHELL_HPP_
    #include <iostream>
    #include <istream>
    #include <sstream>
    #define SHELL_HPP_

class Shell {
    public:
        Shell(std::istream& stream);
        ~Shell();
        void next(void);
        template<typename T>
        T extract(void)
        {
            T value;
            if (!(_buf >> value)) {
                throw Shell::Warning("Invalid conversion");
            } else {
                return value;
            }
        };
        class Error : public std::exception {
            public:
                Error(std::string message);
                virtual const char *what() const noexcept override;

            private:
                std::string _msg;
        };

        class Warning : public std::exception {
            public:
                Warning(std::string message);
                virtual const char *what() const noexcept override;

            private:
                std::string _msg;
        };

    private:
        std::istream& _shell;
        std::stringstream _buf;
};

#endif /* !SHELL_HPP_ */
