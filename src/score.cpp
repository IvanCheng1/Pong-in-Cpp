#include <vector>
#include "score.h"
#include "SDL2/SDL.h"
#include <iostream>

PlayerScore::PlayerScore(Vec2 position, SDL_Renderer* renderer)
{
    std::cout << "1" << std::endl;
    // surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
    std::cout << "2" << std::endl;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    std::cout << "3" << std::endl;

    int width, height;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    std::cout << "4" << std::endl;

    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
    rect.w = width;
    rect.h = height;
    std::cout << "Player score init complete" << std::endl;

}


PlayerScore::~PlayerScore()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void PlayerScore::Draw()
{
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

