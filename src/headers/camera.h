#pragma once
#include<raylib.h>

class CameraHandler
{
    public:
        CameraHandler() = default;
        void SetTarget(const Rectangle* target);
        void BeginCameraMode();
        void EndCameraMode();
        void Update();

    private:
        Camera2D m_cam;
        const Rectangle* m_target;
};