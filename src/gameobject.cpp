#include"headers/gameobject.h"
#include"headers/ext.h"

void GameObject::Draw() const
{
    DrawRectangle(m_rect, m_color);
}

bool GameObject::IsCollideWith(const Rectangle& target) const
{
    return
    (m_rect.x + m_rect.width >= target.x && m_rect.y + m_rect.height >= target.y) &&
    (m_rect.x <= target.x + target.width && m_rect.y <= target.y + target.height);
}

const Rectangle& GameObject::GetRect() const
{
    return m_rect;
}