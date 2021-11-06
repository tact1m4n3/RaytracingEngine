#include "world/material.h"

#include "math/utils.h"
#include "math/random.h"

bool Material::scatter(const Ray& ray, const Hit& hit, Ray& scattered_ray, Vec3& attenuation)
{
    return false;
}

Vec3 Material::emitted_color()
{
    return { 0.0, 0.0, 0.0 };
}

MatteMaterial::MatteMaterial(const Vec3& color)
{
    m_color = color;
}

bool MatteMaterial::scatter(const Ray& ray, const Hit& hit, Ray& scattered_ray, Vec3& attenuation)
{
    Vec3 scatter_dir = hit.normal + random_generator::random_vec3(-1.0, 1.0);
    
    scattered_ray = { hit.point, scatter_dir, 0.001, INF };
    attenuation = m_color;

    return true;
}

MetallicMaterial::MetallicMaterial(const Vec3& color, double fuzz)
{
    m_color = color;
    m_fuzz = (fuzz <= 1.0) ? fuzz : 1.0;
}

bool MetallicMaterial::scatter(const Ray& ray, const Hit& hit, Ray& scattered_ray, Vec3& attenuation)
{
    Vec3 reflected_dir = reflect(ray.dir, hit.normal);

    scattered_ray = { hit.point, reflected_dir + m_fuzz * random_generator::random_vec3(-1.0, 1.0), 0.001, INF };
    attenuation = m_color;

    return (dot(scattered_ray.dir, hit.normal) > 0);
}

LightEmittingMaterial::LightEmittingMaterial(const Vec3& color)
{
    m_color = color;
}

Vec3 LightEmittingMaterial::emitted_color()
{
    return m_color;
}
