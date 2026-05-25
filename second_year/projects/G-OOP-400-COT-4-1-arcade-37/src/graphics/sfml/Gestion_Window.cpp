#include "../../../include/graphics/Arcade_sfml.hpp"

ArcadeSfml::ArcadeSfml() : name("SFML") {}

ArcadeSfml::~ArcadeSfml() {}

void ArcadeSfml::init() {
    std::cout << "Init sfml" << std::endl;
    this->window.create(sf::VideoMode(Window_Width, Window_Height), "Arcade SFML");
    
    if (!this->window.isOpen()) {
        std::cerr << "Failed to create SFML window" << std::endl;
        return;
    }
    this->window.setFramerateLimit(60);
}

void ArcadeSfml::close() {
    if (this->window.isOpen()) {
        this->window.close();
    }
}

const std::string &ArcadeSfml::getName() const {
    return name;
}

void ArcadeSfml::clear() {
    this->window.clear(sf::Color::Black);
}

void ArcadeSfml::display() {
    this->window.display();
}

extern "C" {
    Arcade::IGraphics* createGraphics() {
        return new ArcadeSfml();
    }

    void destroyGraphics(Arcade::IGraphics* graphics) {
        delete graphics;
    }
}