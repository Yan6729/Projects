/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** NcurseDisplay
*/

#include <ncurses.h>
#include <vector>
#include <string>
#include "../../include/IModule.hpp"
#include "../../include/IDisplay.hpp"
#include "../../include/displays/NcurseDisplay.hpp"
#include "../../include/MonitorCore.hpp"
#include "../../include/displays/SfmlDisplay.hpp"
#include <sstream>
#include <cstdlib>

using namespace Krell;

NcursesDisplay::NcursesDisplay() {}
NcursesDisplay::~NcursesDisplay() {}

void NcursesDisplay::slide()
{
    Krell::MonitorCore core;

    int count = getCpuCount();

    for (int a = 0; a < count; a++) {
         core.addModule(new Krell::CpuInfo(std::to_string(a)));
    }

    core.addModule(new Krell::RamModule());
    core.addModule(new Krell::Battery());
    core.addModule(new Krell::Network());
    core.addModule(new Krell::DiskModule());
    core.addModule(new Krell::HostUserModule());
    core.addModule(new Krell::OSKernelModule());
    core.addModule(new Krell::DateTimeModule());
    core.addModule(new Krell::ProcessModule());
    core.setDisplay(new Krell::SfmlDisplay);
    core.run();
}

void NcursesDisplay::init()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(0);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
    }
}

void NcursesDisplay::stop()
{
    endwin();
}

void NcursesDisplay::Events()
{
    int ch = getch();
    if (ch == 'q' || ch == 'Q') {
        stop();
        std::exit(0);
    } else if (ch == 's' || ch == 'S') {
        stop();
        slide();
        std::exit(0);
    } else if(ch == KEY_RESIZE) {
    }
}

void NcursesDisplay::drawBox(int y, int x, int h, int w, const std::string& title)
{
    if (y < 0 || x < 0 || y + h >= LINES || x + w >= COLS) return;

    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y, x + w, ACS_URCORNER);
    mvaddch(y + h, x, ACS_LLCORNER);
    mvaddch(y + h, x + w, ACS_LRCORNER);

    for (int i = 1; i < w; ++i) {
        mvaddch(y, x + i, ACS_HLINE);
        mvaddch(y + h, x + i, ACS_HLINE);
    }
    for (int i = 1; i < h; ++i) {
        mvaddch(y + i, x, ACS_VLINE);
        mvaddch(y + i, x + w, ACS_VLINE);
    }

    mvprintw(y, x + 2, "[ %s ]", title.c_str());
}

void NcursesDisplay::drawBar(int y, int x, int w, float percent)
{
    if (percent < 0.f) percent = 0.f;
    if (percent > 1.f) percent = 1.f;

    int filled = static_cast<int>(percent * w);
    int color = (percent < 0.5f) ? 1 : (percent < 0.8f ? 2 : 3);

    attron(COLOR_PAIR(color));
    for (int i = 0; i < w; ++i) {
        mvaddch(y, x + i, (i < filled) ? '|' : '.');
    }
    attroff(COLOR_PAIR(color));
}

float NcursesDisplay::parseStatLineUsage(const std::string &statLine)
{
    std::stringstream ss(statLine);
    long user = 0, nice = 0, system = 0, idle = 0;
    ss >> user >> nice >> system >> idle;
    long total = user + nice + system + idle;
    if (total <= 0) return 0.f;
    return 1.0f - (float)idle / (float)total;
}

int NcursesDisplay::drawBattery(int y, const IModule* m)
{
    auto data = m->getData();
    int height = 4;
    int width = std::max(20, COLS - 6);
    if (y + height >= LINES) return y;

    drawBox(y, 2, height, width, "Battery Info");

    auto it = data.find("capacity");
    std::string cap = (it != data.end()) ? it->second : "0";
    float percent = 0.f;
    try { percent = std::stof(cap) / 100.0f; } catch(...) { percent = 0.f; }

    drawBar(y + 2, 4, std::min(40, width - 10), percent);
    mvprintw(y + 2, 6 + std::min(40, width - 10), " %s%%", cap.c_str());

    return y + height + 1;
}

int NcursesDisplay::drawCPU(int y, const std::vector<IModule*>& modules)
{
    int cpuCount = 0;
    for (auto* m : modules)
        if (m->getName().rfind("cpu", 0) == 0) ++cpuCount;

    if (cpuCount == 0) return y;

    int height = cpuCount + 3;
    int width = COLS - 6;
    if (y + height >= LINES) return y;

    drawBox(y, 2, height, width, "CPU Info");

    int line = y + 2;
    for (auto* m : modules) {
        if (m->getName().rfind("cpu", 0) != 0) continue;

        auto data = m->getData();
        float usage = 0.f;
        auto it = data.find("stat line");
        if (it != data.end()) usage = parseStatLineUsage(it->second);

        std::string coreLabel = "Core " + m->getName().substr(3);
        mvprintw(line, 4, "%s", coreLabel.c_str());

        int barW = std::min(50, std::max(10, width - 30));
        drawBar(line, 18, barW, usage);

        int pctX = 18 + barW + 2;
        if (pctX + 6 < 2 + width)
            mvprintw(line, pctX, "%3d%%", static_cast<int>(usage * 100));

        ++line;
        if (line >= LINES - 3) break;
    }

    return y + height + 1;
}

int NcursesDisplay::drawRAM(int y, const IModule* m)
{
    auto d = m->getData();

    float used = std::stof(d.at("MemUsed"));
    float total = std::stof(d.at("MemTotal"));
    float percent = used / total;

    int height = 4;
    int width = COLS - 6;

    drawBox(y, 2, height, width, "RAM");

    drawBar(y + 2, 6, width - 20, percent);
    mvprintw(y + 2, width - 10, "%d%%", int(percent * 100));

    return y + height + 1;
}

int NcursesDisplay::drawNetwork(int y, const IModule* m)
{
    auto data = m->getData();
    int height = std::max(3, static_cast<int>(data.size()) + 2);
    int width = COLS - 6;
    if (y + height >= LINES) return y;

    drawBox(y, 2, height, width, "Network Info");

    int line = y + 2;
    for (const auto& kv : data) {
        if (line >= LINES - 3) break;
        mvprintw(line++, 4, "%s : %s", kv.first.c_str(), kv.second.c_str());
    }
    return y + height + 1;
}

int NcursesDisplay::drawTextBlock(int y, const IModule* m)
{
    auto data = m->getData();
    int height = std::max(3, static_cast<int>(data.size()) + 2);
    int width = COLS - 6;
    if (y + height >= LINES) return y;

    drawBox(y, 2, height, width, m->getName());

    int line = y + 2;
    for (const auto& kv : data) {
        if (line >= LINES - 3) break;
        mvprintw(line++, 4, "%s : %s", kv.first.c_str(), kv.second.c_str());
    }
    return y + height + 1;
}

void NcursesDisplay::display_modules(const std::vector<IModule*>& modules)
{
    clear();
    int y = 1;

    for (auto *m : modules) {
        if (m->getName() == "Host / user"
         || m->getName() == "OS / Kernel"
         || m->getName() == "Date / Time") {
            y = drawTextBlock(y, m);
        }
    }

    y = drawCPU(y, modules);

    for (auto *m : modules) {
        if (m->getName() == "Ram module")
            y = drawRAM(y, m);
    }

    for (auto *m : modules) {
        if (m->getName() == "Network")
            y = drawNetwork(y, m);
    }

    for (auto *m : modules) {
        if (m->getName() == "Battery")
            y = drawBattery(y, m);
    }

    mvprintw(LINES - 2, 2, "Press Q to quit");
    refresh();
    Events();
}