/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Client
*/

#include "../include/Client.hpp"

Client::Client()
{
    _clientSocket = 0;
}

Client::~Client()
{
}

void Client::init(int domain, int type, int protocol)
{
    _clientSocket = socket(domain, type, protocol);

    if (_clientSocket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}

void Client::connectClient(string addressIP, int Port)
{
    int val = 0;
    socklen_t addrlen = sizeof(_infoServer);
    memset(&_infoServer, 0x00, addrlen);

    _infoServer.sin_family = AF_INET;
    _infoServer.sin_port = htons(Port);

    inet_aton(addressIP.c_str(), &_infoServer.sin_addr);

    val = connect(_clientSocket, (const struct sockaddr *)&_infoServer, addrlen);
    if (val == -1) {
        perror("connect");
        closeClientFd();
        exit(EXIT_FAILURE);
    }
}

void Client::sendMessage(string _msg)
{
    int _write = 0;
 
    if (!_msg.empty())
        _send = _msg;

    _write = write(_clientSocket, _send.c_str(), _send.length());

    switch (_write) {
        case 0:
            cerr << "La socket a été fermée par le serveur" << endl;
            closeClientFd();
            exit(EXIT_SUCCESS);
        
        case -1:
            perror("write");
            closeClientFd();
            exit(EXIT_FAILURE);
    default:
        break;
    }
}

void Client::receiveMessage(void)
{
    int _read = 0;

    _receive.resize(2048);
    _read = read(_clientSocket, &_receive[0], 2048);

    switch (_read) {
        case 0:
            cerr << "La socket a été fermée par le serveur" << endl;
            closeClientFd();
            exit(EXIT_SUCCESS);
            
        case -1:
            perror("read");
            closeClientFd();
            exit(EXIT_FAILURE);
    
        default:
            cout << _receive << endl;
            break;
    }
}

void Client::closeClientFd(void)
{
    close(_clientSocket);
}

int main(int ac, char *av[])
{
    Client _client;

    _client.init(AF_INET, SOCK_STREAM, 0);
    _client.connectClient("127.0.0.1", 5500);
    //_client.sendMessage("PWD");
    _client.sendMessage("CWD /home/michou/snd_year_projects/G-NWP-400-COT-4-1-myftp-103");
    //_client.sendMessage("PWD");
    _client.receiveMessage();
    sleep(60);
    _client.closeClientFd();
}