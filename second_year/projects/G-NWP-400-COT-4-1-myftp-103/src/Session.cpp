/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Session
*/

#include "../include/Session.hpp"

Session::Session(const string& homedir) : 
    _homedir(homedir), _currentDir(homedir),
    _status(false), _user_name(""),
    _passwd(""), _oldpwd(""),
    _isPassive(false), _dataSocket(-1),
    _dataPort(-1), _dataAddress("")
{
    this->initCommands();
}

Session::~Session()
{}

string Session::__user__(string& name, int fd)
{
    (void)fd;
    if (name.empty())
        return "530 Syntax error in parameters or arguments.";
    if (_status == true)
        return "530 User were already connected";
    _user_name = name;
    return "331 User name okay, need password";
}

string Session::__pass__(string& pass, int fd)
{
    (void)fd;
    if (_user_name.empty())
        return "332 Need account for login.";
    if (pass.empty() && _user_name != "Anonymous")
        return "530 Syntax error in parameters or arguments.";
    if (_user_name == "Anonymous") {
        if (!pass.empty()) {
            return "530 Login incorrect.";
        }
        _status = true;
        _passwd = "";
        return "230 User logged in, proceed...";
    }
    (void)pass;
    return "530 Login incorrect.";
}

string Session::__cwd__(string& dir, int fd)
{
    (void)fd;
    if (_status == false)
        return "530 Action not permetted, not logged in";
    if (dir.empty())
        return "501 Syntax error in parameters or arguments.";
    string newPath;

    if (dir == "~")
        newPath = _homedir;
    else if (dir == "-") {
        if (_oldpwd.empty())
            return "550 Failed to change directory";
        std::swap(_currentDir, _oldpwd);
        return 0;
    }
    else if (dir[0] == '/')
        newPath = _homedir + dir;
    else
        newPath = _currentDir + "/" + dir;
    char verified[PATH_MAX];
    if (!realpath(newPath.c_str(), verified))
        return "550 Failed to change directory";

    string finalPath = verified;
    if (finalPath.rfind(_homedir, 0) != 0)
        return "550 Failed to change directory";

    if (finalPath != _currentDir) {
        if (!filesystem::is_directory(finalPath)) {
            return "550 Failed to change director (the target is not a directory)";
        }
        _oldpwd = _currentDir;
        _currentDir = finalPath;
    }
    return "250 Directory successfuly changed";
}

string Session::__pwd__(string& str, int fd)
{
    (void)fd;
    if (!str.empty())
        return "501 Syntax error in parameters or arguments.";
    if (_status == false)
        return "530 Action not permetted, not logged in";
    return "257 \"" + _currentDir + " created.\"";
}

string Session::__list__(string& str, int fd)
{
    if (_status == false)
        return "530 Action not permetted, not logged in";
    if (_dataSocket == -1 && _dataAddress.empty()) {
        return "425 Use PORT or PASV first.";
    }
    send(fd, "150 File status okay... about to open data connection.\r\n", 56, 0);
    int _fd = -1;
    pid_t pid = fork();
    if (pid < 0) {
        return "530 Error in the process";
    }

    if (pid == 0) {
        if (_isPassive == true) {
            struct sockaddr_in clientAddr;
            socklen_t len = sizeof(clientAddr);
            _fd = accept(_dataSocket, (struct sockaddr *)&clientAddr, &len);
            close(_dataSocket);
        } else {
            _fd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in Addr;
            Addr.sin_family = AF_INET;
            Addr.sin_port = htons(_dataPort);
            inet_pton(AF_INET, _dataAddress.c_str(), &Addr.sin_addr);
            if (connect(_fd, (struct sockaddr *)&Addr, sizeof(Addr)) < 0)
                exit(1);
        }
        if (_fd != -1) {
            string cmd;
            if (str.empty())
                cmd = "/bin/ls -l " + _currentDir;
            else
                cmd = "/bin/ls -l " + str;
            FILE *stream = popen(cmd.c_str(), "r");
            char res[1024];
            while (fgets(res, sizeof(res), stream) != NULL) {
                send(_fd, res, strlen(res), 0);
            }
            pclose(stream);
            close(_fd);
        }
        exit(0);
    }
    send(fd, "226 Closing data connection. Transfer complete.\r\n", 49, 0);
    if (_isPassive == true) {
        close(_dataSocket);
        _dataSocket = -1;
        _isPassive = false;
    }
    return "";
}

string Session::__stor__(string& fileName, int fd)
{
    if (fileName.empty())
        return "501 Syntax error in parameters or arguments.";
    if (_status == false)
        return "530 Action not permetted, not logged in";
    if (_dataSocket == -1 && _dataAddress.empty()) {
        return "550 Use PORT or PASV first.";
    }
    std::string filePath = _currentDir + "/" + fileName;
    int fileFd = open(filePath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    send(fd, "150 File status okay; about to open data connection.\r\n", 54, 0);
    pid_t pid = fork();
    if (pid < 0)
        return "502 Error in the process";
    
    if (pid == 0) {
        int _fd = -1;
        if (_isPassive == true) {
            struct sockaddr_in clientAddr;
            socklen_t len = sizeof(clientAddr);
            _fd = accept(_dataSocket, (struct sockaddr *)&clientAddr, &len);
        } else {
            _fd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in _Addr;
            _Addr.sin_family = AF_INET;
            _Addr.sin_port = htons(_dataPort);
            inet_pton(AF_INET, _dataAddress.c_str(), &_Addr.sin_addr);
            if (connect(_fd, (struct sockaddr *)&_Addr, sizeof(_Addr)) < 0)
                exit(1);
        }
        if (_fd != -1) {
            char buffer[4096];
            ssize_t n;
            while ((n = read(_fd, buffer, sizeof(buffer))) > 0) {
                write(fileFd, buffer, n);
            }
            close(_fd);
        }
        close(fileFd);
        exit(0);
    }
    send(fd, "226 Closing data connection. Upload complete.\r\n", 48, 0);
    close(fileFd);
    if (_isPassive == true) {
        close(_dataSocket);
        _dataSocket = -1;
        _isPassive = false;
    }
    return "";
}

string Session::__dele__(string& fileName, int fd)
{
    if (fileName.empty())
        return "501 Syntax error in parameters or arguments.";
    if (_status == false)
        return "530 Action not permetted, not logged in";
    send(fd, "150 File status okay; about to open data connection.\r\n", 54, 0);
    string fullFilePath = fileName[0] == '/' ? _currentDir + fileName : _currentDir + "/" + fileName;

    if (unlink(fullFilePath.c_str()) == 0) {
        return "250 Requested file action okay, completed.";
    } else {
        return "550 Permission denied, neither file not found nor permission denied.";
    }
}

string Session::__retr__(string& fileName, int fd)
{
    if (_status == false)
        return "530 Action not permetted, not logged in";
    if (_dataSocket == -1 && _dataAddress.empty()) {
        return "425 Use PORT or PASV first.";
    }
    if (fileName.empty()) {
        return "501 Syntax error in parameters or arguments.";
    }
    string fullFilePath = fileName[0] == '/' ? _currentDir + fileName : _currentDir + "/" + fileName;
    if (access(fullFilePath.c_str(), R_OK) != 0) {
        return "550 File (" + fullFilePath + ") not found or access denied.";
    }
    send(fd, "150 File status okay; about to open data connection.\r\n", 54, 0);
    pid_t pid = fork();
    int _fd = -1;
    if (pid < 0)
        return "530 Error in the process";

    if (pid == 0) {
        if (_isPassive == true) {
            struct sockaddr_in clientAddr;
            socklen_t len = sizeof(clientAddr);
            _fd = accept(_dataSocket, (struct sockaddr *)&clientAddr, &len);
            close(_dataSocket);
        } else {
            _fd = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in Addr;
            Addr.sin_family = AF_INET;
            Addr.sin_port = htons(_dataPort);
            inet_pton(AF_INET, _dataAddress.c_str(), &Addr.sin_addr);
            if (connect(_fd, (struct sockaddr *)&Addr, sizeof(Addr)) < 0)
                exit(1);
        }

        if (_fd != -1) {
            int _fileFd = open(fullFilePath.c_str(), O_RDONLY);
            char buffer[4096];
            ssize_t n;
            if (fd != -1) {
                while ((n = read(_fileFd, buffer, sizeof(buffer))) > 0) {
                    send(_fd, buffer, n, 0);
                }
                close(fd);
            }
            close(_fd);
        }
        exit(0);
    }
    send(fd, "226 Closing data connection. Download complete.\r\n", 49, 0);
    if (_isPassive == true) {
        close(_dataSocket);
        _dataSocket = -1;
        _isPassive = false;
    }
    return "";
}

string Session::__pasv__(string& str, int fd)
{
    if (_isPassive == true) {
        return "125 Data connection already open; transfer starting.";
    }
    (void)fd;
    if (!str.empty()) {
        return "501 Syntax error in parameters or arguments.";
    }
    if (_status == false)
        return "530 Action not permetted, not logged in";
    _dataSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    socklen_t addrLen = sizeof(addr);
    std::memset(&addr, 0, addrLen);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = 0;

    if (bind(_dataSocket, (struct sockaddr *)&addr, addrLen) < 0)
        return "530 Command Failed.";
    if (listen(_dataSocket, 1) < 0)
        return "530 Command Failed.";
    getsockname(_dataSocket, (struct sockaddr *)&addr, &addrLen);
    int port = ntohs(addr.sin_port);
    int p1 = port / 256;
    int p2 = port % 256;
    _isPassive = true;

    sockaddr_in _addr;
    socklen_t len = sizeof(_addr);
    getsockname(fd, (sockaddr*)&_addr, &len);
    string addresse = inet_ntoa(_addr.sin_addr);
    replace(addresse.begin(), addresse.end(), '.', ',');
    return "227 Entering Passive Mode ("+ addresse + "," + std::to_string(p1) + "," + std::to_string(p2) + ").";
}

string Session::__noop__(string& str, int fd)
{
    (void)fd;
    (void)str;
    return "200 Command okay";
}

string Session::__cdup__(string& str, int fd)
{
    (void)fd;
    if (!str.empty()) {
        return "501 Syntax error in parameters or arguments.";
    }
    string parent = "..";
    string _return = this->__cwd__(parent, fd);
    return _return.find("250") != string::npos ? "200 Command okay." : _return;
}

string Session::__port__(string& cmd, int fd)
{
    if (!_dataAddress.empty()) {
        return "125 Data connection already open; transfer starting.";
    }
    (void)fd;
    if (_status == false)
        return "530 Action not permetted, not logged in";
    string data = cmd;
    replace(data.begin(), data.end(), ',', ' ');

    stringstream ss(data);
    string _1, _2, _3, _4, _5, _6;
    if (!(ss >> _1 >> _2 >> _3 >> _4 >> _5 >> _6))
        return "501 Syntax error in parameters or arguments.";

    _dataAddress = _1 + "." + _2 + "." + _3 + "." + _4;
    int port = stoi(_5)*256 + stoi(_6);
    if (port >= 65536)
        return "500 Port number out of range, made sure your result is less than 65536.";
    _dataPort = port;
    _isPassive = false;
    return "200 Command okay.";
}

string Session::__help__(string& str, int fd)
{
    (void)str;
    (void)fd;
    return "214 Here is the available commands\n"
    "USER <SP> <username> <CRLF>   : Specify user for authentication\n"
    "PASS <SP> <password> <CRLF>   : Specify password for authentication\n"
    "CWD  <SP> <pathname> <CRLF>   : Change working directory\n"
    "CDUP <CRLF>                   : Change working directory to parent directory\n"
    "QUIT <CRLF>                   : Disconnection\n"
    "DELE <SP> <pathname> <CRLF>   : Delete file on the server\n"
    "PWD  <CRLF>                   : Print working directory\n"
    "PASV <CRLF>                   : Enable \"passive\" mode for data transfer\n"
    "PORT <SP> <host-port> <CRLF>  : Enable \"active\" mode for data transfer\n"
    "HELP [<SP> <string>] <CRLF>   : List available commands\n"
    "NOOP <CRLF>                   : Do nothing (the following are commands using data transfer)\n"
    "RETR <SP> <pathname> <CRLF>   : Download file from server to client\n"
    "STOR <SP> <pathname> <CRLF>   : Upload file from client to server\n"
    "LIST [<SP> <pathname>] <CRLF> : List files in the current working directory\n";
}

string Session::__quit__(string& str, int fd)
{
    (void)str;
    (void)fd;
    return "221: loging out from the server...";
}

void Session::initCommands(void)
{
    _commands.emplace("USER", &Session::__user__);
    _commands.emplace("PASS", &Session::__pass__);
    _commands.emplace("NOOP", &Session::__noop__);
    _commands.emplace("DELE", &Session::__dele__);
    _commands.emplace("LIST", &Session::__list__);
    _commands.emplace("PORT", &Session::__port__);
    _commands.emplace("PASV", &Session::__pasv__);
    _commands.emplace("CWD", &Session::__cwd__);
    _commands.emplace("PWD", &Session::__pwd__);
    _commands.emplace("CDUP", &Session::__cdup__);
    _commands.emplace("RETR", &Session::__retr__);
    _commands.emplace("STOR", &Session::__stor__);
    _commands.emplace("HELP", &Session::__help__);
    _commands.emplace("QUIT", &Session::__quit__);
}

string Session::handle(string& cmd, int fd)
{
    stringstream ss(cmd);

    string one = "";
    string two = "";

    ss >> one >> two;

    if (_commands.find(one) == _commands.end()) {
        return "500 Unknown command, try \"HELP\" to see the allowed actions";
    } else {
        return (this->*_commands[one])(two, fd);
    }
}
