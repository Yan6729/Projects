/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** SfmlOutput
*/

#ifndef SFMLOUTPUT_HPP_
    #define SFMLOUTPUT_HPP_
    #include "IOutput.hpp"
    #include "../reSf/ModifiedWindow.hpp"
    #include "../reSf/Button.hpp"
    #include "PpmOutput.hpp"
    #include "../scene/Scene.hpp"
    #include "LoadFiles.hpp"
    #include "../scene/SceneParser.hpp"
    #include "../scene/SceneBuilder.hpp"
    #include "../camera/Camera.hpp"


namespace RayTracer {
    enum STATE {
        INTRO,
        MENU,
        LOADING,
        RENDERER,
    };

    class SfmlOutput {
        public:
            SfmlOutput();
            ~SfmlOutput();
            void render(void);
            void loader(void);
            void update(const STATE& state);
            void showTheRendering(void);
            void menu_displaying(void);
            void configCamera(CameraData _data);
            void drawSceneButtons(void);
            void loading(void);

        private:
            sf::Sprite createSprite(const sf::Texture& _text, const sf::Vector2f& scale,
                const sf::Vector2f& position);
            sf::Text createTexte(const std::string& label,
                const sf::Vector2f& position,
                std::size_t charactereSize,
                const sf::Color _color
            );
            reSf::ModifiedWindow _window;
            sf::Event _event;
            sf::Image _img;
            int _maxX;
            int _maxY;
            int _loadingProgress;
            int _loadingStep;
            int _scrollOffset = 0;
            int _visibleButtons = 10;
            float _buttonHeight = 70.f;
            float _buttonStartY = 20.f;
            float _maxScroll = 0.f;
            sf::RectangleShape _loadBar;
            sf::Texture _text;
            PpmOutput _ppm;
            FrameBuffer _buf;
            Camera _cam;
            std::string _sceneName;
            sf::Text _sceneText;
            sf::Text avancmentText;
            std::string avencment;
            std::map<std::string, std::string> _filesScene;
            std::vector<reSf::Button> _leftPanelButton;
            std::vector<reSf::Button> _scenesButtons;
            std::vector<reSf::Button> _menuButton;
            PluginFactory<IPrimitive> _prim;
            PluginFactory<ILight> _light;
            std::unique_ptr<SceneParser> _parse;
            std::unique_ptr<SceneBuilder> _build;
            Scene _scene;
            sf::Font _font;
            STATE _state;
            sf::Sprite _sp;
            sf::Texture _introTexture;
            sf::RectangleShape buttonPanel;
            int _currentLine;
            int _index = 1;
            int _gifIndex = 1;
            int count = 0;
            int one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8;
            sf::Texture _back1, _back2, _back3, _back4, _back5, _back6, _back7, _back8;
    };
}

#endif /* !SFMLOUTPUT_HPP_ */
