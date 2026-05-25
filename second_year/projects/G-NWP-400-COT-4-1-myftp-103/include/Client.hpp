/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #include <iostream>
    #include <string>
    #include <list>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <exception>
    #include <unistd.h>
    #include <string.h>
    #define CLIENT_HPP_
    using namespace std;

class Client {
    public:
        Client();
        ~Client();
        void init(int domain, int type, int protocol);
        void connectClient(string addressIP, int Port);
        void sendMessage(string _msg);
        void receiveMessage(void);
        void closeClientFd(void);

    private:
        int _clientSocket;
        struct sockaddr_in _infoServer;
        string _send = "";
        string _receive = "";
};

#endif /* !CLIENT_HPP_ */
