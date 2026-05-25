/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Server
*/

#include "../include/Server.hpp"
using namespace std;
atomic<bool> run(true);


string _format_(const string& str)
{
    string _str = str;
    replace(_str.begin(), _str.end(), '\t', ' ');

    auto bothAreSpace = [](char l, char r) {
        return l == ' ' && r == ' ';
    };
    _str.erase(remove(_str.begin(), _str.end(), '\n'), _str.end());
    _str.erase(remove(_str.begin(), _str.end(), '\r'), _str.end());
    _str.erase(unique(_str.begin(), _str.end(), bothAreSpace), _str.end());
    while (!_str.empty() && _str.front() == ' ')
        _str.erase(_str.begin());
    while (!_str.empty() && _str.back() == ' ')
        _str.pop_back();

    return _str;
}

ServerError::ServerError(string message)
{
    _msg = message;
}

ServerError::~ServerError()
{}

const char* ServerError::what() const noexcept
{
    return _msg.c_str();
}

Server::Server()
{
    _serverSocket = 0;
}

Server::~Server()
{
}

void Server::init(int domain, int type, int protocol)
{
    _serverSocket = socket(domain, type, protocol);

    if (_serverSocket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}

void Server::bindServer(int domain, int port)
{
    int val = 0;

    _addrlen = sizeof(struct sockaddr_in);
    memset(&_addrServer, 0x00, _addrlen);

    _addrServer.sin_family = domain;
    _addrServer.sin_port = htons(port);
    _addrServer.sin_addr = {htonl(INADDR_ANY)};

    val = bind(_serverSocket, (const struct sockaddr*)&_addrServer, _addrlen);
    if (val < 0) {
        perror("bind");
        closeServerFd();
        exit(EXIT_FAILURE);
    }
    cout << "Serveur Created successfully and run on port " << port << "..." << endl;
}

void Server::listenPort(void)
{
    _listen = listen(_serverSocket, SOMAXCONN);

    if (_listen < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    struct pollfd _fd;

    _fd.fd = _serverSocket;
    _fd.events = POLLIN;
    _fd.revents = 0;
    _pollfds.push_back(_fd);
}

void Server::createSession(int fd, const string& path)
{
    _session.emplace(fd, Session(path));
}

int Server::acceptConnection(void)
{

    int _client = accept(_serverSocket, (struct sockaddr*)&_addrClient, &_addrlen);
    if (_client < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    struct pollfd _fd;
    _fd.fd = _client;
    _fd.events = POLLIN;
    _fd.revents = 0;
    _pollfds.push_back(_fd);
    createSession(_client, _homedir);
    cout << "Client accepted on FD " << _client << " from " << this->clientIP() << endl;
    this->sendMessage(_client, "220 Server ready for new user...\r\n");
    return _client;
}

void Server::sendMessage(int _clientfd, string _msg)
{
    int _write = 0;
 
    if (!_msg.empty())
        _send = _msg;

    _write = send(_clientfd, _send.c_str(), _send.length(), 0);

    switch (_write) {
        case 0:
            cerr << "" << endl;
            closeServerFd();
            exit(EXIT_SUCCESS);
        
        case -1:
            perror("write");
            closeServerFd();
            exit(EXIT_FAILURE);
    default:
        break;
    }
}

string Server::clientIP(void)
{
    string sep = ":";
    return string(inet_ntoa(_addrClient.sin_addr)) + sep + to_string(ntohs(_addrServer.sin_port));
}

int Server::receiveMessage(int _clientfd, string& msg)
{
    int _read = 0;
    char _receive[2048];

    _read = recv(_clientfd, _receive, sizeof(_receive), 0);
    _receive[_read] = '\0';
    if (_read > 0) {
        msg.assign(_receive, _read);
        return _read;
    } else if (_read == 0) {
        return _read;
    } else {
        perror("revc");
        return _read;
    }
}

void Server::closeServerFd(void)
{
    close(_serverSocket);
}

void Server::closeClientFd(int fd, size_t index)
{
    close(fd);
    _session.erase(fd);
    _pollfds.erase(_pollfds.begin() + index);
    cout << "Client on FD " << fd << " deconnected." << endl;
}

void Server::handleClient(int _clientfd, size_t index)
{
    string msg = "";

    int read = this->receiveMessage(_clientfd, msg);
    if (read < 0) {
        closeClientFd(_clientfd, index);
        return;
    }

    string _msg = _format_(msg);
    string response = _session.at(_clientfd).handle(_msg, _clientfd);
    if (response.empty())
        return;
    this->sendMessage(_clientfd,  response+"\r\n");
    if (response.find("221") != string::npos) {
        closeClientFd(_clientfd, index);
    }
}

void signal_hanger(int signum)
{
    if (signum == SIGINT) {
        run = false;
        return;
    }
}

void Server::launchServer(int& port, string& path)
{
    pid_t pid = 0;
    int activity = 0;

    char resolved[PATH_MAX];
    realpath(path.c_str(), resolved);
    _homedir = resolved;
    signal(SIGINT, signal_hanger);
    signal(SIGCHLD, SIG_IGN);
    this->init(AF_INET, SOCK_STREAM, 0);
    this->bindServer(AF_INET, port);
    this->listenPort();
    while (run) {
        activity = poll(_pollfds.data(), _pollfds.size(), -1);
        if (activity < 0) {
            perror("poll");
            break;
        }

        for (size_t a = 0; a < _pollfds.size(); a++) {
            if (!(_pollfds[a].revents & POLLIN))
                continue;
            if (_pollfds[a].fd == _serverSocket) {
                this->acceptConnection();
            } else {
                handleClient(_pollfds[a].fd, a);
            }
        }
    }
    this->closeServerFd();
}
