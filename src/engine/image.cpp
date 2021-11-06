#include "image.h"

#include <cmath>
#include <fstream>

#include "math/utils.h"

Image::Image(int width, int height)
{
    m_width = width;
    m_height = height;

    m_pixels = new uint8_t[m_width * m_height * 3];
}

Image::~Image()
{
    delete m_pixels;
}

void Image::put_pixel(int x, int y, const Vec3& color, int samples)
{
    // gamma correction
    double scale = 1.0 / samples;
    Vec3 final_color = { sqrt(scale * color.r), sqrt(scale * color.g), sqrt(scale * color.b) };

    m_pixels[(y * m_width + x) * 3 + 0] = (uint8_t)(clamp(final_color.r, 0.0, 1.0) * 255);
    m_pixels[(y * m_width + x) * 3 + 1] = (uint8_t)(clamp(final_color.g, 0.0, 1.0) * 255);
    m_pixels[(y * m_width + x) * 3 + 2] = (uint8_t)(clamp(final_color.b, 0.0, 1.0) * 255);
}

void Image::save(const std::string& name)
{
    std::ofstream out;

    out.open(name, std::ofstream::binary);

    out << "P6\n";
    out << m_width << ' ' << m_height << '\n';
    out << 255 << '\n';

    out.write((const char*)m_pixels, m_width * m_height * 3);

    out.close();
}
