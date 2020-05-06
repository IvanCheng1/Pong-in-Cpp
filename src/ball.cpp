#include <vector>
#include <iostream>
#include "ball.h"


Vec2 Vec2::operator+(Vec2 const& other)  {
    return Vec2(x + other.x, y + other.y);
}

Vec2& Vec2::operator+=(Vec2 const& other) {
    x += other.x;
    y += other.y;

    return *this;
}

Vec2 Vec2::operator*(float other) {
    return Vec2(x * other, y * other);
}




void Ball::Draw(SDL_Renderer* renderer) {
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);

    SDL_RenderFillRect(renderer, &rect);
}


void Paddle::Update() {
    position += velocity*10;
    if (position.y < 0) {
        position.y = 0;
    } else if (position.y > (screen_h - Paddle_h)) {
        position.y = screen_h - Paddle_h;
    }
}


void Paddle::Draw(SDL_Renderer* renderer) {
    rect.y = static_cast<int>(position.y);

    SDL_RenderFillRect(renderer, &rect);
}