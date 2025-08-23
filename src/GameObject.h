#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <mutex>

class GameObject
{
    public:

        int GetX();
        int GetY();

        void SetX(const int new_x);
        void SetY(const int new_y);

        void SetPosition(const int &new_x, const int &new_y);


    protected:

        std::mutex position_mutex; 
        int position_x;
        int position_y;

};

#endif