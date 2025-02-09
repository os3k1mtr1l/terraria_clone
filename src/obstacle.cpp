#include"headers/obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height, Color color)
{
    m_rect = {(float)x, (float)y, (float)width, (float)height};
    m_color = color;
}