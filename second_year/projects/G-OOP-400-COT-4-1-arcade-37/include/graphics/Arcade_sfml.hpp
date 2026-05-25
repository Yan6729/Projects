#ifndef ARCADE_SFML_HPP_
    #define ARCADE_SFML_HPP_
    #include "IGraphics.hpp"

    #include <SFML/Graphics.hpp>
    #include <map>
    #include <queue>

class ArcadeSfml : public Arcade::IGraphics {
    public:
        ArcadeSfml();
        ~ArcadeSfml() override;
        void init() override;
        void close() override;
        const std::string &getName() const override;
        void clear() override;
        sf::Color SetColor(Arcade::Color color);
        Arcade::Input getInput() override;
        void display() override;
        void drawText(const Arcade::Text &text) override;
        void drawEntity(const Arcade::Entity &entity, std::size_t Col_Grid, std::size_t Line_Grid) override;
        char pollChar() override;
        
    private:
        std::string name;
        std::size_t Window_Width = 800;
        std::size_t Window_Height = 600;
        sf::RenderWindow window;
        sf::Font font;
        std::map<std::string, sf::Texture> _textures;
        std::queue<char> _charQueue;
};


#endif