#pragma once

#include <cmath>
#include <string>
#include <sstream>

struct Vec3
{
    union { double x, r; };
    union { double y, g; };
    union { double z, b; };

    inline double length() const { return sqrt(x*x + y*y + z*z); }
    inline double length_squared() const { return x*x + y*y + z*z; }

    inline Vec3 operator-() { return { -x, -y, -z }; }
    inline Vec3 operator*(double t) { return { x * t, y * t, z * t }; }
    inline Vec3 operator/(double t) { return { x / t, y / t, z / t }; }
    inline Vec3& operator+=(const Vec3& v) { x += v.x, y += v.y, z += v.z; return *this; }
    inline Vec3& operator-=(const Vec3& v) { x -= v.x, y -= v.y, z -= v.z; return *this; }
    inline Vec3& operator*=(double t) { x *= t, y *= t, z *= t; return *this; }
    inline Vec3& operator/=(double t) { x /= t, y /= t, z /= t; return *this; }
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) { return out << "Vector3 { " << v.x << ", " << v.y << ", " << v.z << " }"; }
inline Vec3 operator*(double t, const Vec3& v) { return { t * v.x, t * v.y, t * v.z }; }
inline Vec3 operator+(const Vec3& u, const Vec3& v) { return { u.x + v.x, u.y + v.y, u.z + v.z }; }
inline Vec3 operator-(const Vec3& u, const Vec3& v) { return { u.x - v.x, u.y - v.y, u.z - v.z }; }
inline Vec3 operator*(const Vec3& u, const Vec3& v) { return { u.x * v.x, u.y * v.y, u.z * v.z }; }
inline Vec3 operator/(const Vec3& u, const Vec3& v) { return { u.x / v.x, u.y / v.y, u.z / v.z }; }
