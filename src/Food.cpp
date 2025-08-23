#include "Food.h"

Food::Food() : 
    engine(dev())
{
}

double Food::GetSpeedMultiplier()
{
    return speedMultiplier;
}
