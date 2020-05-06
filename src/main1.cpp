#include "renderer1.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "controller1.h"
#include "game1.h"
#include <thread>


int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{1280};
    constexpr std::size_t kScreenHeight{720};

    Renderer renderer(kScreenWidth, kScreenHeight);
    Controller controller;
    Game game(kScreenWidth, kScreenHeight);
    game.Run(controller, renderer, kMsPerFrame, kScreenWidth, kScreenHeight);


    //   Controller controller;
    //   Game game(kGridWidth, kGridHeight);
    //   game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    return 0;
}