/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** centipedeGame
*/

#ifndef CENTIPEDEGAME_HPP_
    #include "IGame.hpp"
    #define CENTIPEDEGAME_HPP_


namespace Arcade {
    class centipedeGame : public IGame {
        public:
            centipedeGame();
            ~centipedeGame();
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

#endif /* !CENTIPEDEGAME_HPP_ */
