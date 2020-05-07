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

Paddle::Paddle(float x, std::size_t screen_height)
    : position(Vec2(x, (screen_height / 2.0f) - (Paddle_h / 2.0f)))
{
    screen_h = screen_height;
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
    rect.w = Paddle_w;
    rect.h = Paddle_h;
}

void Paddle::Update(float dt)
{
    this->rect.h = this->Paddle_h;
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

void Paddle::SizeUpdate(Paddle otherPaddle) {
    
    int scoreDif = this->score - otherPaddle.score;
    if (scoreDif > 3) {
        if (this->Paddle_h > 60) {
            this->Paddle_h = this->Paddle_h * 0.97;
        }
    } else if (scoreDif < -3) {
        if (this->Paddle_h < 160) {
            this->Paddle_h = this->Paddle_h * 1.05;
        }
    } else if (scoreDif < 3 && scoreDif > -3) {
        if (this->Paddle_h > 110) {
            this->Paddle_h = this->Paddle_h * 0.9;
        } else if (this->Paddle_h < 90) {
            this->Paddle_h = this->Paddle_h * 1.1;
        } else if (this->Paddle_h == 100) {
            return;
        } else if (this->Paddle_h > 90 && this->Paddle_h < 110) {
            this->Paddle_h = 100;
        } 
    }
}
