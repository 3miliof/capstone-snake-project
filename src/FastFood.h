#ifndef FASTFOOD_H
#define FASTFOOD_H

#include <mutex>
#include "Food.h"
#include <random>

class FastFood : public Food
{
    public:

        void CalculateSpeedMultiplier() override;

};

#endif