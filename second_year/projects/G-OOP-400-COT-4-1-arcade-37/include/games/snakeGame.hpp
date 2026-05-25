/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** snakeGame
*/

#ifndef SNAKEGAME_HPP_
    #include "IGame.hpp"
    #define SNAKEGAME_HPP_

namespace Arcade {
    class snakeGame : public IGame {
        public:
            snakeGame();
            ~snakeGame();
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
            string _name;
            int _score;
            bool _isGameOver;
            vector<Entity> _entities;
            string _direction;
            vector<string> foods;
            size_t _h;
            size_t _w;
            map<string, string> _assets;
            size_t getEntity(char symbol, Color color);
            int _timer;
    };
}

#endif /* !SNAKEGAME_HPP_ */
