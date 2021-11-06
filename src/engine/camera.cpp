#include "camera.h"

#include <cmath>

#include "math/utils.h"

Camera::Camera(const Vec3& lookfrom, const Vec3& lookat, const Vec3& up, double fov, double aspect, double near, double far)
{
    m_near = near;
    m_far = far;

    double scale = tan(radians(fov * 0.5));

    Vec3 w = lookfrom - lookat;
    w /= w.length();
    Vec3 u = cross(up, w);
    u /= u.length();
    Vec3 v = cross(w, u);

    m_origin = lookfrom;
    m_horizontal = 2.0 * aspect * scale * u;
    m_vertical = 2.0 * scale * v;
    m_bottom_left = m_origin - m_horizontal / 2.0 - m_vertical / 2.0 - w;
}

Ray Camera::screen_to_ray(double h, double v)
{
    return { m_origin, m_bottom_left + h * m_horizontal + v * m_vertical - m_origin, m_near, m_far };
}
