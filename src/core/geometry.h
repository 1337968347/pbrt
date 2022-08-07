#include <pbrt.h>

class Point {
   public:
    Point() { x = y = z = 0.f; };
    Point(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};

    Point(const Point& p) {
        x = p.x;
        y = p.y;
        z = p.z;
    }

    Point& operator=(const Point& p) {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }

    Point& operator=(const Vector& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y, z + p.z);
    }

    Point operator+(const Vector& v) const {
        return Point(x + v.x, y + v.y, z + v.z);
    }

    Point& operator+=(const Point& p) {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }

    Point& operator+=(const Vector& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    Point operator-(const Vector& v) const {
        return Point(x - v.x, y - v.y, z - v.z);
    }

    Point& operator-=(const Point& p) {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    Point& operator-=(const Vector& v) {
        return Point(x - v.x, y - v.y, z - v.z);
    }

    Point operator*(float f) const { return Point(x * f, y * f, z * f); }

    Point& operator*=(float f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    Point operator/(float f) const {
        float inv = 1.0 / f;
        return Point(inv * x, inv * y, inv * z);
    }

    Point& operator/=(float f) {
        float inv = 1.0 / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    float operator[](int i) const { return (&x)[i]; }

    float& operator[](int i) { return (&x)[i]; }

    bool operator==(const Point& p) { return p.x == x && p.y == y && p.z == z; }

    bool operator!=(const Point& p) const {
        return x != p.x || y != p.y || z != p.z;
    }

    float x, y, z;
};

class Vector {
   public:
    Vector() { x = y = z = 0.f; }
    Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};
    Vector(const Vector& v) {
        x = v.x;
        y = v.y;
        z = v.z;
    };
    bool HasNaNs() const { return isnan(x) || isnan(y) || isnan(z); }

    Vector& operator=(const Vector& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y, z + v.z);
    }

    Vector& operator+=(const Vector& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector operator-(const Vector& v) const {
        return Vector(x - v.x, y - v.y, z - v.z);
    }

    Vector& operator-=(const Vector& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector operator*(float f) const { return Vector(f * x, f * y, f * z); }

    Vector& operator*=(float f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    Vector operator/(float f) const {
        float inv = 1.f / f;
        return Vector(x * inv, y * inv, z * inv);
    }

    Vector& operator/=(float f) {
        float inv = 1.f / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }
    Vector operator-() const { return Vector(-x, -y, -z); }
    float operator[](int i) const { return (&x)[i]; }

    float& operator[](int i) { return (&x)[i]; }

    float LengthSquared() const { return x * x + y * y + z * z; }
    float Length() const { return sqrtf(LengthSquared()); }
    explicit Vector(const Normal& n);

    bool operator==(const Vector& v) const {
        return x == v.x && y == v.y && z == v.z;
    }
    bool operator!=(const Vector& v) const {
        return x != v.x || y != v.y || z != v.z;
    }
    float x, y, z;
};

class Normal {
   public:
    Normal() {
        x = 0.f;
        y = 0.f;
        z = 0.f;
    }
    Normal(float xx, float yy, float zz) : x(xx), y(yy), z(zz){};
    Normal(const Normal& n) {
        x = n.x;
        y = n.y;
        z = n.z;
    };
    explicit Normal(const Vector& v) : x(v.x), y(v.y), z(v.z){};

    Normal& operator=(const Normal& n) {
        x = n.x;
        y = n.y;
        z = n.z;
        return *this;
    }

    Normal operator-() const { return Normal(-x, -y, -z); }
    Normal operator+(const Normal& n) const {
        return Normal(x + n.x, y + n.y, z + n.z);
    }

    Normal& operator+=(const Normal& n) {
        x += n.x;
        y += n.y;
        z += n.z;
        return *this;
    }
    Normal operator-(const Normal& n) const {
        return Normal(x - n.x, y - n.y, z - n.z);
    }

    Normal& operator-=(const Normal& n) {
        x -= n.x;
        y -= n.y;
        z -= n.z;
        return *this;
    }
    bool HasNaNs() const { return isnan(x) || isnan(y) || isnan(z); }
    Normal operator*(float f) const { return Normal(f * x, f * y, f * z); }

    Normal& operator*=(float f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    Normal operator/(float f) const {
        float inv = 1.f / f;
        return Normal(x * inv, y * inv, z * inv);
    }

    Normal& operator/=(float f) {
        float inv = 1.f / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    float operator[](int i) const { return (&x)[i]; }

    float& operator[](int i) { return (&x)[i]; }

    bool operator==(const Normal& n) const {
        return x == n.x && y == n.y && z == n.z;
    }
    bool operator!=(const Normal& n) const {
        return x != n.x || y != n.y || z != n.z;
    }

    float LengthSquared() const { return x * x + y * y + z * z; }
    float Length() const { return sqrtf(LengthSquared()); }

    float x, y, z;
};

class Ray {
   public:
    Ray() : mint(0.f), maxt(INFINITY), depth(0), time(0.f){};
    Ray(const Point& origin,
        const Vector& direction,
        float start,
        float end = INFINITY,
        float t = 0.f,
        int d = 0)
        : o(origin), d(direction), mint(start), maxt(end), depth(d) {}

    Point operator()(float t) { return o + d * t; }

    Point o;
    Vector d;
    float time;
    int depth;
    mutable float mint, maxt;
};

// 微分
class RayDifferential : public Ray {
    RayDifferential() : hasDifferentials(false){};
    RayDifferential(const Point& org,
                    const Vector& dir,
                    float start,
                    float end = INFINITY,
                    float t = 0.f,
                    int d = 0)
        : Ray(org, dir, start, end, t, d) {
        hasDifferentials = false;
    };

    explicit RayDifferential(const Ray& ray) : Ray(ray) {
        hasDifferentials = false;
    };

    void ScaleDifferentials(float s) {
        rxOrigin = o + (rxOrigin - o) * s;
        ryOrigin = o + (ryOrigin - o) * s;
        rxDirection = d + (rxDirection - d) * s;
        ryDirection = d + (ryDirection - d) * s;
    }

    bool hasDifferentials;
    Point rxOrigin, ryOrigin;
    Vector rxDirection, ryDirection;
};

class BBox {
   public:
    BBox() {
        pMax = Point(INFINITY, INFINITY, INFINITY);
        pMin = Point(-INFINITY, -INFINITY, -INFINITY);
    };

    BBox(const Point& p1, const Point& p2) {
        pMin = Point(min(p1.x, p2.x), min(p1.y, p2.y), min(p1.z, p2.z));
        pMax = Point(max(p1.x, p2.x), max(p1.y, p2.y), max(p1.z, p2.z));
    }

    Point pMin, pMax;
};
