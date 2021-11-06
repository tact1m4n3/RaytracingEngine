#pragma once

#include <string>

#include <math/vector.h>

class Image
{
private:
    int m_width, m_height;
    uint8_t* m_pixels;
public:
    Image(int width, int height);
    ~Image();

    void put_pixel(int x, int y, const Vec3& color, int samples);
    void save(const std::string& name);

    inline int get_width() const { return m_width; }
    inline int get_height() const { return m_height; }
};