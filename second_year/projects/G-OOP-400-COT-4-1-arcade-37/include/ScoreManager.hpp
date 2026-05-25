#ifndef SCOREMANAGER_HPP_
#define SCOREMANAGER_HPP_

#include <map>
#include <string>
#include <vector>

namespace Arcade {

struct ScoreEntry {
    std::string player;
    int         score;
};

class ScoreManager {
public:
    explicit ScoreManager(const std::string &filepath = "./scores.txt");

    void load();
    void save() const;

    void addScore(const std::string &gameName,
                  const std::string &player,
                  int score);

    std::vector<ScoreEntry> getScores(const std::string &gameName,
                                      int topN = 5) const;

private:
    std::string _filepath;
    std::map<std::string, std::vector<ScoreEntry>> _scores;
};

}

#endif
