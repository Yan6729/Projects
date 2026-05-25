/*
** EPITECH PROJECT, 2025
** my_menu.h
** File description:
** Header for RPG menu logic
*/

#ifndef MY_MENU_H_
    #define MY_MENU_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <math.h>
    #define MAX_X 105
    #define MAX_Y 60
    #define MY_RPG

typedef enum {
    POTION,
    NOURRITURE,
    ARME
} TypeObjet;

typedef struct {
    char nom[50];
    TypeObjet type;
    int quantite;
} Objet;

typedef struct {
    Objet objets[100];
    int nombreObjets;
} Inventaire;

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct param_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfUint32 sf;
    player_t player;
} param_t;

typedef struct {
    sfTexture *tex_sol;
    sfTexture *tex_arbre;
    sfTexture *tex_herbe;
    sfTexture *tex_case;
    sfTexture *tex_barr;
    sfTexture *tex_barr_;
} text_t;


typedef struct {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f origin;
    sfVector2f scale_normal;
    sfVector2f scale_hover;
} Button_t;

typedef struct {
    Button_t btn_start;
    Button_t btn_settings;
    Button_t btn_quit;
    Button_t btn_help;
    Button_t btn_back;
} Buttons_t;

typedef struct {
    sfSprite *menu;
    sfSprite *settings;
    sfSprite *help;
} Backgrounds_t;

typedef struct {
    sfRenderWindow *win;
    sfTexture *menu_tex;
    sfTexture *settings_tex;
    sfTexture *help_tex;
    Buttons_t buttons;
    Backgrounds_t backgrounds;
    sfFloatRect rect_back;
    sfFloatRect rect_help;
    int state;
} Menu_t;

int loop(sfRenderWindow *window);
int is_mouse_over(Button_t *btn, sfRenderWindow *win);
void setup_button(Button_t *btn, sfTexture *tex, sfIntRect rect, sfVector2f pos);
int init_window(sfRenderWindow **win);
int load_textures(sfTexture **menu, sfTexture **settings, sfTexture **help);
void init_menu(Menu_t *menu);
void handle_events(Menu_t *menu);
void update_hover(Menu_t *menu);
void draw_menu(Menu_t *menu);
void handle_menu(Menu_t *menu);
void destroy_menu(Menu_t *menu);
sfMusic *play_music_loop(const char *filepath);
void drawInventory(sfRenderWindow* window, Inventaire* inv, sfTexture* texPotion, sfTexture* texPomme, sfTexture* texEpee);
int inventaire_func(sfRenderWindow *window);
void drawInventory(sfRenderWindow* window, Inventaire* inv, sfTexture* texPotion, sfTexture* texPomme, sfTexture* texEpee);

#endif
