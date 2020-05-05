#include "renderer1.h"
#include <iostream>
#include "SDL.h"
#include "controller1.h"
#include "game1.h"
#include <thread>

// #include "controller.h"
// #include "game.h"

// const int WINDOW_WIDTH = 1280;
// const int WINDOW_HEIGHT = 720;

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{1280};
    constexpr std::size_t kScreenHeight{720};

    Renderer renderer(kScreenWidth, kScreenHeight);
    Controller controller;
    Game game;
    game.Run(controller, renderer, kMsPerFrame);



    // bool running = true;
    
    // while (running)
    // {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //     SDL_Event event;
    //     while (SDL_PollEvent(&event))
    //     {
    //         if (event.type == SDL_QUIT)
    //         {
    //             running = false;
    //         }
    //         else if (event.type == SDL_KEYDOWN)
    //         {
    //             if (event.key.keysym.sym == SDLK_ESCAPE)
    //             {
    //                 running = false;
    //             }
    //         }
    //     }

    //     // Clear the window to black
    //     renderer.Render();
    // }

    
   
//    renderer.Render();


    //   Controller controller;
    //   Game game(kGridWidth, kGridHeight);
    //   game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    return 0;
}