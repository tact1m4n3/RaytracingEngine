#pragma once

#include <random>

#include "math/vector.h"

class random_generator
{
private:
    static std::mt19937 s_random_engine;
    static std::uniform_int_distribution<std::mt19937::result_type> s_distribution;
public:
    static void init();

    static double random_double();
    static double random_double(double min, double max);
    static Vec3 random_vec3();
    static Vec3 random_vec3(double min, double max);
};