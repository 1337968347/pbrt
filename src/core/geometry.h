#include <pbrt.h>

class Point
{
public:
    Point() { x = y = z = 0.f; };
    Point(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};

    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }

    Point &operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }

    Point &operator=(const Vector &v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y, z + p.z);
    }

    Point operator+(const Vector &v) const
    {
        return Point(x + v.x, y + v.y, z + v.z);
    }

    Point &operator+=(const Point &p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }

    Point &operator+=(const Vector &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    Point operator-(const Vector &v) const
    {
        return Point(x - v.x, y - v.y, z - v.z);
    }

    Point &operator-=(const Point &p)
    {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    Point &operator-=(const Vector &v)
    {
        return Point(x - v.x, y - v.y, z - v.z);
    }

    Point operator*(float f) const
    {
        return Point(x * f, y * f, z * f);
    }

    Point &operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    Point operator/(float f) const
    {
        float inv = 1.0 / f;
        return Point(inv * x, inv * y, inv * z);
    }

    Point &operator/=(float f)
    {
        float inv = 1.0 / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    float operator[](int i) const
    {
        return (&x)[i];
    }

    float &operator[](int i)
    {
        return (&x)[i];
    }

    bool operator==(const Point &p)
    {
        return p.x == x && p.y == y && p.z == z;
    }

    bool operator!=(const Point &p) const
    {
        return x != p.x || y != p.y || z != p.z;
    }

    float x, y, z;
};

class Vector
{
public:
    Vector() { x = y = z = 0.f; }
    Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};
    bool HasNaNs() const
    {
        return isnan(x) || isnan(y) || isnan(z);
    }
    explicit Vector(const Vector &v);
    float x, y, z;
};