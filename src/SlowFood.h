#ifndef SLOWFOOD_H
#define SLOWFOOD_H

#include <mutex>
#include "Food.h"
#include <random>

class SlowFood : public Food
{
    public:

        void CalculateSpeedMultiplier() override;

};

#endif