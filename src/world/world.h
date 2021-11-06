#pragma once

#include <vector>

#include "engine/ray.h"
#include "engine/hit.h"
#include "world/object.h"

class World
{
private:
    std::vector<Object*> m_objects;
public:
    World() = default;
    ~World() = default;

    void add_object(Object* object);

    bool intersect(const Ray& ray, Hit& hit);
};
