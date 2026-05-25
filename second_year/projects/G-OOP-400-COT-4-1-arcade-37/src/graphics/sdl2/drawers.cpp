#include "../../../include/graphics/Arcade_sdl.hpp"

SDL_Color ArcadeSdl::SetColor(Arcade::Color color) {
    switch (color) {
        case Arcade::Color::WHITE:
            return SDL_Color{255, 255, 255, 255};
        case Arcade::Color::RED:
            return SDL_Color{255, 0, 0, 255};
        case Arcade::Color::GREEN:
            return SDL_Color{0, 255, 0, 255};
        case Arcade::Color::BLUE:
            return SDL_Color{0, 0, 255, 255};
        case Arcade::Color::YELLOW:
            return SDL_Color{255, 255, 0, 255};
        case Arcade::Color::CYAN:
            return SDL_Color{0, 255, 255, 255};
        case Arcade::Color::MAGENTA:
            return SDL_Color{255, 0, 255, 255};
        case Arcade::Color::BLACK:
            return SDL_Color{0, 0, 0, 255};
        case Arcade::Color::INDIGO:
            return SDL_Color{75, 0, 130, 255};
        case Arcade::Color::ORANGE:
            return SDL_Color{255, 165, 0, 255};
        case Arcade::Color::VIOLET:
            return SDL_Color{238, 130, 238, 255};
        case Arcade::Color::PINK:
            return SDL_Color{255, 192, 203, 255};
        case Arcade::Color::BROWN:
            return SDL_Color{165, 42, 42, 255};
        case Arcade::Color::GRAY:
            return SDL_Color{128, 128, 128, 255};
        case Arcade::Color::LIGHT_BLUE:
            return SDL_Color{173, 216, 230, 255};
        case Arcade::Color::LIGHT_GREEN:
            return SDL_Color{144, 238, 144, 255};
        case Arcade::Color::LIGHT_RED:
            return SDL_Color{255, 182, 193, 255};
        case Arcade::Color::LIGHT_YELLOW:
            return SDL_Color{255, 255, 224, 255};
        case Arcade::Color::LIGHT_CYAN: 
            return SDL_Color{224, 255, 255, 255};
        case Arcade::Color::LIGHT_MAGENTA:
            return SDL_Color{255, 224, 255, 255};
        case Arcade::Color::LIGHT_GRAY:
            return SDL_Color{211, 211, 211, 255};
        case Arcade::Color::DARK_BLUE:
            return SDL_Color{0, 0, 139, 255};
        case Arcade::Color::DARK_GREEN:
            return SDL_Color{0, 100, 0, 255};
        case Arcade::Color::DARK_RED:
            return SDL_Color{139, 0, 0, 255};
        case Arcade::Color::DARK_YELLOW:
            return SDL_Color{139, 139, 0, 255};
        case Arcade::Color::DARK_CYAN:
            return SDL_Color{0, 139, 139, 255};
        case Arcade::Color::DARK_MAGENTA:
            return SDL_Color{139, 0, 139, 255};
        case Arcade::Color::DARK_GRAY:
            return SDL_Color{169, 169, 169, 255};
        default:
            return SDL_Color{255, 255, 255, 255};
    }
}
void ArcadeSdl::drawText(const Arcade::Text &text) {
    std::string fontKey = text.font + "_24"; 
    if (this->_fonts.find(fontKey) == this->_fonts.end()) {
        this->_fonts[fontKey] = TTF_OpenFont(text.font.c_str(), 24);
        if (!this->_fonts[fontKey]) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            return;
        }
    }
    TTF_Font *currentFont = this->_fonts[fontKey];
    
    SDL_Color color = SetColor(text.color);
    SDL_Surface *surface = TTF_RenderText_Solid(currentFont, text.content.c_str(), color);
    if (!surface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }
    
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }
    
    SDL_Rect Text;
    Text.w = surface->w;
    Text.h = surface->h;
    Text.x = text.x;
    Text.y = text.y;
    SDL_RenderCopy(renderer, texture, nullptr, &Text);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void ArcadeSdl::drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) {
    SDL_Rect Entity;
    Entity.w = Window_Width/Col_Grid;
    Entity.h = Window_Height/Line_Grid;
    Entity.x = entity.x * Entity.w;
    Entity.y = entity.y * Entity.h;
    if (entity.sprite.empty()) {
        SDL_Color color = SetColor(entity.color);
        if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0) {
            std::cerr << "Failed to set render draw color: " << SDL_GetError() << std::endl;
            return;
        }
        SDL_RenderFillRect(renderer, &Entity);
        return;
    }
    if (this->_textures.find(entity.sprite) == this->_textures.end()) {
        SDL_Surface *surface = IMG_Load(entity.sprite.c_str());
        if (!surface) {
            std::cerr << "Failed to load surface: " << SDL_GetError() << std::endl;
            return;
        }
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cerr << "Failed to load texture: " << entity.sprite << std::endl;
            return;
        }
        this->_textures[entity.sprite] = texture;
        SDL_FreeSurface(surface);
    }
    SDL_RenderCopy(renderer, this->_textures[entity.sprite], nullptr, &Entity);
}