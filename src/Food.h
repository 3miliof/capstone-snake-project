#ifndef FOOD_H
#define FOOD_H

#include <mutex>
#include "GameObject.h"
#include <random>

class Food : public GameObject
{
    public:

        Food();

        double GetSpeedMultiplier();

        virtual void CalculateSpeedMultiplier() = 0;

    protected:

        std::random_device dev;
        std::mt19937 engine;
        double speedMultiplier = 0;
};

#endif