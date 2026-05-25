/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Shell
*/

#ifndef SHELL_HPP_
    #include <string>
    #include <iostream>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sstream>
    #include <limits.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <exception>
    #include <cstring>
    #include <csignal>
    #include <atomic>
    #include <map>
    #include <fstream>
    #include <functional>
    #include "poll.h"
    #include <fcntl.h>
    #include <filesystem>
    #define SHELL_HPP_
    using namespace std;
    #define Command string (Session::*)(string&, int)

class Session {
    public:
        Session(const string& homedir);
        ~Session();
        string __user__(string& name, int fd);
        string __pass__(string& pass, int fd);
        string __pwd__(string& str, int fd);
        string __list__(string& str, int fd);
        string __cwd__(string& dir, int fd);
        string __quit__(string& str, int fd);
        string __help__(string& str, int fd);
        string __noop__(string& str, int fd);
        string __retr__(string& str, int fd);
        string __dele__(string& str, int fd);
        string __stor__(string& str, int fd);
        string __pasv__(string& str, int fd);
        string __cdup__(string& str, int fd);
        string __port__(string& cmd, int fd);
        void initCommands(void);
        string handle(string& cmd, int fd);

    protected:
        string _oldpwd;
        string _homedir;
        string _currentDir;
        string _user_name;
        string _passwd;
        bool _status;
        bool _isPassive = false;
        int _dataSocket = 0;
        int _dataPort = 0;
        string _dataAddress = "";
        map<string, Command> _commands;
    private:
};

#endif /* !SHELL_HPP_ */
