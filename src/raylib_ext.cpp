#include"headers/raylib_ext.h"

Vector2d::Vector2d(float x, float y)
{
    this->x = x;
    this->y = y;
}

Camera_2D::Camera_2D()
{
    this->offset    = Vector2d();
    this->target    = Vector2d();
    this->rotation  = 0.0f;
    this->zoom      = 1.0f;
}

Camera_2D::Camera_2D(const Vector2d& Offset)
{
    this->offset    = Offset;
    this->target    = Vector2d();
    this->rotation  = 0.0f;
    this->zoom      = 1.0f;
}

Camera_2D::Camera_2D(const Vector2d& Offset, const Vector2d& Target, float Rotation, float Zoom)
{
    this->offset    = Offset;
    this->target    = Target;
    this->rotation  = Rotation;
    this->zoom      = Zoom;
}

RGBA::operator Color()
{
    return {(uint8_t)R, (uint8_t)G, (uint8_t)B, A};
}

void DrawRectangle(const Rectangle& object, const Color& color)
{
    DrawRectangle(object.x, object.y, object.width, object.height, color);
}