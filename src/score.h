#ifndef SCORE_H
#define SCORE_H

#include "ball.h"
#include "SDL2/SDL.h"
#include <renderer1.h>


class PlayerScore {
    public:
        PlayerScore(Vec2 position, SDL_Renderer* renderer);
        ~PlayerScore();

        void Draw();

        SDL_Renderer* renderer;
        SDL_Surface* surface{};
        SDL_Texture* texture{};
        SDL_Rect rect{};
};

#endif