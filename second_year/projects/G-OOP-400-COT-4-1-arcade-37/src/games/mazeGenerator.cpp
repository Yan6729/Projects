/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** maizeGeneration
*/

#include "../../include/games/mazeGenerator.hpp"
using namespace Arcade;

mazeGenerator::mazeGenerator()
{}

mazeGenerator::~mazeGenerator()
{}

void mazeGenerator::init(int height, int width, int ghostHouseHeight, int ghostHouseWidht)
{
    _height = height;
    _width = width;
    _center = {_width/2, _height/2};
    _h = ghostHouseHeight;
    _w = ghostHouseWidht;
    _upCX =  _center.x - _w/2;
    _upCY = _center.y - _h/2;
    _downCX =  _center.x + _w/2;
    _downCY = _center.y + _h/2;
    _maze.assign(_height, string(_width, '#'));
}

void mazeGenerator::init(int height, int width)
{
    _height = height;
    _width = width;
    _h = 0;
    _w = 0;
    _center = {_width/2, _height/2};
    _upCX =  _center.x - _w/2;
    _upCY = _center.y - _h/2;
    _downCX =  _center.x + _w/2;
    _downCY = _center.y + _h/2;
    _maze.assign(_height, string(_width, '#'));
}

void mazeGenerator::carvePath(int x, int y)
{
    stack<Pos> _s;
    _s.push({x, y});
    _maze[y][x] = '.';
    _start = {x, y};

    random_device rd;
    mt19937 g(rd());

    while (!_s.empty()) {
        Pos _current = _s.top();

        vector<Pos> _neighbors;
        vector<Pos> dirs = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};

        for (auto& d : dirs) {
            int nx = _current.x + d.x;
            int ny = _current.y + d.y;

            if ((nx > 0 && nx < _width/2 + 1) && (ny > 0 && ny < _height - 1) && _maze[ny][nx] == '#') {
                _neighbors.push_back({nx, ny});
            }
        }
        if (!_neighbors.empty()) {
            shuffle(_neighbors.begin(), _neighbors.end(), g);
            Pos next = _neighbors[0];

            _maze[_current.y + (next.y - _current.y)/2][_current.x + (next.x - _current.x)/2] = '.';
            _maze[next.y][next.x] = '.';

            _s.push(next);
        } else {
            _s.pop();
        } 
    }
}

bool mazeGenerator::isInGhostHouse(int x, int y)
{
    return (x == _upCX && x == _downCX &&
            y == _upCY && y == _downCY);
}

bool mazeGenerator::isBorder(int x, int y)
{
    return (x == 0 || x == _width - 1 ||
            y == 0 || y == _height - 1);
}

void mazeGenerator::removeDeadEnds()
{
    for (int y = 1; y < _height - 1; y++) {
        for (int x = 1; x < _width - 1; x++) {
            if (_maze[y][x] == '.') {
                int walls = 0;
                Pos _wallToBreak;
                if (_maze[y + 1][x] == '#' &&
                    !(isInGhostHouse(x, y + 1))) {
                    walls += 1;
                    _wallToBreak = {x, y + 1};
                }
                if (_maze[y - 1][x] == '#' &&
                    !(isInGhostHouse(x, y + 1))) {
                    walls += 1;
                    _wallToBreak = {x, y - 1};
                }
                if (_maze[y][x + 1] == '#' &&
                    !(isInGhostHouse(x, y + 1))) {
                    walls += 1;
                    _wallToBreak = {x + 1, y};
                }
                if (_maze[y][x - 1] == '#' &&
                    !(isInGhostHouse(x, y + 1))) {
                    walls += 1;
                    _wallToBreak = {x - 1, y};
                }
                if (walls >= 3) {
                    _maze[_wallToBreak.y][_wallToBreak.x] = '.';
                }
            }
            if (x == _center.x && !(isInGhostHouse(x, y))) {
                _maze[y][x] = '.';
            }
        }
    }
}

void mazeGenerator::applySymmetry() {
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            _maze[y][_width - 1 - x] = _maze[y][x];
        }
    }
    _maze[_start.y][0] = 'G';
}

void mazeGenerator::generate(void)
{
    this->carvePath(1, 1);
    this->removeDeadEnds();
    this->createGhostHouse();
    this->applySymmetry();
}

vector<string> mazeGenerator::getMaze(void)
{
    return this->_maze;
}

void mazeGenerator::createGhostHouse(void)
{
    for (int y = _upCY; y <= _downCY; y++) {
        for (int x = _upCX; x <= _downCX; x++) {
            if (y == _upCY || y == _downCY
                || x == _upCX || x == _downCX)
            {
                _maze[y][x] = '#';
            } else {
                _maze[y][x] = ' ';
            }
            if ((y == _upCY + 1 || y == _downCY - 1)
                && (x == _upCX + 1 || x == _downCX - 1))
            {
                _maze[y][x] = 'E';        
            }
        }
    }
    _maze[_upCY][_center.x] = '_';
}
