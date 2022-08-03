#include <pbrt.h>

class Vector
{
public:
    Vector() { x = y = z = 0.f; }
    Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};
    bool HasNaNs() const
    {
        return isnan(x) || isnan(y) || isnan(z);
    }
    float x, y, z;
}