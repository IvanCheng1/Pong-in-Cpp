#include "game1.h"
#include "ball.h"
#include <iostream>
#include "SDL.h"

const int BALL_WIDTH = 15;
const int BALL_HEIGHT = 15;

// Game::Game(const std::size_t screen_width, const std::size_t screen_height) {
//     Ball ball(
//         Vec2((screen_width / 2.0f) - (BALL_WIDTH / 2.0f),
// 	(screen_height / 2.0f) - (BALL_HEIGHT / 2.0f)));
// }
      



void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration, 
               const std::size_t screen_width, const std::size_t screen_height) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  Ball ball(
    Vec2((screen_width / 2.0f) - (BALL_WIDTH / 2.0f),
	(screen_height / 2.0f) - (BALL_HEIGHT / 2.0f)));

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running);
    // Update();
    renderer.Render(screen_width, screen_height, ball);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


// void Game::Update() {
//   if (!snake.alive) return;

//   snake.Update();

//   int new_x = static_cast<int>(snake.head_x);
//   int new_y = static_cast<int>(snake.head_y);

//   // Check if there's food over here
//   if (food.x == new_x && food.y == new_y) {
//     score++;
//     PlaceFood();
//     // Grow snake and increase speed.
//     snake.GrowBody();
//     snake.speed += 0.02;
//   }
// }

// int Game::GetScore() const { return score; }
