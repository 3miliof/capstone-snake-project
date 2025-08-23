#include "GameObject.h"

int GameObject::GetX()
{
    std::lock_guard<std::mutex> lock(position_mutex);
    return position_x;
}

int GameObject::GetY()
{
    std::lock_guard<std::mutex> lock(position_mutex);
    return position_y;
}

void GameObject::SetX(const int new_x)
{
    std::lock_guard<std::mutex> lock(position_mutex);
    position_x = new_x;
}

void GameObject::SetY(const int new_y)
{
    std::lock_guard<std::mutex> lock(position_mutex);
    position_y = new_y;
}

void GameObject::SetPosition(const int new_x, const int new_y)
{
    std::lock_guard<std::mutex> lock(position_mutex);
    position_x = new_x;
    position_y = new_y;
}