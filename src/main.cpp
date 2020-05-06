#include "renderer.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "controller.h"
#include "game.h"

// https://austinmorlan.com/posts/pong_clone/

int main()
{
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{1280};
    constexpr std::size_t kScreenHeight{720};

    Renderer renderer(kScreenWidth, kScreenHeight);
    Controller controller;
    Game game(kScreenWidth, kScreenHeight);
    game.Run(controller, renderer, kMsPerFrame, kScreenWidth, kScreenHeight);

    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    return 0;
}