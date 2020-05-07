#ifndef BALL_H
#define BALL_H

#include "SDL2/SDL.h"
#include <random>
#include "paddle.h"

enum class CollisionType
{
    None,
    Top,
    Middle,
    Bottom,
    Left,
    Right
};

struct Contact
{
    CollisionType type;
    float penetration;
};

class Ball
{
public:
    Ball(const std::size_t screen_width, const std::size_t screen_height);

    void Update(float dt);
    void Draw(SDL_Renderer *renderer);
    void PaddleCollide(Contact const &contact);
    Contact PaddleCollision(Paddle const &paddle);
    void WallCollide(Contact const &contact);
    Contact WallCollision();
    void Reset();
    void CollisionCheck(Paddle &paddleOne, Paddle &paddleTwo, int &count);
    void DelayStart(Paddle &paddleOne, Paddle &paddleTwo, int &count);
    void Simulate(Paddle &paddle);

    const int Ball_w = 15;
    const int Ball_h = 15;
    Vec2 position;
    Vec2 startPosition;
    Vec2 velocity{0, 0};
    Vec2 p_velocity;
    SDL_Rect rect{};
    float Ball_s{1};
    std::size_t screen_h;
    std::size_t screen_w;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_real_distribution<float> random_hit;
    std::uniform_real_distribution<float> random_y_hit;
    std::uniform_real_distribution<float> random_speed;
    std::uniform_real_distribution<float> random_y_start;
};

#endif