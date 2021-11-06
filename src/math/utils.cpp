#include "math/utils.h"

double clamp(double a, double min, double max)
{
    if (a < min)
        a = min;
    else if (a > max)
        a = max;
    
    return a;
}

double radians(double a)
{
    return a * (PI / 180.0);
}

double dot(const Vec3& u, const Vec3& v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vec3 cross(const Vec3& u, const Vec3& v)
{
    return { u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x };
}

Vec3 reflect(const Vec3& v, const Vec3& n)
{
    return v - 2.0 * dot(v, n) * n;
}
