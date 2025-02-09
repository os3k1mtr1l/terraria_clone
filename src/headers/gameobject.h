#pragma once
#include<raylib.h>

class GameObject
{
    public:
        void Draw() const;

        bool IsCollideWith(const Rectangle& target) const;
        const Rectangle& GetRect() const;
    
    protected:
        Rectangle m_rect;
        Color m_color;
};