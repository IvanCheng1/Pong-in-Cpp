#ifndef GAME_H
#define GAME_H

// #include <random>
#include "SDL.h"
#include "controller1.h"
#include "renderer1.h"
#include "ball.h"

class Game {
    public:
        // Game(const std::size_t screen_width, const std::size_t screen_height);
        void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration,
             const std::size_t screen_width, const std::size_t screen_height);
        // int GetScore() const;

    private:
        // Ball ball;

        // std::random_device dev;
        // std::mt19937 engine;
        // std::uniform_int_distribution<int> random_w;
        // std::uniform_int_distribution<int> random_h;

    int score{0};


        // void Update();
};

#endif