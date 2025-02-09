#include"headers/player.h"
#include"headers/ext.h"
#include<iostream>
#include"headers/camera.h"

Player::Player()
{
    m_speed = 100;
    m_rect = {(WINDOW_WIDTH / 2) - 5, (WINDOW_HEIGHT / 2) - 5, 10, 10};
    m_color = WHITE;
}

void Player::m_move(float dx, float dy, const std::vector<Obstacle>& obstacles)
{
    const Rectangle old_rect = m_rect;

    m_rect.x += dx * GetFrameTime();
    for (const Obstacle& ob : obstacles)
    {
        if (this->IsCollideWith(ob.GetRect()))
        {
            m_rect.x = old_rect.x;
            break;
        }
    }

    m_rect.y += dy * GetFrameTime();
    for (const Obstacle& ob : obstacles)
    {
        if (this->IsCollideWith(ob.GetRect()))
        {
            m_rect.y = old_rect.y;
            break;
        }
    }
}

void Player::Update(const std::vector<Obstacle>& obstacles)
{
    float dx = 0, dy = 0;
    if(IsKeyDown(KEY_LEFT)) dx = -m_speed;

    if(IsKeyDown(KEY_RIGHT)) dx = m_speed;
    
    if(IsKeyDown(KEY_UP)) dy = -m_speed;
    
    if(IsKeyDown(KEY_DOWN)) dy = m_speed;

    m_move(dx, dy, obstacles);
}