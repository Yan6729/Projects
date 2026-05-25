/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include "../include/myftp.hpp"
using namespace std;

void usage(void)
{
    cout << "USAGE: ./myftp port path" << endl;
    cout << " port is the port number on which the server socket listens" << endl;
    cout << " path is the path to the home directory for the Anonymous user" << endl;
}

int main(int ac, char *av[])
{
    try {
        if (ac == 2 && (string(av[1]) == "-h" || string(av[1]) == "--help")) {
            usage();
            return 0;
        } else {
            if (ac == 3) {
                string _port = av[1];
                if (_port.find_first_not_of("0123456789") != string::npos)
                    throw ServerError("Invalid port");
                int port = stoi(_port);
                if (port < 0 || port >= 65536) {
                    throw ServerError("Invalid port number");
                }
                string path = av[2];
                struct stat buf;
                if (stat(path.c_str(), &buf) != 0) {
                    throw ServerError("Invalid path parsed to the function.");
                }

                Server _server;
                _server.launchServer(port, path);
            } else {
                if (ac < 3)
                    throw ServerError("Too few arguments.");
                else if (ac > 3)
                    throw ServerError("Too many arguments.");
            }
        }
    } catch (const ServerError& e) {
        cerr << e.what() << endl;
        cerr << "Try \"./myftp -h\" || \"./myftp --help\" to see the usage." << endl;
        return 84;
    }
}
