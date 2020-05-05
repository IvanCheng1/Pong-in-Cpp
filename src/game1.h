#ifndef GAME_H
#define GAME_H

// #include <random>
#include "SDL.h"
#include "controller1.h"
#include "renderer1.h"
// #include "snake.h"

class Game {
 public:
  void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
  // int GetScore() const;

 private:
  // Snake snake;

  // std::random_device dev;
  // std::mt19937 engine;
  // std::uniform_int_distribution<int> random_w;
  // std::uniform_int_distribution<int> random_h;

  int score{0};


  // void Update();
};

#endif