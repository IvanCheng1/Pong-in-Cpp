#ifndef PADDLE_H
#define PADDLE_H

#include "SDL2/SDL.h"

class Vec2
{
public:
    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2 operator+(Vec2 const &other);
    Vec2 &operator+=(Vec2 const &other);
    Vec2 operator*(float other);

    float x;
    float y;
};

class Paddle
{
public:
    const int Paddle_w = 10;
    const int Paddle_h = 100;

    Paddle(float x, std::size_t screen_height) : position(Vec2(x, (screen_height / 2.0f) - (Paddle_h / 2.0f)))
    {
        screen_h = screen_height;
        rect.x = static_cast<int>(position.x);
        rect.y = static_cast<int>(position.y);
        rect.w = Paddle_w;
        rect.h = Paddle_h;
    }

    void Update(float dt);
    void Draw(SDL_Renderer *renderer);

    Vec2 position;
    Vec2 velocity;
    SDL_Rect rect{};
    std::size_t screen_h;
    float Paddle_speed = 1;
    int score{0};
};

#endif