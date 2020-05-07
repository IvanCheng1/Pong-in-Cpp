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
    int Paddle_h = 100;

    Paddle(float x, std::size_t screen_height);

    void Update(float dt);
    void Draw(SDL_Renderer *renderer);
    void SizeUpdate(Paddle otherPaddle);

    Vec2 position;
    Vec2 velocity;
    SDL_Rect rect{};
    std::size_t screen_h;
    float Paddle_speed = 1;
    int score{0};
};

#endif