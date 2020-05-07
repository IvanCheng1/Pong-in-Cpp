#include <iostream>
#include "ball.h"
#include "paddle.h"
#include <random>

/*---------------- Ball ----------------*/

Ball::Ball(const std::size_t screen_width, const std::size_t screen_height)
    : position(Vec2((screen_width / 2.0f) - (Ball_w / 2.0f),
                    (screen_height / 2.0f) - (Ball_h / 2.0f))),
      engine(dev()),
      random_hit(0.85, 1.15),
      random_speed(0.9, 1.1),
      random_y_hit(-0.1, 0.1),
      random_y_start(0, 1)
{
    startPosition = position;
    screen_h = screen_height;
    screen_w = screen_width;
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
    rect.w = Ball_w;
    rect.h = Ball_h;
}

void Ball::Draw(SDL_Renderer *renderer)
{
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);

    SDL_RenderFillRect(renderer, &rect);
}

void Ball::Update(float dt)
{
    position += velocity * Ball_s * dt;
}

void Ball::PaddleCollide(Contact const &contact)
{
    this->position.x += contact.penetration;
    this->velocity.x = -velocity.x * random_speed(engine);

    if (contact.type == CollisionType::Top)
    {
        this->velocity.y = -0.75f * Ball_s * random_hit(engine);
    }
    else if (contact.type == CollisionType::Bottom)
    {
        this->velocity.y = 0.75f * Ball_s * random_hit(engine);
    }
    else if (contact.type == CollisionType::Middle)
    {
        if (this->velocity.y == 0)
        {
            this->velocity.y = random_y_hit(engine);
            return;
        }
        this->velocity.y = velocity.y * random_hit(engine);
    }
}

Contact Ball::PaddleCollision(Paddle const &paddle)
{
    float ballLeft = this->position.x;
    float ballRight = this->position.x + this->Ball_w;
    float ballTop = this->position.y;
    float ballBottom = this->position.y + this->Ball_h;

    float paddleLeft = paddle.position.x;
    float paddleRight = paddle.position.x + paddle.Paddle_w;
    float paddleTop = paddle.position.y;
    float paddleBottom = paddle.position.y + paddle.Paddle_h;

    Contact contact{};

    if (ballLeft >= paddleRight)
    {
        return contact;
    }
    else if (ballRight <= paddleLeft)
    {
        return contact;
    }
    else if (ballTop >= paddleBottom)
    {
        return contact;
    }
    else if (ballBottom <= paddleTop)
    {
        return contact;
    }

    float paddleRangeUpper = paddleBottom - (2.0f * paddle.Paddle_h / 3.0f);
    float paddleRangeMiddle = paddleBottom - (paddle.Paddle_h / 3.0f);

    if (this->velocity.x < 0)
    {
        // Left paddle
        contact.penetration = paddleRight - ballLeft;
    }
    else if (this->velocity.x > 0)
    {
        // Right paddle
        contact.penetration = paddleLeft - ballRight;
    }

    if ((ballBottom > paddleTop) && (ballBottom < paddleRangeUpper))
    {
        contact.type = CollisionType::Top;
    }
    else if ((ballBottom > paddleRangeUpper) && (ballBottom < paddleRangeMiddle))
    {
        contact.type = CollisionType::Middle;
    }
    else
    {
        contact.type = CollisionType::Bottom;
    }

    return contact;
}

void Ball::WallCollide(Contact const &contact)
{
    if ((contact.type == CollisionType::Top) || (contact.type == CollisionType::Bottom))
    {
        this->position.y += contact.penetration;
        this->velocity.y = -velocity.y * random_hit(engine);
        this->velocity.x = velocity.x * random_speed(engine);
    }
}

Contact Ball::WallCollision()
{
    float ballLeft = this->position.x;
    float ballRight = this->position.x + this->Ball_w;
    float ballTop = this->position.y;
    float ballBottom = this->position.y + this->Ball_h;

    Contact contact{};

    if (ballLeft < 0.0f)
    {
        contact.type = CollisionType::Left;
    }
    else if (ballRight > this->screen_w)
    {
        contact.type = CollisionType::Right;
    }
    else if (ballTop < 0.0f)
    {
        contact.type = CollisionType::Top;
        contact.penetration = -ballTop;
    }
    else if (ballBottom > screen_h)
    {
        contact.type = CollisionType::Bottom;
        contact.penetration = this->screen_h - ballBottom;
    }
    return contact;
}

void Ball::Reset() // reset ball to middle of screen
{
    rect.x = static_cast<int>(startPosition.x);
    rect.y = static_cast<int>(startPosition.y);
    position = startPosition;
    p_velocity.x = velocity.x;
    p_velocity.y = velocity.y;
    velocity.x = 0;
    velocity.y = 0;
}

void Ball::CollisionCheck(Paddle &paddleOne, Paddle &paddleTwo, int &count)
{
    if (Contact contact = this->PaddleCollision(paddleOne);
        contact.type != CollisionType::None)
    {
        this->PaddleCollide(contact);
    }
    else if (Contact contact = this->PaddleCollision(paddleTwo);
             contact.type != CollisionType::None)
    {
        this->PaddleCollide(contact);
    }
    else if (contact = this->WallCollision();
             contact.type != CollisionType::None)
    {
        if (contact.type == CollisionType::Left)
        {
            // player two wins
            this->Reset();
            paddleOne.score++;
            count = 0;
        }
        else if (contact.type == CollisionType::Right)
        {
            // player one wins
            this->Reset();
            paddleTwo.score++;
            count = 0;
        }
        else
        {
            this->WallCollide(contact);
        }
    }
}

void Ball::DelayStart(Paddle &paddleOne, Paddle &paddleTwo, int &count)
{
    // if ball is not moving, i.e. in the middle of the screen after reset, or start of game
    if (this->velocity.x == 0 && this->velocity.y == 0)
    {
        // increment to add a delay
        count++;
        if (count > 50)
        {
            if (paddleOne.score == 0 && paddleTwo.score == 0)
            {
                // always goes to the right at the start
                this->velocity.x = 1;
                return;
            }
            // not the start game, reverse ball direction, and random y value
            if (abs(this->p_velocity.x) > 0.9) { // if ball is too quick, dampen
                this->velocity.x = -this->p_velocity.x * 0.9;
            } else {
                this->velocity.x = -this->p_velocity.x;
            }
            this->velocity.y = this->random_y_start(this->engine);
        }
    }
}
