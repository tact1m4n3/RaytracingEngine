#include "engine/engine.h"

#include <cassert>

RaytracingEngine* RaytracingEngine::s_instance = nullptr;

RaytracingEngine::RaytracingEngine(Camera* camera, World* world)
{
    assert(!s_instance);

    m_camera = camera;
    m_world = world;
 
    m_timer = new Timer();
 
    random_generator::init();
}

double RaytracingEngine::render(Image& image, const Vec3& background, int pixel_samples, int ray_depth)
{
    m_timer->start();

    for (int y = 0; y < image.get_height(); y++)
    {
        for (int x = 0; x < image.get_width(); x++)
        {
            Vec3 color = { 0.0, 0.0, 0.0 };
            for (int i = 0; i < pixel_samples; i++)
            {
                double h = 1.0 - (x + random_generator::random_double(-1.0, 1.0)) / image.get_width();
                double v = 1.0 - (y + random_generator::random_double(-1.0, 1.0)) / image.get_height();

                Ray ray = m_camera->screen_to_ray(h, v);
                color += trace_ray(ray, background, ray_depth);
            }
            image.put_pixel(x, y, color, pixel_samples);
        }
    }

    return m_timer->stop();
}

Vec3 RaytracingEngine::trace_ray(const Ray& ray, const Vec3& background, int depth)
{
    Hit hit;
    if (!m_world->intersect(ray, hit))
        return background;

    if (depth <= 0)
        return { 0.0, 0.0, 0.0 };

    Ray scattered_ray;
    Vec3 attenuation;
    Vec3 emitted_color = hit.mat->emitted_color();
    if (hit.mat->scatter(ray, hit, scattered_ray, attenuation))
        return emitted_color + attenuation * trace_ray(scattered_ray, background, depth - 1);
    return emitted_color;
}
