#include <iostream>
#include "paddle.h"

/*---------------- Vec2 ----------------*/

Vec2 Vec2::operator+(Vec2 const &other)
{
    return Vec2(x + other.x, y + other.y);
}

Vec2 &Vec2::operator+=(Vec2 const &other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vec2 Vec2::operator*(float other)
{
    return Vec2(x * other, y * other);
}

/*---------------- Paddle ----------------*/

void Paddle::Update(float dt)
{
    position += velocity * dt;
    if (position.y < 0)
    {
        position.y = 0;
    }
    else if (position.y > (screen_h - Paddle_h))
    {
        position.y = screen_h - Paddle_h;
    }
}

void Paddle::Draw(SDL_Renderer *renderer)
{
    rect.y = static_cast<int>(position.y);

    SDL_RenderFillRect(renderer, &rect);
}
