#include "../../../include/graphics/Arcade_Libcaca.hpp"

ArcadeLibcaca::ArcadeLibcaca() : name("libcaca"), canvas(nullptr), display_ptr(nullptr) {}

ArcadeLibcaca::~ArcadeLibcaca() {}

void ArcadeLibcaca::init() {
    std::cout << "Init libcaca" << std::endl;
    canvas = caca_create_canvas(Window_Width/8, Window_Height/16);
    setenv("CACA_DRIVER", "slang", 1);
    display_ptr = caca_create_display(canvas);
    if (!display_ptr) {
        std::cerr << "Failed to initialize libcaca display" << std::endl;
        caca_free_canvas(canvas);
        canvas = nullptr;
        return;
    }

    caca_set_display_title(display_ptr, "Arcade Libcaca");
}


void ArcadeLibcaca::close() {
    if (display_ptr) {
        caca_free_display(display_ptr);
        display_ptr = nullptr;
    }
    if (canvas) {
        caca_free_canvas(canvas);
        canvas = nullptr;
    }
}

const std::string &ArcadeLibcaca::getName() const {
    return name;
}

void ArcadeLibcaca::clear() {
    if (canvas) {
        caca_set_color_argb(canvas, 0xF444, 0xF444);
        caca_clear_canvas(canvas);

        caca_set_color_ansi(canvas, CACA_WHITE, CACA_BLACK);
        caca_draw_thin_box(canvas, 0, 0, Window_Width/8 + 1, Window_Height/16+1);
    }
}


void ArcadeLibcaca::display() {
    if (display_ptr) {
        caca_refresh_display(display_ptr);
    }
}

extern "C" {
    Arcade::IGraphics* createGraphics() {
        return new ArcadeLibcaca();
    }

    void destroyGraphics(Arcade::IGraphics* graphics) {
        delete graphics;
    }
}