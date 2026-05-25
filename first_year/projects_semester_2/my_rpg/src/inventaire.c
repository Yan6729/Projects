#include "../include/my_rpg.h"

void addObj(Inventaire* inv, Objet objet)
{
    if (inv->nombreObjets >= 100) {
        printf("L'inventaire est plein, impossible d'ajouter %s\n", objet.nom);
        return;
    }
    inv->objets[inv->nombreObjets] = objet;
    inv->nombreObjets++;
}

void manage_event(param_t *param)
{
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed) {
            sfRenderWindow_close(param->window);
        }
    }
}

sfTexture* loadTexture(const char* filename)
{
    sfTexture* tex = sfTexture_createFromFile(filename, NULL);
    if (!tex) {
        fprintf(stderr, "Erreur chargement texture : %s\n", filename);
    }
    return tex;
}

void setSpriteToSize(sfSprite* sprite, sfTexture* texture, float width, float height)
{
    sfVector2u size = sfTexture_getSize(texture);
    float scaleX = width / size.x;
    float scaleY = height / size.y;
    sfSprite_setScale(sprite, (sfVector2f){scaleX, scaleY});
}

void drawInventory(sfRenderWindow* window, Inventaire* inv, sfTexture* texPotion, sfTexture* texPomme, sfTexture* texEpee)
{
    sfSprite* spr = sfSprite_create();
    const int spacing = 80;
    const int startX = 85;
    const int startY = 121;
    sfTexture *text = sfTexture_createFromFile("texture/inventaire_3.png", NULL);
    sfSprite *invent = sfSprite_create();

    sfSprite_setTexture(invent, text, sfTrue);
    sfSprite_setScale(invent, (sfVector2f){0.7, 0.7});

    sfRenderWindow_drawSprite(window, invent, NULL);
    for (int i = 0; i < inv->nombreObjets; i++) {
        Objet* obj = &inv->objets[i];

        sfTexture* tex = NULL;
        if (obj->type == POTION) tex = texPotion;
        else if (obj->type == NOURRITURE) tex = texPomme;
        else if (obj->type == ARME) tex = texEpee;
        if (!tex) continue;
        sfSprite_setTexture(spr, tex, sfTrue);
        setSpriteToSize(spr, tex, 64, 64);
        sfVector2f pos = {startX + i * spacing, startY};
        sfSprite_setPosition(spr, pos);
        sfRenderWindow_drawSprite(window, spr, NULL);
        char quantiteText[10];
        sprintf(quantiteText, "x%d", obj->quantite);
        static sfFont* font = NULL;
        if (!font) {
            font = sfFont_createFromFile("fonts/super_adorable.ttf");
            if (!font) fprintf(stderr, "Erreur chargement police\n");
        }
        sfText* text = sfText_create();
        sfText_setString(text, quantiteText);
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 20);
        sfText_setFillColor(text, sfWhite);
        sfText_setPosition(text, (sfVector2f){pos.x + 45, pos.y + 45});
        sfRenderWindow_drawText(window, text, NULL);
        sfText_destroy(text);
    }

    sfSprite_destroy(spr);
}

void init_param(param_t *param)
{
    sfVideoMode mode = {800, 600, 32};

    param->window = sfRenderWindow_create(mode, "My_RPG", sfClose, NULL);
}

int inventaire_func(sfRenderWindow *window)
{
    sfTexture *texture1;
    Inventaire inventaire = { .nombreObjets = 0 };

    addObj(&inventaire, (Objet){"Potion de soin", POTION, 50});
    addObj(&inventaire, (Objet){"Pomme", NOURRITURE, 50});
    addObj(&inventaire, (Objet){"Épée en fer", ARME, 50});
    sfTexture* texPotion = loadTexture("texture/potion_rouge2.png");
    sfTexture* texPomme = loadTexture("texture/pomme2.png");
    sfTexture* texEpee = loadTexture("texture/epee2.png");
    if (!texPotion || !texPomme || !texEpee) {
        fprintf(stderr, "Erreur de chargement des textures, fin du programme\n");
        return 1;
    }

    drawInventory(window, &inventaire, texPotion, texPomme, texEpee);
    sfTexture_destroy(texPotion);
    sfTexture_destroy(texPomme);
    sfTexture_destroy(texEpee);

    return 0;
}



