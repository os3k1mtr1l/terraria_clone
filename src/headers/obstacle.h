#pragma once
#include"gameobject.h"

class Obstacle : public GameObject
{
    public:
        Obstacle(int x, int y, int width, int height, Color color);
};