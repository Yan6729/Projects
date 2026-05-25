/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
#include "../graphics/IGraphics.hpp"
#include <map>
#include "mazeGenerator.hpp"
#define COL 41
#define GRID 41
#define DEFAULT_TICK 100

namespace Arcade {
    class IGame {
        public:
            virtual ~IGame() = default;
            virtual void init(void) = 0;
            virtual void close(void) = 0;
            virtual const string &getName(void) const = 0;
            virtual void update(void) = 0;
            virtual vector<Entity> getEntities(void) const = 0;
            virtual void handleEvent(Input event) = 0;
            virtual int getScore(void) const = 0;
            virtual bool isGameOver(void) = 0;
            virtual size_t getWidth(void) const = 0;
            virtual size_t getHeight(void) const = 0;
    };
}

int generate_random_number(int start, int end);
void move_head(int& x, int& y, string& _direction);
vector<string> generate_map(int col, int grid, int ghostnumber);
string getAssets(const pair<int, int>& prev, const pair<int, int>& curr, const pair<int, int>& next);
void getTailAssetsByState(vector<Arcade::Entity>& _entities);
string getGrassAssets(int h, int w, int x, int y);
size_t findDot(Arcade::Entity space, vector<Arcade::Entity> _entities);
Arcade::Entity choosePiece(int a, int x, int y);
pair<int, int> spawnFood(const vector<Arcade::Entity>& entities, int maxX, int maxY);
pair<int, int> generateRandomTarget(const vector<Arcade::Entity>& entities, int maxX, int maxY);

#endif
