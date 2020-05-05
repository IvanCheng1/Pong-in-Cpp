#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"

class Vec2 {
    public:
        Vec2() : _x(0.0f), _y(0.0f) {}
        Vec2(float x, float y) : _x(x), _y(y) {}

        Vec2 operator+(Vec2 const& other);

        Vec2& operator+=(Vec2 const& other);

        Vec2 operator*(float other);

        float get_x() const { return _x; }
        float get_y() const { return _y; }

    private:
        float _x;
        float _y;

};

class Ball {
    public:
        const int BALL_WIDTH = 15;
        const int BALL_HEIGHT = 15;

        // Ball(const std::size_t screen_width, const std::size_t screen_height)
        //   : grid_width(grid_width),
        //     grid_height(grid_height),
        //     head_x(grid_width / 2),
        //     head_y(grid_height / 2) {}



        Ball(Vec2 position) : position(position)
        {
            rect.x = static_cast<int>(position.get_x());
            rect.y = static_cast<int>(position.get_y());
            rect.w = BALL_WIDTH;
            rect.h = BALL_HEIGHT;
        }

        void Draw(SDL_Renderer* renderer);

        Vec2 position;
        SDL_Rect rect{};
    
};


#endif