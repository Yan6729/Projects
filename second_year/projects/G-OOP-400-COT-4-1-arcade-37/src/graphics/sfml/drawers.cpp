#include "../../../include/graphics/Arcade_sfml.hpp"

sf::Color ArcadeSfml::SetColor(Arcade::Color color) {
    switch (color) {
        case Arcade::Color::WHITE:
            return sf::Color::White;
        case Arcade::Color::RED:
            return sf::Color::Red;
        case Arcade::Color::GREEN:
            return sf::Color::Green;
        case Arcade::Color::BLUE:
            return sf::Color::Blue;
        case Arcade::Color::YELLOW:
            return sf::Color::Yellow;
        case Arcade::Color::CYAN:
            return sf::Color::Cyan;
        case Arcade::Color::MAGENTA:
            return sf::Color::Magenta;
        case Arcade::Color::BLACK:
            return sf::Color::Black;
        case Arcade::Color::INDIGO:
            return sf::Color(75, 0, 130);
        case Arcade::Color::ORANGE:
            return sf::Color(255, 165, 0);
        case Arcade::Color::VIOLET:
            return sf::Color(238, 130, 238);
        case Arcade::Color::PINK:
            return sf::Color(255, 192, 203);
        case Arcade::Color::BROWN:
            return sf::Color(165, 42, 42);
        case Arcade::Color::GRAY:
            return sf::Color(128, 128, 128);
        case Arcade::Color::LIGHT_BLUE:
            return sf::Color(173, 216, 230);
        case Arcade::Color::LIGHT_GREEN:
            return sf::Color(144, 238, 144);
        case Arcade::Color::LIGHT_RED:
            return sf::Color(255, 182, 193);
        case Arcade::Color::LIGHT_YELLOW:
            return sf::Color(255, 255, 224);
        case Arcade::Color::LIGHT_CYAN:
            return sf::Color(224, 255, 255);
        case Arcade::Color::LIGHT_MAGENTA:
            return sf::Color(255, 224, 255);
        case Arcade::Color::LIGHT_GRAY:
            return sf::Color(211, 211, 211);
        case Arcade::Color::DARK_BLUE:
            return sf::Color(0, 0, 139);
        case Arcade::Color::DARK_GREEN:
            return sf::Color(0, 100, 0);
        case Arcade::Color::DARK_RED:
            return sf::Color(139, 0, 0);
        case Arcade::Color::DARK_YELLOW:
            return sf::Color(139, 139, 0);
        case Arcade::Color::DARK_CYAN:
            return sf::Color(0, 139, 139);
        case Arcade::Color::DARK_MAGENTA:
            return sf::Color(139, 0, 139);
        case Arcade::Color::DARK_GRAY:
            return sf::Color(169, 169, 169);
        default:
            return sf::Color::White;
        
    }
}

void ArcadeSfml::drawText(const Arcade::Text &text) {
    if (!font.loadFromFile(text.font)) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }
    sf::Text sfText(text.content, font, 24);
    sfText.setPosition(text.x, text.y);
    sfText.setFillColor(SetColor(text.color));
    this->window.draw(sfText);
}

void ArcadeSfml::drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) {
    sf::Vector2f size = {static_cast<float> (Window_Width/Col_Grid), static_cast<float> (Window_Height/Line_Grid)};
    sf::RectangleShape Entity(size);
    Entity.setPosition(entity.x * size.x, entity.y * size.y);
    if (entity.sprite.empty()) {
        Entity.setFillColor(SetColor(entity.color));
        this->window.draw(Entity);
        return;
    }
    if (this->_textures.find(entity.sprite) == this->_textures.end()) {
        if (!this->_textures[entity.sprite].loadFromFile(entity.sprite)) {
            std::cerr << "Failed to load texture: " << entity.sprite << std::endl;
            return;
        }
    }
    Entity.setTexture(&this->_textures[entity.sprite], true);
    this->window.draw(Entity);
}

