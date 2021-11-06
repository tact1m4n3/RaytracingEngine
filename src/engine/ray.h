#pragma once

#include "math/vector.h"

struct Ray
{
    Vec3 orig;
    Vec3 dir;
    double t_min;
    double t_max;
};
