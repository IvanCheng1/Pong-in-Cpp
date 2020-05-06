#include <renderer1.h>
#include <string>
#include <iostream>
#include "score.h"
#include "ball.h"


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }


  // Create Window
  sdl_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  

  std::cout << "SDL init complete" << std::endl;
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
  std::cout << "SDL Destroyed" << std::endl;
}

void Renderer::Render(const std::size_t screen_width, const std::size_t screen_height, Ball ball, Paddle &paddleOne, Paddle &paddleTwo) {
    // Clear screen to black
    SDL_SetRenderDrawColor(sdl_renderer, 0x0, 0x0, 0x0, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // draw the white line in the middle
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF); // white
    for (int y = 0; y < screen_height; y++) {
        if (y % 5) {
            SDL_RenderDrawPoint(sdl_renderer, screen_width / 2, y);
        }
    }
    // draw ball
    ball.Draw(sdl_renderer);

    // draw paddles
    paddleOne.Draw(sdl_renderer);
    paddleTwo.Draw(sdl_renderer);
    
    paddleOne.Update();
    paddleTwo.Update();

 
    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Pong Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}