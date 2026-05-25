/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** maizeGenerator
*/

#ifndef MAIZEGENERATOR_HPP_
    #define MAIZEGENERATOR_HPP_
    #include "IGame.hpp"


namespace Arcade {
    struct Pos {
        int x;
        int y;
    };

    class mazeGenerator {
        public:
            mazeGenerator();
            ~mazeGenerator();
            void init(int height, int width, int ghostHouseHeight, int ghostHouseWidht);
            void init(int height, int width);
            void carvePath(int x, int y);
            void removeDeadEnds(void);
            void applySymmetry(void);
            vector<string> getMaze(void);
            void createGhostHouse(void);
            bool isInGhostHouse(int x, int y);
            bool isBorder(int x, int y);
            void generate(void);


        private:
            int _height;
            int _width;
            Pos _start;
            Pos _center;
            int _upCY;
            int _upCX;
            int _downCY;
            int _downCX;
            int _h;
            int _w;
            vector<string> _maze;
    };
}

#endif /* !MAIZEGENERATOR_HPP_ */
