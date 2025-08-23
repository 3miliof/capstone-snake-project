#include "FastFood.h"

void FastFood::CalculateSpeedMultiplier()
{
    std::uniform_real_distribution<double> random_m(1, 4);
    speedMultiplier = random_m(engine);
}
