/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** pacmanGhost
*/

#include "../../include/games/pacmanGame.hpp"
using namespace Arcade;

vector<vector<bool>> pacmanGame::buidWallGrid() const
{
    vector<vector<bool>> map(_h, vector<bool>(_w, false));

    for (auto& ent : _entities) {
        if (ent.symbol == '#')
            map[ent.y][ent.x] = true;
    }
    return map;
}

pos pacmanGame::goAhead(pos start, pos target, const vector<vector<bool>>& wall, pos retour)
{
    if (start == target)
       return start;
    const vector<pos> directions = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
    vector<vector<pos>> parent(_h, vector<pos>(_w, {-1, -1}));

    queue<pos> _q;
    _q.push(start);
    parent[start.y][start.x] = start;

    while(!_q.empty()) {
        pos _c = _q.front();
        _q.pop();
        if (_c.x == target.x && _c.y == target.y) {
            pos current = target;
            while (parent[current.y][current.x] != start)
                current = parent[current.y][current.x];
            return current;
        }
        for (auto& direction : directions) {
            pos n = {_c.x + direction.x, _c.y + direction.y };

            if (n.x < 0 || n.y < 0 || n.x >= (int)_w || n.y >= (int)_h)
                continue;
            if (wall[n.y][n.x])
                continue;
            if (parent[n.y][n.x].x != -1)
                continue;
            if (n == retour)
                continue;
            parent[n.y][n.x] = _c;
            _q.push(n);
        }
    }
    if (retour.x != -1)
        return goAhead(start, target, wall, {-1, -1});
    return start;
}

pos pacmanGame::setTarget(const GhostInfo &ghost, pos ghostPos, pos pacman)
{
    pos target = pacman;

    if (_eatghost) {
        target = {
            (2 * ghostPos.x - pacman.x),
            (2 * ghostPos.y - pacman.y)
        };
    } else if (ghost._name == "blinky") {
        target = pacman;
    } else if (ghost._name == "pinky") {
        target = pacman;
        if (_direction == "up")
            target.y -= 4;
        if (_direction == "down")
            target.y += 4;
        if (_direction == "left")
            target.x -= 4;
        if (_direction == "right")
            target.x += 4;
    } else if (ghost._name == "inky") {
        pos pivot = pacman;
        if (_direction == "up")
            pivot.y -= 2;
        if (_direction == "down")
            pivot.y += 2;
        if (_direction == "left")
            pivot.x -= 2;
        if (_direction == "right")
            pivot.x += 2;
        auto blinkyIt = find_if(_ghosts.begin(), _ghosts.end(),
            [](const GhostInfo &g){ return g._name == "blinky"; });
        pos blinkyPos = {
            _entities[blinkyIt->_entityIdx].x,
            _entities[blinkyIt->_entityIdx].y
        };
        target = {
            pivot.x + (pivot.x - blinkyPos.x),
            pivot.y + (pivot.y - blinkyPos.y)
        };
    } else {
        int dist = abs(ghostPos.x - pacman.x)
                 + abs(ghostPos.y - pacman.y);
        target = (dist > 8) ? pacman : pos{0, (int)_h - 1};
    }
    target.x = max(0, min(target.x, (int)_w - 1));
    target.y = max(0, min(target.y, (int)_h - 1));
    return target;
}

void pacmanGame::moveGhosts(void)
{
    size_t pacmanIndex = getEntity('G', Color::YELLOW);
    pos pacman = { _entities[pacmanIndex].x, _entities[pacmanIndex].y };
    size_t exitIndex = getEntity('_', Color::GRAY);
    pos exitPos = { _entities[exitIndex].x, _entities[exitIndex].y };
    auto walls = buidWallGrid();

    for (auto &ghost : _ghosts) {
        Entity &entity = _entities[ghost._entityIdx];
        pos ghostPos = {entity.x, entity.y};

        ghost.speed += 1;
        if (ghost.speed < 2)
            continue;
        ghost.speed = 0;
        pos retour = {-1, -1};
        if (!ghost._prevDir.empty()) {
            if (ghost._prevDir == "right")
                retour = {ghostPos.x - 1, ghostPos.y};
            if (ghost._prevDir == "left")
                retour = {ghostPos.x + 1, ghostPos.y};
            if (ghost._prevDir == "up")
                retour = {ghostPos.x, ghostPos.y + 1};
            if (ghost._prevDir == "down")
                retour = {ghostPos.x, ghostPos.y - 1};
        }
        if (!ghost._hasLeft) {
            if (ghostPos == exitPos) {
                ghost._hasLeft = true;
            } else {
                pos next = goAhead(ghostPos, exitPos, walls, retour);
                entity.x = next.x;
                entity.y = next.y;
                int dx = next.x - ghostPos.x;
                int dy = next.y - ghostPos.y;
                if (dx ==  1)
                    ghost._prevDir = "right";
                else if (dx == -1)
                    ghost._prevDir = "left";
                else if (dy ==  1)
                    ghost._prevDir = "down";
                else if (dy == -1)
                    ghost._prevDir = "up";
                continue;
            }
        }
        if (_eatghost)
            retour = {-1, -1};
        pos target = setTarget(ghost, ghostPos, pacman);
        pos next = goAhead(ghostPos, target, walls, retour);
        entity.x = next.x;
        entity.y = next.y;

        int dx = next.x - ghostPos.x;
        int dy = next.y - ghostPos.y;
        if (dx ==  1)
            ghost._prevDir = "right";
        else if (dx == -1)
            ghost._prevDir = "left";
        else if (dy ==  1)
            ghost._prevDir = "down";
        else if (dy == -1)
            ghost._prevDir = "up";
        if (next == pacman && !_eatghost)
            _isGameOver = true;
    }
}