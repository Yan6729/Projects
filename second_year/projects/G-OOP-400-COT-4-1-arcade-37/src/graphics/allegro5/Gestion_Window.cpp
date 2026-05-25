#include "../../../include/graphics/Arcade_Allegro5.hpp"


ArcadeAllegro5::ArcadeAllegro5() : name("Allegro 5") {}

ArcadeAllegro5::~ArcadeAllegro5() {}

void ArcadeAllegro5::init() {
    std::cout << "Init allegro5" << std::endl;
    if (!al_init()) {
        std::cerr << "Failed to initialize Allegro" << std::endl;
        return;
    }
    if (!al_init_font_addon()) {
        std::cerr << "Failed to initialize Allegro font addon" << std::endl;
        return;
    }
    if (!al_init_ttf_addon()) {
        std::cerr << "Failed to initialize Allegro TTF addon" << std::endl;
        return;
    }
    if (!al_init_primitives_addon()) {
        std::cerr << "Failed to initialize Allegro primitive addon" << std::endl;
        return;
    }
    if (!al_init_image_addon()) {
        std::cerr << "Failed to initialize Allegro image addon" << std::endl;
        return;
    }
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    this->font = al_create_builtin_font();
    this->show = al_create_display(Window_Width, Window_Height);
    if (!this->show) {
        std::cerr << "Failed to create Allegro display" << std::endl;
        return;
    }
    al_install_keyboard();
    this->event_queue = al_create_event_queue();
    if (!this->event_queue) {
        std::cerr << "Failed to create Allegro event queue" << std::endl;
        return; 
    }
    al_register_event_source(this->event_queue, al_get_display_event_source(this->show));
    al_register_event_source(this->event_queue, al_get_keyboard_event_source());

}

void ArcadeAllegro5::close() {
    for (auto &pair : _textures) {
        if (pair.second) {
            al_destroy_bitmap(pair.second);
        }
    }
    _textures.clear();
    if (event_queue) {
        al_destroy_event_queue(event_queue);
        event_queue = nullptr;
    }
    if (show) {
        al_destroy_display(show);
        show = nullptr;
    }
    al_uninstall_keyboard();
    al_shutdown_primitives_addon();
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_shutdown_image_addon();
    al_uninstall_system();
}

const std::string &ArcadeAllegro5::getName() const {
    return name;
}

void ArcadeAllegro5::clear() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

void ArcadeAllegro5::display() {
    al_flip_display();
}

extern "C" {
    Arcade::IGraphics* createGraphics(void) {
        return new ArcadeAllegro5();
    }

    void destroyGraphics(Arcade::IGraphics* graphics) {
        delete graphics;
    }
}