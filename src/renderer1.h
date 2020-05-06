#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL2/SDL.h"
#include "ball.h"
#include "score.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(const std::size_t screen_width, const std::size_t screen_height, Ball ball, Paddle &paddleOne, Paddle &paddleTwo);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;

};

#endif