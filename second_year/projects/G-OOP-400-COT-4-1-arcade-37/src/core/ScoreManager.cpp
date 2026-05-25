#include "../../include/ScoreManager.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>

namespace Arcade {

ScoreManager::ScoreManager(const std::string &filepath)
    : _filepath(filepath)
{
    load();
}

void ScoreManager::load()
{
    std::ifstream file(_filepath);
    if (!file.is_open())
        return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string game, player;
        int score = 0;
        if (ss >> game >> player >> score)
            _scores[game].push_back({player, score});
    }
}

void ScoreManager::save() const
{
    std::ofstream file(_filepath);
    for (const auto &[game, entries] : _scores)
        for (const auto &e : entries)
            file << game << " " << e.player << " " << e.score << "\n";
}

void ScoreManager::addScore(const std::string &gameName,
                            const std::string &player,
                            int score)
{
    _scores[gameName].push_back({player, score});
    save();
}

std::vector<ScoreEntry> ScoreManager::getScores(const std::string &gameName,
                                                int topN) const
{
    auto it = _scores.find(gameName);
    if (it == _scores.end())
        return {};

    auto entries = it->second;
    std::sort(entries.begin(), entries.end(),
        [](const ScoreEntry &a, const ScoreEntry &b) {
            return a.score > b.score;
        });

    if (static_cast<int>(entries.size()) > topN)
        entries.resize(static_cast<std::size_t>(topN));
    return entries;
}

}
