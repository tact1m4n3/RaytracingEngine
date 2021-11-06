#include <iostream>

#include "engine/engine.h"

#define WIDTH 1920
#define HEIGHT 1080
#define SAMPLES 200
#define RAY_DEPTH 100

int main()
{
    Camera* camera = new Camera({ 0.0, 3.0, -2.0 }, { 0.0, 0.0, 3.0 }, { 0.0, 1.0, 0.0 }, 90.0, (double)WIDTH / (double)HEIGHT, 0.1, 1000.0);
    Image* image = new Image(WIDTH, HEIGHT);
    World* world = new World();

    Material* ground_material = new MatteMaterial({ 0.5, 0.5, 0.5 });
    Material* light_material1 = new LightEmittingMaterial({ 0.8, 0.8, 0.2 });
    Material* light_material2 = new LightEmittingMaterial({ 0.2, 0.8, 0.8 });
    Material* metallic_material1 = new MetallicMaterial({ 1.0, 1.0, 1.0 }, 0.0);
    Material* metallic_material2 = new MetallicMaterial({ 0.4, 0.2, 0.9 }, 0.2);
    Material* metallic_material3 = new MetallicMaterial({ 0.1, 0.5, 0.2 }, 0.5);
    Material* metallic_material4 = new MetallicMaterial({ 0.8, 0.8, 0.8 }, 0.8);
    Material* matte_material1 = new MatteMaterial({ 0.8, 0.3, 0.4 });
    Material* matte_material2 = new MatteMaterial({ 0.2, 0.4, 0.6 });
    Material* matte_material3 = new MatteMaterial({ 0.3, 0.5, 0.2 });
    Material* matte_material4 = new MatteMaterial({ 0.8, 0.1, 0.8 });

    world->add_object(new SphereObject({ 0.0, -1000.0, 0.0 }, 1000.0, ground_material));
    world->add_object(new SphereObject({ -1.4, 1.0, 3.0 }, 1.0, light_material1));
    world->add_object(new SphereObject({ -2.0, 0.4, -0.5 }, 0.4, light_material2));
    world->add_object(new SphereObject({ 1.4, 1.2, 1.5 }, 1.2, metallic_material1));
    world->add_object(new SphereObject({ 2.4, 0.4, 0.0 }, 0.4, metallic_material2));
    world->add_object(new SphereObject({ -1.2, 0.3, -0.2 }, 0.3, metallic_material3));
    world->add_object(new SphereObject({ -2.4, 0.7, 1.0 }, 0.7, metallic_material4));
    world->add_object(new SphereObject({ -1.0, 0.2, 0.5 }, 0.2, matte_material1));
    world->add_object(new SphereObject({ 1.5, 0.4, -0.4 }, 0.4, matte_material2));
    world->add_object(new SphereObject({ 0.5, 0.3, 0.2 }, 0.3, matte_material3));
    world->add_object(new SphereObject({ -0.5, 0.5, 1.8 }, 0.5, matte_material4));

    RaytracingEngine* engine = new RaytracingEngine(camera, world);
    std::cout << "Execution took " << engine->render(*image, { 0.1, 0.2, 0.8 }, SAMPLES, RAY_DEPTH) << " second/s!" << std::endl;
    delete engine;

    image->save("output.ppm");

    delete camera, image, world;

    system("convert output.ppm output.png");

    return 0;
}
