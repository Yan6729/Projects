#ifndef LIBMANAGER_HPP_
#define LIBMANAGER_HPP_

#include "DLLoader.hpp"
#include "graphics/IGraphics.hpp"
#include "games/IGame.hpp"

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace Arcade {

template <typename T>
using LibPtr = std::unique_ptr<T, std::function<void(T *)>>;

class LibManager {
public:
    LibManager() = default;

    void scanLibs(const std::string &libDir = "./lib");

    bool isGraphicLib(const std::string &path) const;
    bool isGameLib   (const std::string &path) const;

    const std::vector<std::string> &graphicLibs() const { return _graphicLibs; }
    const std::vector<std::string> &gameLibs()    const { return _gameLibs; }

    LibPtr<IGraphics> loadGraphics(const std::string &path);
    LibPtr<IGame>     loadGame    (const std::string &path);

    static std::string nextIn(const std::vector<std::string> &list,
                              const std::string &current);

private:
    std::vector<std::string> _graphicLibs;
    std::vector<std::string> _gameLibs;

    std::vector<std::shared_ptr<DLLoader>> _loaders;
};

}

#endif
