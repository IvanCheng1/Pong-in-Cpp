#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL2/SDL.h"
#include "ball.h"

class Renderer
{
public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height);
    ~Renderer();

    void Render(const std::size_t screen_width, const std::size_t screen_height, Ball &ball, Paddle &paddleOne, Paddle &paddleTwo, std::size_t frame_duration);
    void UpdateWindowTitle(std::string score, int fps);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    int count = 0;
};

#endif