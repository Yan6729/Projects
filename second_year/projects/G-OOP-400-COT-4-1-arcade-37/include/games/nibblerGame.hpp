/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** nibblerGame
*/

#ifndef NIBBLERGAME_HPP_
    #include "IGame.hpp"
    #define NIBBLERGAME_HPP_

namespace Arcade {
    class nibblerGame : public IGame {
        public:
            nibblerGame();
            ~nibblerGame();
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
            string _direction;
            map<string, string> _assets;
            unique_ptr<mazeGenerator> _generator = make_unique<mazeGenerator>();
            bool canBeCrossed(pair<int, int> coord);
            size_t getEntity(char c, Color color);
            bool reverse;
            vector<string> foods;
            vector<string> numbers;
            int _timer;
            int _first;
            int _second;
            int _last;
    };
}

#endif /* !NIBBLERGAME_HPP_ */
