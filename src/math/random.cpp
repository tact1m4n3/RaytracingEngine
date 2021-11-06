#include "math/random.h"

std::mt19937 random_generator::s_random_engine;
std::uniform_int_distribution<std::mt19937::result_type> random_generator::s_distribution;

void random_generator::init()
{
    s_random_engine.seed(std::random_device()());
}

double random_generator::random_double()
{
    return (double)s_distribution(s_random_engine) / (double)std::numeric_limits<uint32_t>::max();
}

double random_generator::random_double(double min, double max)
{
    return min + (max - min) * random_double();
}

Vec3 random_generator::random_vec3()
{
    Vec3 v = { random_double(), random_double(), random_double() };
    v /= v.length();
    return v;
}

Vec3 random_generator::random_vec3(double min, double max)
{
    Vec3 v = { random_double(min, max), random_double(min, max), random_double(min, max) };
    v /= v.length();
    return v;
}
