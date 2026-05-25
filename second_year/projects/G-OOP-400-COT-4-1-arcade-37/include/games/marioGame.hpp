/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** marioGame
*/

#ifndef MARIOGAME_HPP_
    #include "IGame.hpp"
    #define MARIOGAME_HPP_
    #define GRAVITY 0.5f;
    #define JUMP_FORCE -8.0f;


namespace Arcade {
    class marioGame : public IGame {
        public:
            marioGame();
            ~marioGame();
            void init();
            void close();
            const string &getName() const;
            void update();
            vector<Entity> getEntities() const;
            void handleEvent(Input event);
            int getScore() const;
            bool isGameOver();
            size_t getWidth(void) const;
            size_t getHeight(void) const;

        private:
            int _score;
            string _name;
            size_t _h;
            size_t _w;
            bool _isGameOver;
            vector<Entity> _entities;
            int _cameraX;
            int _marioX;
            int _marioY;
            int _viewWidth;
            float _velocityY;
            bool  _isJumping;
            bool  _onGround;
            pair<size_t, size_t> getElement(size_t start, char symbol);
            vector<pair<size_t, size_t>> _tubes;
            bool canBeCrossed();
    };
}

#endif /* !MARIOGAME_HPP_ */
