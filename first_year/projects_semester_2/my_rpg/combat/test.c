#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Combat - Pokémon Style", sfResize | sfClose, NULL);
    if (!window)
        return 1;

    // Chargement textures sprites
    sfTexture *player_texture = sfTexture_createFromFile("assets/player_combat.png", NULL);
    sfTexture *enemy_texture = sfTexture_createFromFile("assets/enemy_combat.png", NULL);
    if (!player_texture || !enemy_texture) {
        printf("Erreur chargement textures.\n");
        return 1;
    }

    sfSprite *player_sprite = sfSprite_create();
    sfSprite_setTexture(player_sprite, player_texture, sfTrue);
    sfSprite_setScale(player_sprite, (sfVector2f){2.f, 2.f});
    sfSprite_setPosition(player_sprite, (sfVector2f){100.f, 400.f});

    sfSprite *enemy_sprite = sfSprite_create();
    sfSprite_setTexture(enemy_sprite, enemy_texture, sfTrue);
    sfSprite_setScale(enemy_sprite, (sfVector2f){2.f, 2.f});
    sfSprite_setPosition(enemy_sprite, (sfVector2f){850.f, 150.f});

    // Barre de dialogue
    sfRectangleShape *dialogue_box = sfRectangleShape_create();
    sfRectangleShape_setSize(dialogue_box, (sfVector2f){WINDOW_WIDTH - 100.f, 150.f});
    sfRectangleShape_setPosition(dialogue_box, (sfVector2f){50.f, WINDOW_HEIGHT - 180.f});
    sfRectangleShape_setFillColor(dialogue_box, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineColor(dialogue_box, sfBlack);
    sfRectangleShape_setOutlineThickness(dialogue_box, 3.f);

    // Police
    sfFont *font = sfFont_createFromFile("assets/font.ttf"); // Assure-toi d'avoir une police ici
    if (!font) {
        printf("Erreur chargement police.\n");
        return 1;
    }

    // Curseur >
    sfText *cursor = sfText_create();
    sfText_setFont(cursor, font);
    sfText_setString(cursor, ">");
    sfText_setCharacterSize(cursor, 24);
    sfText_setFillColor(cursor, sfBlack);

    // Options de combat
    sfText *attack_text = sfText_create();
    sfText_setFont(attack_text, font);
    sfText_setString(attack_text, "Attaquer");
    sfText_setCharacterSize(attack_text, 24);
    sfText_setPosition(attack_text, (sfVector2f){150.f, WINDOW_HEIGHT - 150.f});
    sfText_setFillColor(attack_text, sfBlack);

    sfText *flee_text = sfText_create();
    sfText_setFont(flee_text, font);
    sfText_setString(flee_text, "Fuir");
    sfText_setCharacterSize(flee_text, 24);
    sfText_setPosition(flee_text, (sfVector2f){150.f, WINDOW_HEIGHT - 100.f});
    sfText_setFillColor(flee_text, sfBlack);

    int selected_option = 0; // 0 = attaquer, 1 = fuir

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeyDown)
                    selected_option = (selected_option + 1) % 2;
                if (event.key.code == sfKeyUp)
                    selected_option = (selected_option + 1) % 2;
                if (event.key.code == sfKeyEnter || event.key.code == sfKeyReturn) {
                    if (selected_option == 0) {
                        printf("Vous avez choisi d'attaquer !\n");
                    } else {
                        printf("Vous avez fui le combat !\n");
                        sfRenderWindow_close(window);
                    }
                    fflush(stdout);
                }
            }
        }

        // Position curseur
        sfVector2f cursor_pos;
        cursor_pos.x = 120.f;
        cursor_pos.y = (selected_option == 0) ? WINDOW_HEIGHT - 150.f : WINDOW_HEIGHT - 100.f;
        sfText_setPosition(cursor, cursor_pos);

        // Rendu
        sfRenderWindow_clear(window, sfColor_fromRGB(230, 230, 255));
        sfRenderWindow_drawSprite(window, player_sprite, NULL);
        sfRenderWindow_drawSprite(window, enemy_sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, dialogue_box, NULL);
        sfRenderWindow_drawText(window, attack_text, NULL);
        sfRenderWindow_drawText(window, flee_text, NULL);
        sfRenderWindow_drawText(window, cursor, NULL);
        sfRenderWindow_display(window);
    }

    // Libération mémoire
    sfSprite_destroy(player_sprite);
    sfSprite_destroy(enemy_sprite);
    sfTexture_destroy(player_texture);
    sfTexture_destroy(enemy_texture);
    sfText_destroy(cursor);
    sfText_destroy(attack_text);
    sfText_destroy(flee_text);
    sfRectangleShape_destroy(dialogue_box);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);

    return 0;
}
