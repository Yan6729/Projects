/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Command
*/

#ifndef COMMAND_HPP_
    #include <iostream>
    #include <string>
    #include <map>
    #include <functional>
    #define COMMAND_HPP_

class Command {
    public:
        Command();
        ~Command();
        void registerCommand(const std::string& name, const std::function<void()>& function);
        void executeCommand(const std::string& name);
        class Error : public std::exception {
            public:
                Error(std::string message);
                virtual const char *what() const noexcept override;
            private:
                std::string _msg = "";
        };

    private:
        std::map<std::string, const std::function<void()>> _map;
};

#endif /* !COMMAND_HPP_ */
