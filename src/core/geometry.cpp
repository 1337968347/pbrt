#include "geometry.h"

BBox Union(const BBox& b, const Point& p) {
    BBox ret = b;
    ret.pMin.x = min(b.pMin.x, p.x);
    ret.pMin.y = min(b.pMin.y, p.y);
    ret.pMin.z = min(b.pMin.z, p.z);
    ret.pMax.x = max(b.pMax.x, p.x);
    ret.pMax.y = max(b.pMax.y, p.y);
    ret.pMax.z = max(b.pMax.z, p.z);
    return ret;
}

BBox Union(const BBox& b, const BBox& b2) {
    BBox ret;
    ret.pMin.x = min(b.pMin.x, b2.pMin.x);
    ret.pMin.y = min(b.pMin.y, b2.pMin.y);
    ret.pMin.z = min(b.pMin.z, b2.pMin.z);
    ret.pMax.x = max(b.pMax.x, b2.pMax.x);
    ret.pMax.y = max(b.pMax.y, b2.pMax.y);
    ret.pMax.z = max(b.pMax.z, b2.pMax.z);
    return ret;
}

void BBox::BoundingSphere(Point* c, float* rad) const {
    *c = (pMin + pMax) / 2;
    *rad = Inside(*c) ? Distance(*c, pMax) : 0.f;
}

bool BBox::IntersectP(const Ray& ray, float* hitt0, float* hitt1) const {
    float t0 = ray.mint, t1 = ray.maxt;
    for (int i = 0; i < 3; ++i) {
        float invRayDir = 1.f / ray.d[i];
        float tNear = (pMin[i] - ray.o[i]) * invRayDir;
        float tFar = (pMax[i] - ray.o[i]) * invRayDir;

        if (tNear > tFar)
            swap(tNear, tFar);
        t0 = tNear > t0 ? tNear : t0;
        t1 = tFar < t1 ? tFar : t1;
        if (t0 > t1)
            return false;
    }

    if (hitt0)
        *hitt0 = t0;
    if (hitt1)
        *hitt1 = t1;
    return true;
}