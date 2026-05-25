/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** slorFoxGame
*/

#ifndef SLORFOXGAME_HPP_
    #include "IGame.hpp"
    #define SLORFOXGAME_HPP_


namespace Arcade {
    class solarFoxGame : public IGame {
        public:
            solarFoxGame();
            ~solarFoxGame();
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
            size_t _h;
            size_t _w;
    };
}

#endif /* !SLORFOXGAME_HPP_ */
