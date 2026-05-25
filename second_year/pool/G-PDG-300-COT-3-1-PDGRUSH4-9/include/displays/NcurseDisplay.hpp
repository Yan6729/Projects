/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** NcurseDisplay
*/
#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include "../IModule.hpp"
#include "../IDisplay.hpp"

namespace Krell {

class NcursesDisplay : public IDisplay {
public:
    NcursesDisplay();
    ~NcursesDisplay();

    void init() override;
    void stop() override;
    void Events() override;
    void display_modules(const std::vector<IModule*>& modules) override;

private:
    void drawBox(int y, int x, int h, int w, const std::string& title);
    void drawBar(int y, int x, int w, float percent);

    int drawBattery(int y, const IModule* m);
    int drawCPU(int y, const std::vector<IModule*>& modules);
    int drawRAM(int y, const IModule* m);
    int drawDateTime(int y, const std::vector<IModule*>& modules);
    int drawNetwork(int y, const IModule* m);
    int drawTextBlock(int y, const IModule* m);
    void slide();

    float parseStatLineUsage(const std::string &statLine);
};

}
