#include "../../../include/graphics/Arcade_sdl.hpp"

ArcadeSdl::ArcadeSdl() : name("SDL2") {}

ArcadeSdl::~ArcadeSdl() {}

void ArcadeSdl::init() {
    std::cout << "Init sdl2" << std::endl;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }
    int imgFlags = IMG_INIT_PNG| IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
        return;
    }
    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow("Arcade SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Window_Width, Window_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, 800, 600);
    if (!renderer) {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        return;
    }
}


void ArcadeSdl::close() {
    if (!this->_textures.empty()) {
        for (auto &pair : this->_textures) {
            if (pair.second) {
                SDL_DestroyTexture(pair.second);
                pair.second = nullptr;
            }
        }
        this->_textures.clear();
    }
    if (!this->_fonts.empty()) {
        for (auto &pair : this->_fonts) {
            if (pair.second) {
                TTF_CloseFont(pair.second);
                pair.second = nullptr;
            }
        }        
        this->_fonts.clear();
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

std::string const &ArcadeSdl::getName() const {
    return name;
}

void ArcadeSdl::clear() {
    SDL_Color Black = {0, 0,0, 225};
    if (SDL_SetRenderDrawColor(renderer, Black.r, Black.g, Black.b, Black.a) != 0) {
        std::cerr << "Failed to set render draw color: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_RenderClear(renderer);
}

void ArcadeSdl::display() {
    SDL_RenderPresent(renderer);
}

extern "C" {
    Arcade::IGraphics* createGraphics() {
        return new ArcadeSdl();
    }

    void destroyGraphics(Arcade::IGraphics* graphics) {
        delete graphics;
    }
}