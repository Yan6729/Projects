/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Server
*/

#include "Server.hpp"
using namespace std;
atomic<bool> run(true);

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
    cout << "Socket créée avec succès !" << endl;
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
}

void Server::listenPort(void)
{
    _listen = listen(_serverSocket, SOMAXCONN);

    if (_listen < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void Server::acceptConnection(void)
{

    _client = accept(_serverSocket, (struct sockaddr*)&_addrClient, &_addrlen);
    if (_client < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}

void Server::sendMessage(string _msg)
{
    int _write = 0;
 
    if (!_msg.empty())
        _send = _msg;

    _write = write(_client, _send.c_str(), _send.length());

    switch (_write) {
        case 0:
            cerr << "La socket a été fermée par le serveur" << endl;
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
    return inet_ntoa(_addrClient.sin_addr) + sep + to_string(ntohs(_addrServer.sin_port));
}

int Server::receiveMessage(void)
{
    int _read = 0;

    _receive.resize(2048);
    _read = read(_client, &_receive[0], 2048);

    _receive[_read] = '\0';
    switch (_read) {
        case 0:
            cerr << "La socket a été fermée par le serveur" << endl;
            closeServerFd();
            exit(EXIT_SUCCESS);
            
        case -1:
            perror("read");
            closeServerFd();
            exit(EXIT_FAILURE);
    
        default:
            _receive.resize(_read);
            cout << _receive << endl;
            if (_receive == "Je rêve son visage, je décline son corps")
                return -1;
            return 0;
    }
}

void Server::closeServerFd(void)
{
    close(_serverSocket);
}

void Server::closeClientFd(void)
{
    close(_client);
}

void signal_hanger(int signum)
{
    //if (signum == SIGINT) {
      //  run = false;
        //return;
    //}
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main()
{
    Server _server;
    pid_t pid = 0;

    signal(SIGCHLD, signal_hanger);
    //signal(SIGINT, signal_hanger);
    _server.init(AF_INET, SOCK_STREAM, 0);
    _server.bindServer(AF_INET, 5500);
    _server.listenPort();
    while (run) {
        _server.acceptConnection();
        cout << "Connection from " << _server.clientIP() << endl;
        pid = fork();
        if (pid == -1) {
            perror("fork");
            _server.closeServerFd();
            continue;
        }
        if (pid == 0) {
            _server.closeServerFd();
            while (1) {
                int _return = _server.receiveMessage();
                _return == -1 ? 
                _server.sendMessage("Et puis je l'imagine habitant mon décor\nJ'aurais tant à lui dire si j'avais su parler\nComment lui faire lire au fond de mes pensées?\nMais comment font ces autres à qui tout réussit?\nQu'on me dise mes fautes, mes chimères aussi\nMoi j'offrirais mon âme, mon cœur et tout mon temps\nMais j'ai beau tout donner, tout n'est pas suffisant\nS'il suffisait qu'on s'aime, s'il suffisait d'aimer\nSi l'on changeait les choses un peu, rien qu'en aimant donner\nS'il suffisait qu'on s'aime, s'il suffisait d'aimer\nJe ferais de ce monde un rêve, une éternité\nJ'ai du sang dans mes songes, un pétale séché\nQuand des larmes me rongent que d'autres ont versées\nLa vie n'est pas étanche, mon île est sous le vent\nLes portes laissent entrer les cris même en fermant\nDans un jardin d'enfant, sur un balcon, des fleurs\nMa vie paisible où j'entends battre tous les cœurs\nQuand les nuages foncent, présages des malheurs\nQuelles armes répondent aux pays de nos peurs?\nS'il suffisait qu'on s'aime, s'il suffisait d'aimer\nSi l'on changeait les choses un peu, rien qu'en aimant donner\nS'il suffisait qu'on s'aime, s'il suffisait d'aimer\nJe ferais de ce monde un rêve, une éternité\nS'il suffisait qu'on s'aime, s'il suffisait d'aimer\nSi l'on pouvait changer les choses et tout recommencer\nS'il suffisait qu'on s'aime, s'il suffisait d'aimer\nNous ferions de ce rêve un monde\nS'il suffisait d'aimer") :
                _server.sendMessage("She likes everyone\nI never like to admit that I was wrong");
            }
            _server.closeClientFd();
        } else
            _server.closeClientFd();
    }
    _server.closeServerFd();
}
