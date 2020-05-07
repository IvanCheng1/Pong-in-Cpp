#include <renderer.h>
#include <string>
#include <iostream>
#include "ball.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window)
    {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer)
    {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(const std::size_t screen_width, const std::size_t screen_height, Ball &ball, Paddle &paddleOne, Paddle &paddleTwo, std::size_t target_frame_duration)
{
    // Clear screen to black
    SDL_SetRenderDrawColor(sdl_renderer, 0x0, 0x0, 0x0, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // draw the white line in the middle
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF); // white
    for (int y = 0; y < screen_height; y++)
    {
        if (y % 5)
        {
            SDL_RenderDrawPoint(sdl_renderer, screen_width / 2, y);
        }
    }
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0x00, 0xFF); // yellow 
    // draw ball
    ball.Draw(sdl_renderer);

    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF); // white
    // draw paddles
    paddleOne.Draw(sdl_renderer);
    paddleTwo.Draw(sdl_renderer);

    // simulate computer - remove for two players
    ball.Simulate(paddleTwo);

    // update items on screen
    paddleOne.Update(target_frame_duration);
    paddleTwo.Update(target_frame_duration);
    ball.Update(target_frame_duration);

    ball.CollisionCheck(paddleOne, paddleTwo, count);
    ball.DelayStart(paddleOne, paddleTwo, count);
    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(std::string score, int fps)
{
    std::string title{"Pong Score: " + score + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}