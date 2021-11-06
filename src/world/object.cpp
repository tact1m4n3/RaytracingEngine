#include "world/object.h"

#include <cmath>
#include <iostream>

#include "math/utils.h"

Object::Object(Material* mat)
{
    m_mat = mat;
}

SphereObject::SphereObject(const Vec3& center, double radius, Material* mat)
    : Object(mat)
{
    m_center = center;
    m_radius = radius;
}

double SphereObject::intersect(const Ray& ray)
{
    Vec3 oc = ray.orig - m_center;

    double a = ray.dir.length_squared();
    double half_b = dot(oc, ray.dir);
    double c = oc.length_squared() - m_radius * m_radius;

    double delta = half_b * half_b - a * c;
    if (delta < 0.0)
        return INF;
    
    return (-half_b - sqrt(delta)) / a;
}

Vec3 SphereObject::normal(const Vec3& point)
{
    Vec3 n = point - m_center;
    return n / n.length();
}
