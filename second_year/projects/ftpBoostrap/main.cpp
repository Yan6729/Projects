/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** main
*/

#include <iostream>
#include <list>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
using namespace std;

void shell(char *env[])
{
    list<string> _env;

    for (int a = 0; env[a] != NULL; a++) {
        _env.push_back(env[a]);
    }

    for (auto& i : _env)
        cout << i << endl;
}

int main(int ac, char *av[], char *env[])
{
    shell(env);
}
