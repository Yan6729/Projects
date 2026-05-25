#include "../../include/LibManager.hpp"

#include <filesystem>
#include <stdexcept>

namespace Arcade {

void LibManager::scanLibs(const std::string &libDir)
{
    _graphicLibs.clear();
    _gameLibs.clear();

    if (!std::filesystem::exists(libDir))
        return;

    for (const auto &entry : std::filesystem::directory_iterator(libDir)) {
        if (entry.path().extension() != ".so")
            continue;
        const std::string p = entry.path().string();
        if (isGraphicLib(p))
            _graphicLibs.push_back(p);
        else if (isGameLib(p))
            _gameLibs.push_back(p);
    }
}

bool LibManager::isGraphicLib(const std::string &path) const
{
    try {
        DLLoader loader(path);
        loader.getSymbol<void *>("createGraphics");
        return true;
    } catch (...) {
        return false;
    }
}

bool LibManager::isGameLib(const std::string &path) const
{
    try {
        DLLoader loader(path);
        loader.getSymbol<void *>("createGame");
        return true;
    } catch (...) {
        return false;
    }
}

LibPtr<IGraphics> LibManager::loadGraphics(const std::string &path)
{
    auto loader  = std::make_shared<DLLoader>(path);
    auto creator = loader->getSymbol<IGraphics *(*)()>("createGraphics");
    auto deleter = loader->getSymbol<void (*)(IGraphics *)>("destroyGraphics");

    _loaders.push_back(loader);
    return LibPtr<IGraphics>(creator(), [deleter](IGraphics *p) { deleter(p); });
}

LibPtr<IGame> LibManager::loadGame(const std::string &path)
{
    auto loader  = std::make_shared<DLLoader>(path);
    auto creator = loader->getSymbol<IGame *(*)()>("createGame");
    auto deleter = loader->getSymbol<void (*)(IGame *)>("destroyGame");

    _loaders.push_back(loader);
    return LibPtr<IGame>(creator(),
        [deleter](IGame *p) { deleter(p); });
}

std::string LibManager::nextIn(const std::vector<std::string> &list,
                               const std::string &current)
{
    if (list.empty())
        return "";
    for (std::size_t i = 0; i < list.size(); ++i)
        if (list[i] == current)
            return list[(i + 1) % list.size()];
    return list[0];
}

}
