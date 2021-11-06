#pragma once

#include "math/vector.h"

struct Material;

struct Hit
{
    Vec3 point;
    Vec3 normal;
    Material* mat;
};
