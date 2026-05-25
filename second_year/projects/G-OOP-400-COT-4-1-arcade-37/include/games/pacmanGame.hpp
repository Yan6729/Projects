/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** pacmanGame
*/

#ifndef PACMANGAME_HPP_
    #include "IGame.hpp"
    #define PACMANGAME_HPP_

namespace Arcade {
    struct pos {
        int x;
        int y;

        bool operator==(const pos& other) {
            return x == other.x && y == other.y;
        }
        bool operator!=(const pos& other) {
            return x != other.x || y != other.y;
        }
    };

    struct GhostInfo {
        Color _color;
        string _name;
        string _prevDir;
        bool _hasLeft;
        size_t _entityIdx;
        pos origin;
        int speed;
    };

    class pacmanGame : public IGame {
        public:
            pacmanGame();
            ~pacmanGame();
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
            bool canBeCrossed(pair<int, int> coord);
            size_t getEntity(char symbol, Color color);
            size_t _h;
            size_t _w;
            unique_ptr<mazeGenerator> _generator = make_unique<mazeGenerator>();
            map<string, vector<string>> pacman_assets;
            map<string, vector<string>> ghost_asstes;
            string _direction;
            int change;
            int change_ghost;
            bool _eatghost;
            int time = 0;
            vector<vector<bool>> buidWallGrid() const;
            pos goAhead(pos start, pos target, const vector<vector<bool>>& wall, pos retour);
            void moveGhosts(void);
            pos setTarget(const GhostInfo &ghost, pos ghostPos, pos pacman);
            vector<GhostInfo> _ghosts;
            vector<string> _dead;
            int lost;
            int affraid;
            int blink;
            void eatGhost();
    };
}

#endif /* !PACMANGAME_HPP_ */
