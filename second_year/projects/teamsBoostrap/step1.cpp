/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** step1
*/

#include <iostream>
#include <poll.h>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>
using namespace std;
#define MAX_COMMAND_LENGTH 32

int main(int ac, char *av[])
{
    struct pollfd fds[2];
    fds[0].fd = 0;
    fds[0].events = POLLIN;
    fds[0].revents = 0;
    fds[1].fd = 1;
    fds[1].events = POLLOUT;
    fds[1].revents = 0;
    char buf[MAX_COMMAND_LENGTH];
    string buffer = "";
    
    int err = poll(fds, 1, -1);
    if (err < 0) {
        return 84;
    }
    while (1) {
        if (!(fds[0].revents & POLLIN))
            break;
        int _bytes = read(fds[0].fd, &buf, sizeof(buf));
        if (_bytes <= 0) {
            break;
        }
        buf[_bytes - 1] = '\0';
        string line(buf);
        buffer += line;
        if (line.find("\n") != string::npos || line.size() >= MAX_COMMAND_LENGTH) {
            break;
        } else {
            buf[0] = '\0';
            line.clear();
            continue;
        }
    }
    //if (!(fds[1].revents & POLLOUT))
      //  return 0;
    write(fds[1].fd, buffer.c_str(), buffer.size());
}
