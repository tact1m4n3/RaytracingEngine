#pragma once

#include "math/vector.h"
#include "engine/ray.h"
#include "engine/hit.h"

class Material
{
public:
    virtual bool scatter(const Ray& ray, const Hit& hit, Ray& scattered_ray, Vec3& attenuation);
    virtual Vec3 emitted_color();
};

class MatteMaterial : public Material
{
private:
    Vec3 m_color;
public:
    MatteMaterial(const Vec3& color);
    ~MatteMaterial() = default;

    bool scatter(const Ray& ray, const Hit& hit, Ray& scattered_ray, Vec3& attenuation) override;
};

class MetallicMaterial : public Material
{
private:
    Vec3 m_color;
    double m_fuzz;
public:
    MetallicMaterial(const Vec3& color, double fuzz);
    ~MetallicMaterial() = default;

    bool scatter(const Ray& ray, const Hit& hit, Ray& scattered_ray, Vec3& attenuation) override;
};

class LightEmittingMaterial : public Material
{
private:
    Vec3 m_color;
public:
    LightEmittingMaterial(const Vec3& color);
    ~LightEmittingMaterial() = default;

    virtual Vec3 emitted_color() override;
};
