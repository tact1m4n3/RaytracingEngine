#pragma once

#include <limits>

#include "math/vector.h"

#define PI 3.14159265359
#define INF std::numeric_limits<double>::max()

double clamp(double a, double min, double max);
double radians(double a);

double dot(const Vec3& u, const Vec3& v);
Vec3 cross(const Vec3& u, const Vec3& v);
Vec3 reflect(const Vec3& v, const Vec3& n);
