#include "../include/Pch.hpp"
#include "../include/Gfx.hpp"

void setUp(std::pair<bool, bool> displayFlags);
void quit();
std::pair<bool, bool> args(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    auto displayFlags = args(argc, argv);
    setUp(displayFlags);

    quit();
    return 0;
}

void setUp(std::pair<bool, bool> displayFlags) {
    Gfx::getInstance()->setGfxContext(displayFlags.first, displayFlags.second);
    Gfx::getInstance()->showMouseCursor(false);
}

void quit() {
   delete Gfx::getInstance();
}

std::pair<bool, bool> args(int argc, char* argv[]) {
    bool fullscreen = false;
    bool vsync = false;

    for (short i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--fullscreen") == 0) {
            fullscreen = true;
        }
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--vsync") == 0) {
            vsync = true;
        }
    }

    return std::make_pair(fullscreen, vsync);
}
