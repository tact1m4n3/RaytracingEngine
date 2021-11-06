#pragma once

#include "math/random.h"
#include "math/utils.h"
#include "math/vector.h"
#include "engine/timer.h"
#include "engine/image.h"
#include "engine/ray.h"
#include "engine/hit.h"
#include "engine/camera.h"
#include "world/world.h"

class RaytracingEngine
{
private:
    static RaytracingEngine* s_instance;

    Camera* m_camera;
    World* m_world;
    
    Timer* m_timer;
public:
    RaytracingEngine(Camera* camera, World* world);

    double render(Image& image, const Vec3& background, int pixel_samples, int ray_depth);

    inline static RaytracingEngine* get_instance() { return s_instance; }
private:
    Vec3 trace_ray(const Ray& ray, const Vec3& background, int depth);
};
