#pragma once

#include "math/vector.h"
#include "engine/ray.h"
#include "world/material.h"

class Object
{
private:
    Material* m_mat;
public:
    Object(Material* mat);
    ~Object() = default;

    virtual double intersect(const Ray& ray) = 0;
    virtual Vec3 normal(const Vec3& point) = 0;

    inline Material* get_material() const { return m_mat; };
};

class SphereObject : public Object
{
private:
    Vec3 m_center;
    double m_radius;
public:
    SphereObject(const Vec3& center, double radius, Material* mat);
    ~SphereObject() = default;

    virtual double intersect(const Ray& ray) override;
    virtual Vec3 normal(const Vec3& point) override;
};
