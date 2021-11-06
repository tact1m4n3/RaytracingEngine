#include "world/world.h"

#include "math/utils.h"

void World::add_object(Object* object)
{
    m_objects.push_back(object);
}

bool World::intersect(const Ray& ray, Hit& hit)
{
    Object* closest_object = nullptr;
    double closest_t = INF, t;

    for (auto* object : m_objects)
    {
        t = object->intersect(ray);
        if ((t >= ray.t_min && t <= ray.t_max) && t < closest_t)
        {
            closest_object = object;
            closest_t = t;
        }
    }

    if (closest_object)
    {
        hit.point = ray.orig + closest_t * ray.dir;
        hit.normal = closest_object->normal(hit.point);
        hit.mat = closest_object->get_material();

        return true;
    }

    return false;
}
