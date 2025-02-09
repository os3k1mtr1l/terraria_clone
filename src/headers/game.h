#pragma once
#include<raylib.h>
#include<vector>
#include"player.h"
#include"camera.h"
#include"obstacle.h"

class Game
{
    public:
        Game();
        ~Game();

        void Run();

    private:
        void m_initGame();
        void m_render();
        void m_update();

        Player o_player;
        CameraHandler o_camera;
        std::vector<Obstacle> o_obstacles;
};