#ifndef BORWEIN_H
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <iostream>
    #include <cmath>
    #include <cstring>
    #include <cctype>
    #include <unistd.h>
    #include <SFML/Window/Mouse.hpp>
    #define BORWEIN_H

using namespace std;
using namespace sf;
int error_case(const char *str, Text *txt1, Text *txt2, Text *txt3);
void init_text(Text &txt, const char *string, Vector2f position, Color color, int size);

#endif