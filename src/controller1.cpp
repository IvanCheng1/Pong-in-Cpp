#include "controller1.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "ball.h"


const Uint8 *keys = SDL_GetKeyboardState(NULL);

void Controller::HandleInput(bool &running, Paddle &paddleOne, Paddle &paddleTwo) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_UP:
                    paddleTwo.velocity.y = -paddleTwo.Paddle_speed;
                    break;
                case SDLK_DOWN:
                    paddleTwo.velocity.y = paddleTwo.Paddle_speed;
                    break;
                case SDLK_w:
                    paddleOne.velocity.y = -paddleOne.Paddle_speed;
                    break;
                case SDLK_s:
                    paddleOne.velocity.y = paddleOne.Paddle_speed;
                    break;

            }
        } else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    if (keys[SDL_SCANCODE_DOWN]) {
                        paddleTwo.velocity.y = paddleTwo.Paddle_speed;
                    } else {paddleTwo.velocity.y = 0;}
                    break;
                case SDLK_DOWN:
                    if (keys[SDL_SCANCODE_UP]) {
                        paddleTwo.velocity.y = -paddleTwo.Paddle_speed;
                    } else {paddleTwo.velocity.y = 0;}
                    break;
                case SDLK_w:
                    if (keys[SDL_SCANCODE_S]) {
                        paddleOne.velocity.y = paddleOne.Paddle_speed;
                    } else {paddleOne.velocity.y = 0;}
                    break;
                case SDLK_s:
                    if (keys[SDL_SCANCODE_W]) {
                        paddleOne.velocity.y = -paddleOne.Paddle_speed;
                    } else {paddleOne.velocity.y = 0;}
                    break;

            }
        }
  }
}