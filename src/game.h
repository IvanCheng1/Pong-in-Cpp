#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ball.h"

class Game
{
public:
    Game(const std::size_t screen_width, const std::size_t screen_height);
    void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration,
             const std::size_t screen_width, const std::size_t screen_height);
    std::string GetScore() const;

private:
    Ball ball;
    Paddle paddleOne;
    Paddle paddleTwo;
};

#endif