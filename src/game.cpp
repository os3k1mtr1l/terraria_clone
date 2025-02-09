#include"../lib/rlImGui-main/imgui.h"
#include"../lib/rlImGui-main/rlImgui.h"
#include"headers/game.h"
#include"headers/ext.h"
#include<string>
#include<iostream>

Game::Game()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game");
    SetTargetFPS(60);
    rlImGuiSetup(true);
}

Game::~Game()
{
    rlImGuiShutdown();
    CloseWindow();
}

void Game::m_initGame()
{
    o_camera.SetTarget(&o_player.GetRect());

    o_obstacles.emplace_back(
        -5,
        0,
        5,
        WINDOW_HEIGHT + 5,
        RED
    ); //LEFT

    o_obstacles.emplace_back(
        WINDOW_WIDTH,
        -5,
        5,
        WINDOW_HEIGHT + 5,
        RED
    ); // RIGHT

    o_obstacles.emplace_back(
        -5,
        -5,
        WINDOW_WIDTH + 5,
        5,
        RED
    ); // TOP

    o_obstacles.emplace_back(
        0,
        WINDOW_HEIGHT,
        WINDOW_WIDTH + 5,
        5,
        RED
    ); //BOTTOM

    o_obstacles.emplace_back(10, 10, 10, 10, BLUE);
    o_obstacles.emplace_back(100, 100, 10, 10, BLUE);
}

void Game::Run()
{
    m_initGame();

    while(!WindowShouldClose())
    {
        m_update();
        m_render();
    }
}

void Game::m_render()
{
    BeginDrawing();
    ClearBackground(BLACK);
    o_camera.BeginCameraMode();

    DrawRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GREEN);
    for(Obstacle ob : o_obstacles)
        ob.Draw();

    o_player.Draw();

    o_camera.EndCameraMode();
    
    rlImGuiBegin();

    {
        ImGui::Begin("Debug");

        const Rectangle& player_pos = o_player.GetRect();

        ImGui::Text("Player pos: %d | %d", (int)player_pos.x, (int)player_pos.y);
        
        for(const Obstacle& ob : o_obstacles)
        {
            int count = &ob - &o_obstacles[0];
            const Rectangle& ob_rect = ob.GetRect();
            ImGui::Text("Obstacle%d pos: %d | %d", count, (int)ob_rect.x, (int)ob_rect.y);
        }

        ImGui::End();
    }

    rlImGuiEnd();
    EndDrawing();
}

void Game::m_update()
{
    o_player.Update(o_obstacles);
    o_camera.Update();
}