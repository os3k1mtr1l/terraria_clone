#pragma once
#include<raylib.h>
#include<cstdint>

struct Vector2d : public Vector2
{
    Vector2d(float x = 0.0f, float y = 0.0f);
};

struct Camera_2D : Camera2D
{
    Camera_2D();
    Camera_2D(const Vector2d& Offset);
    Camera_2D(const Vector2d& Offset, const Vector2d& Target, float Rotation = 0.0f, float Zoom = 1.0f);
};

struct RGBA
{
    int R;
    int G;
    int B;
    const uint8_t A = 255;

    operator Color();
};

extern void DrawRectangle(const Rectangle& object, const Color& color);