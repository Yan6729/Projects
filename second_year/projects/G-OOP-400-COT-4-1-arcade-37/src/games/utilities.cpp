/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** utilities
*/

#include "../../include/games/IGame.hpp"

int generate_random_number(int start, int end)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(start, end);

    return dis(gen);
}

void move_head(int& x, int& y, string& _direction)
{
    _direction == "right" ? ({
        x += 1;
    }) : _direction == "left" ? ({
        x -= 1;
    }) : _direction == "up" ? ({
        y -= 1;
    }) : ({
        y += 1;
    });
}

vector<string> generate_map(int col, int grid, int ghostnumber)
{
    vector<string> map(col, string(grid, '.'));
    map[0][0] = 'G';

    for (int h = 0; h < col; h++) {
        for (int w = 0; w < grid; w++) {
            if ((rand() % 100) < 30)
                map[h][w] = '#';
        }
    }

    for (int a = 0; a < ghostnumber; a++) {
        int x = rand() % col;
        int y = rand() % grid;

        if (map[x][y] == '.') {
            map[x][y] = 'E';
        } else {
            a--;
        }
    }
    return map;
}

string getAssets(const pair<int, int>& prev, const pair<int, int>& curr, const pair<int, int>& next)
{
    int dx1 = curr.first - prev.first;
    int dy1 = curr.second - prev.second;
    int dx2 = next.first - curr.first;
    int dy2 = next.second - curr.second;

    if (prev.first == curr.first && curr.first == next.first) {
        return "asset/picture/snake/vertical.png";
    }
    else if (prev.second == curr.second && curr.second == next.second) {
        return "asset/picture/snake/horizontal.png";
    }
    else {
        if ((dy1 == 1 && dx2 == 1) || (dx1 == -1 && dy2 == -1)) {
            return "asset/picture/snake/bas_droit.png";
        }
        else if ((dy1 == 1 && dx2 == -1) || (dx1 == 1 && dy2 == -1)) {
            return "asset/picture/snake/bas_gauche.png";
        }
        else if ((dy1 == -1 && dx2 == 1) || (dx1 == -1 && dy2 == 1)) {
            return "asset/picture/snake/haut_droit.png";
        }
        else if ((dy1 == -1 && dx2 == -1) || (dx1 == 1 && dy2 == 1)) {
            return "asset/picture/snake/haut_gauche.png";
        }
    }
    return "";
}

void getTailAssetsByState(vector<Arcade::Entity>& _entities)
{
    auto &tail = _entities.back();
    auto &before = _entities[_entities.size() - 2];
    int dx = tail.x - before.x;
    int dy = tail.y - before.y;

    if (dx == 1)
        tail.sprite = "asset/picture/snake/tail_left.png";
    else if (dx == -1)
        tail.sprite = "asset/picture/snake/tail_right.png";
    else if (dy == 1)
        tail.sprite = "asset/picture/snake/tail_up.png";
    else if (dy == -1)
        tail.sprite = "asset/picture/snake/tail_down.png";
}

string getGrassAssets(int h, int w, int x, int y)
{
    if (y == 0) {
        if (x == 0)
            return "asset/picture/background/grass_left_edgeup.png";
        else if (x == w -1) {
            return "asset/picture/background/grass_right_edgeup.png";
        } else {
            return "asset/picture/background/grass_left.png";
        }
    } else if (y == h - 1) {
        if (x == 0)
            return "asset/picture/background/grass_left_edgedown.png";
        else if (x == w -1) {
            return "asset/picture/background/grass_right_edgedown.png";
        } else {
            return "asset/picture/background/grass_right.png";
        }
    } else if (x == 0) {
        return "asset/picture/background/grass_up.png";
    } else if (x == w - 1) {
        return "asset/picture/background/grass_down.png";
    } else {
        return "asset/picture/background/grass_center.png";
    }
}

Arcade::Entity choosePiece(int a, int x, int y)
{
    if (a % 50 == 0) {
        return { x, y, 'o', Arcade::Color::LIGHT_YELLOW,  "asset/picture/goal/piece1.png"};
    } else if (a % 4 == 0) {
        return { x, y, '.', Arcade::Color::LIGHT_GRAY,  "asset/picture/goal/piece2.png"};
    } else {
        return { x, y, '.', Arcade::Color::BROWN,  "asset/picture/goal/piece3.png"};
    }
}

pair<int, int> spawnFood(const vector<Arcade::Entity>& entities, int maxX, int maxY)
{
    int x, y;
    bool valid = false;

    while (!valid) {
        x = generate_random_number(1, maxX - 1);
        y = generate_random_number(1, maxY - 1);
        valid = true;
        for (const auto& e : entities) {
            if (e.x == x && e.y == y) {
                if (e.symbol == '#' ||
                    e.symbol == '0' ||
                    e.symbol == '@' ||
                    e.symbol == 'a' ||
                    e.symbol == 'b')
                {
                    valid = false;
                    break;
                }
            }
        }
    }
    return { x, y };
}

pair<int, int> generateRandomTarget(const vector<Arcade::Entity>& entities, int maxX, int maxY)
{
    int x, y;
    bool valid = false;

    while (!valid) {
        x = generate_random_number(1, maxX - 1);
        y = generate_random_number(1, maxY - 1);
        valid = true;
        for (const auto& e : entities) {
            if (e.x == x && e.y == y) {
                if (e.symbol == '#' || e.symbol == '_')
                {
                    valid = false;
                    break;
                }
            }
        }
    }
    return { x, y };
}
