/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** minesweeperGame
*/

#ifndef MINESWEEPERGAME_HPP_
    #include "IGame.hpp"
    #define MINESWEEPERGAME_HPP_

namespace Arcade {
    class minesweeperGame : public IGame {
        public:
            minesweeperGame();
            ~minesweeperGame();
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
            size_t _h;
            size_t _w;
    };
}

#endif /* !MINESWEEPERGAME_HPP_ */
