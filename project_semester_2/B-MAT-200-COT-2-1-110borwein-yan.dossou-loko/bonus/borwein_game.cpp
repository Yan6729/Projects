#include "borwein.h"

Font font;
RenderWindow window;
Event event;

void load_text()
{
    if (!font.loadFromFile("arialceb.ttf")) {
        cerr << "Erreur pendant le chargement de la font" << endl;
        exit(84);
    }
}

void init_text(Text &txt, const char *string, Vector2f position, Color color, int size)
{
    txt.setFont(font);
    txt.setString(string);
    txt.setCharacterSize(size);
    txt.setFillColor(color);
    //txt.setStyle(Text::Bold | Text::Underlined);
    txt.setPosition(position);
}

void game_loop_3(const char *cont)
{
    Texture text2;
    Text txt4;
    Text txt1;
    Text txt2;
    Text txt3;
    RectangleShape rect;
    
    if (!text2.loadFromFile("last_image.jpg")) {
        cerr << "Impossible de trouver le fichier" << endl;
        exit(84);
    }
    error_case(cont, &txt1, &txt2, &txt3);
    Sprite last(text2);
    last.setScale(Vector2f {0.86, 1.1});
    rect.setSize(Vector2f(600, 450));
    rect.setFillColor(Color::White);
    rect.setOutlineColor(Color::Black);
    rect.setOutlineThickness(1);
    rect.setPosition({110, 100});
    while(window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {                 
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
            }
        }
        window.clear();
        window.draw(last);
        window.draw(rect);
        window.draw(txt1);
        window.draw(txt2);
        window.draw(txt3);
        window.draw(txt4);
        window.display();
    }
}

void game_loop_2()
{
    Texture text2;
    Text txt2;
    string saisie("");
    const char *cont;
    Text txt3;
    RectangleShape rect;
    const char *skip = "Enter your value here please";

    if (!text2.loadFromFile("mathematiques.jpg")) {
        cerr << "Impossible de trouver le fichier" << endl;
        exit(84);
    }
    Sprite last(text2);
    init_text(txt3, skip, Vector2f {250, 90}, Color::Black, 20);
    txt3.setStyle(Text::Bold);
    last.setScale(Vector2f {0.55, 0.75});
    last.setScale(Vector2f {0.86, 1.1});
    rect.setSize(Vector2f(300, 50));
    rect.setFillColor(Color::White);
    rect.setOutlineColor(Color::Black);
    rect.setOutlineThickness(1);
    rect.setPosition({250, 200});
    while(window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {                 
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
            }
            if (event.type == sf::Event::TextEntered) { 
                if (event.text.unicode == 45 || event.text.unicode >= 48 && event.text.unicode <= 57 || event.text.unicode == 13) {
                    saisie += static_cast<String>(event.text.unicode);
                    cont = saisie.c_str();
                    init_text(txt2, cont, Vector2f {385, 210}, Color::Blue, 21);
                    if (event.text.unicode == 13)
                        game_loop_3(cont);
                }
            }
        }
        window.clear();
        window.draw(last);
        window.draw(txt3);
        window.draw(rect);
        window.draw(txt2);
        window.display();
    }
}

void game_loop()
{
    Texture text2;
    Mouse mouse;
    RectangleShape rect;
    Text txt3;
    Text txt4;
    Text txt5;
    Text txt6;
    const char *skip = "If you want to skip press space";
    const char *str2 = "Welcome to our Epitech project !";
    const char *str = "An obvious conjecture would be that this is true for any value of n. A few\ndecades ago, an old-school mathematician would have had to manually\ncalculate the values of the first integrals (which would have taken several\nmonths or even years), then assume that all integrals were equal to\nM_PI / 2 , and finally attempt to prove this conjecture. Today, we can use\nnumerical computation to evaluate as many of these integrals as possible\nbefore proceeding with a proof; this is the goal of this project.";
    const char *str3 = "(Presented by Yousra AMADOU and Yan DOSSOU-LOKO)";

    if (!text2.loadFromFile("usage.jpg")) {
        cerr << "Impossible de trouver le fichier" << endl;
        exit(84);
    }
    Sprite back_2(text2);
    //diminue le framerate
    back_2.setScale(Vector2f {0.55, 0.74});
    rect.setSize(Vector2f(600, 450));
    rect.setFillColor(Color::White);
    rect.setOutlineColor(Color::Black);
    rect.setOutlineThickness(1);
    rect.setPosition({110, 100});
    init_text(txt3, str, Vector2f {145, 300}, Color::Black, 16);
    init_text(txt4, str2, Vector2f {215, 170}, Color::Black, 20);
    init_text(txt5, str3, Vector2f {215, 200}, Color::Black, 13);
    init_text(txt6, skip, Vector2f {0, 0}, Color::Black, 17);
    txt4.setStyle(Text::Bold | Text::Italic);
    txt5.setStyle(Text::Italic);
    while(window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {                 
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == Keyboard::Space) {
                    game_loop_2();
                }
            }    
        }
        window.clear(Color::Black);
        window.draw(back_2);
        window.draw(rect);
        window.draw(txt3);
        window.draw(txt4);
        window.draw(txt5);
        window.draw(txt6);
        window.display();
    }
}

int main()
{
    Text txt;
    window.create(VideoMode(800, 600, 32), "Borwein !");
    Texture text;
    Texture text2;
    Mouse mouse;

    if (!text.loadFromFile("back_1.jpg")) {
        cerr << "Impossible de trouver le fichier" << endl;
        exit(84);
    }
    if (!text2.loadFromFile("start.png")) {
        cerr << "Impossible de trouver le fichier" << endl;
        exit(84);
    }
    Sprite back(text);
    Sprite start(text2);
    //diminue le framerate
    back.setScale(Vector2f {0.55, 0.74});
    start.setScale(Vector2f {0.4, 0.4});
    start.setPosition(Vector2f {300, 400});
    window.setVerticalSyncEnabled(true);
    load_text();
    while(window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {                 
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                Vector2i pos = Mouse::getPosition();
                if (pos.x >= 430 && pos.x <= 532 && pos.y >= 565 && pos.y <= 616) {
                    game_loop();
                }
            }
        }
        window.draw(back);
        window.draw(start);
        window.display();
    }
    return 0;
}
