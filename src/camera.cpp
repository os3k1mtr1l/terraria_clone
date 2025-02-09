#include"headers/camera.h"
#include"headers/ext.h"
#include<iostream>

void CameraHandler::SetTarget(const Rectangle* target)
{
    m_target = target;

    m_cam.offset = Vector2({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    Update();
    m_cam.rotation = 0;
    m_cam.zoom = 1;
}

void CameraHandler::BeginCameraMode()
{
    BeginMode2D(m_cam);
}

void CameraHandler::EndCameraMode()
{
    EndMode2D();
}

void CameraHandler::Update()
{
    if(IsKeyPressed(KEY_KP_ADD))
    {
        if(m_cam.zoom >= 5)
            m_cam.zoom = 5;
        else
            m_cam.zoom += 0.5;
    }

    if(IsKeyPressed(KEY_KP_SUBTRACT))
    {
        if(m_cam.zoom <= 1)
            m_cam.zoom = 1;
        else
            m_cam.zoom -= 0.5f;
    }

    m_cam.target.x = m_target->x;
    m_cam.target.y = m_target->y;
}