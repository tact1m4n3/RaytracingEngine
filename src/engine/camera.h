#pragma once

#include "math/vector.h"
#include "engine/ray.h"

class Camera
{
private:
    double m_near, m_far;
    Vec3 m_origin, m_horizontal, m_vertical, m_bottom_left;
public:
    Camera(const Vec3& lookfrom, const Vec3& lookat, const Vec3& up, double fov, double aspect, double near, double far);

    Ray screen_to_ray(double h, double v);
};
