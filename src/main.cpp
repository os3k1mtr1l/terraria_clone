#include<raylib.h>
#include"../lib/rlImGui-main/rlImGui.h"
#include"../lib/rlImGui-main/imgui.h"
#include<cstdint>
#include<iostream>

#include"headers/raylib_ext.h"

const int WINDOWS_WIDTH = 500;
const int WINDOWS_HEIGHT = 500;

short dir_h = 1, dir_v = 1;
int speed = 1000;
Camera_2D cam(Vector2d(WINDOWS_WIDTH / 2, WINDOWS_HEIGHT / 2));
RGBA RGB;

struct Player
{
    int x, y;
    int w, h;

    Color color;

    Player(int _x, int _y, int _w, int _h, Color _c) : x(_x), y(_y), w(_w), h(_h), color(_c) {}

    operator Rectangle()
    {
        return {x, y,  w, h};
    }

} player(500, 500, 10, 10, WHITE),
outer(0, 0, 1000, 1000, BLUE),
inner(100, 100, 800, 800, BLACK);

void IMguiObjectData(const Player& object, const char* name)
{
    ImGui::Text(name);
    ImGui::Text(" X: %d", object.x);
    ImGui::Text(" Y: %d", object.y);
    ImGui::Text(" Width: %d", object.w);
    ImGui::Text(" Height: %d", object.h);
}

void handle_input()
{
    if(IsKeyDown(KEY_LEFT))
    {
        player.x -= speed * GetFrameTime();
    }

    if(IsKeyDown(KEY_RIGHT))
    {
        player.x += speed * GetFrameTime();
    }

    if(IsKeyDown(KEY_UP))
    {
        player.y -= speed * GetFrameTime();
    }

    if(IsKeyDown(KEY_DOWN))
    {
        player.y += speed * GetFrameTime();
    }

    if(IsKeyDown(KEY_KP_ADD))
    {
        cam.zoom -= 0.05;
        if(cam.zoom < 0.05)
            cam.zoom = 0.05;
    }

    if(IsKeyDown(KEY_KP_SUBTRACT))
    {
        cam.zoom += 0.05;
        if(cam.zoom > 3)
            cam.zoom = 3;
    }
}

void update()
{

    if(player.x <= inner.x)
    {
        dir_h *= -1;
        player.x = inner.x;
    }
    else if(player.x + player.w >= inner.x + inner.w)
    {
        dir_h *= -1;
        player.x = inner.x + inner.w - player.w;
    }

    if(player.y <= inner.y)
    {
        dir_v *= -1;
        player.y = inner.y;
    }
    else if(player.y + player.h >= inner.y + inner.h)
    {
        dir_v *= -1;
        player.y = inner.y + inner.h - player.h;
    }
    
    cam.target.x = player.x;
    cam.target.y = player.y;
}

void render()
{
    BeginDrawing();
    rlImGuiBegin();
    BeginMode2D(cam);

    ClearBackground(RGB);

    DrawRectangle(outer, outer.color);
    DrawRectangle(inner, inner.color);
    DrawRectangle(player, player.color);

    ImGui::Begin("Test");

    {
        ImGui::Text("FT %f", GetFrameTime());
        ImGui::Text("FPS %d", GetFPS());
        ImGui::SliderInt("Red", &RGB.R, 0, 255);
        ImGui::SliderInt("Green", &RGB.G, 0, 255);
        ImGui::SliderInt("Blue", &RGB.B, 0, 255);
        ImGui::Text("%s", GetMonitorName(GetCurrentMonitor()));
        ImGui::Text("%d", GetCurrentMonitor());
        ImGui::Text("%d x %d", GetMonitorPhysicalHeight(GetCurrentMonitor()), GetMonitorPhysicalWidth(GetCurrentMonitor()));
    }

    IMguiObjectData(player, "Player:");
    IMguiObjectData(inner, "Inner: ");
    IMguiObjectData(outer, "Outer:");

    ImGui::End();

    EndMode2D();
    rlImGuiEnd();
    EndDrawing();
}

int main()
{
    InitWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, "Test");
    SetTargetFPS(60);
    rlImGuiSetup(true);

    while(!WindowShouldClose())
    {
        handle_input();
        update();
        render();
    }

    rlImGuiShutdown();
    CloseWindow();

    return 0;
}