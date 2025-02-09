#pragma once
#include"gameobject.h"
#include"obstacle.h"
#include<vector>

class Player : public GameObject
{
    public:
        Player();
        ~Player() = default;

        void Update(const std::vector<Obstacle>& obstacles);
    
    private:
        int m_speed;
        void m_move(float dx, float dy, const std::vector<Obstacle>& obstacles);
};