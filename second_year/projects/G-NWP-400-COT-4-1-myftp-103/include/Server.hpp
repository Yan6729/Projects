/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #include "Session.hpp"
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
        int acceptConnection(void);
        void sendMessage(int _clientfd, string _msg);
        int receiveMessage(int _clientfd, string& msg);
        void closeServerFd(void);
        void closeClientFd(int clientfd, size_t index);
        void createSession(int fd, const string& path);
        void launchServer(int& port, string& path);
        string clientIP(void);
        void handleClient(int _clientfd, size_t index);

    private:
        int _serverSocket;
        struct sockaddr_in _addrServer;
        int _listen;
        socklen_t _addrlen;
        string _send = "";
        struct sockaddr_in _addrClient;
        vector<pollfd> _pollfds;
        map <int, Session> _session;
        string _homedir;
};

#endif /* !SERVER_HPP_ */
