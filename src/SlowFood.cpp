#include "SlowFood.h"

void SlowFood::CalculateSpeedMultiplier()
{
    std::uniform_real_distribution<double> random_m(0.1, 1);
    speedMultiplier = random_m(engine);
}
