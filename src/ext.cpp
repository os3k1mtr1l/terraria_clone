#include"headers/ext.h"

void DrawRectangle(const Rectangle& rect, const Color& color)
{
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, color);
}