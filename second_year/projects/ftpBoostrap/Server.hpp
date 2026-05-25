/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #include <iostream>
    #include <list>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <exception>
    #include <unistd.h>
    #include <string.h>
    #include <limits.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <atomic>
    #define SERVER_HPP_
    using namespace std;

class ServerError : public exception {
    public:
        ServerError(string messages);
        ~ServerError();
        virtual const char *what() const noexcept override;
    private:
        string _msg;
};

class Server {
    public:
        Server();
        ~Server();
        void init(int domain, int type, int protocol);
        void bindServer(int domain, int port);
        void listenPort(void);
        void acceptConnection(void);
        void sendMessage(string _msg);
        int receiveMessage(void);
        void closeServerFd(void);
        void closeClientFd(void);
        string clientIP(void);

    private:
        int _serverSocket;
        struct sockaddr_in _addrServer;
        int _listen;
        socklen_t _addrlen;
        int _client;
        string _send = "";
        struct sockaddr_in _addrClient;
        string _receive = "";
};

#endif /* !SERVER_HPP_ */
