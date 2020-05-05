#include <vector>
#include "ball.h"


Vec2 Vec2::operator+(Vec2 const& other)  {
    return Vec2(get_x() + other.get_x(), get_y() + other.get_y());
}

Vec2& Vec2::operator+=(Vec2 const& other) {
    _x += other.get_x();
    _y += other.get_y();

    return *this;
}

Vec2 Vec2::operator*(float other) {
    return Vec2(get_x() * other, get_y() * other);
}









void Ball::Draw(SDL_Renderer* renderer) {
    rect.x = static_cast<int>(position.get_x());
    rect.y = static_cast<int>(position.get_y());

    SDL_RenderFillRect(renderer, &rect);
}
