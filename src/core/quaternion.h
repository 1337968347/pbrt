#pragma once

#include "geometry.h"
#include "pbrt.h"

struct Quaternion {
    Quaternion() {
        v = Vector(0., 0., 0.);
        w = 1.f;
    }
    Quaternion& operator+=(const Quaternion& q) {
        v += q.v;
        w += w;
        return (*this);
    }
    friend Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
        Quaternion ret = q1;
        return ret += q2;
    }
    Quaternion& operator-=(const Quaternion& q) {
        v -= q.v;
        w -= q.w;
        return *this;
    }
    friend Quaternion operator-(const Quaternion& q1, const Quaternion& q2) {
        Quaternion ret = q1;
        return ret -= q2;
    }
    Quaternion& operator*=(float f) {
        v *= f;
        w *= f;
        return *this;
    }
    Quaternion operator*(float f) const {
        Quaternion ret = *this;
        ret.v *= f;
        ret.w *= f;
        return ret;
    }
    Quaternion& operator/=(float f) {
        v /= f;
        w /= f;
        return *this;
    }
    Quaternion operator/(float f) const {
        Quaternion ret = *this;
        ret.v /= f;
        ret.w /= f;
        return ret;
    }

    Transform ToTransform() const;
    Quaternion(const Transform& t);

    Vector v;
    float w;
};

Quaternion Slerp(float t, const Quaternion& q1, const Quaternion& t2);

inline Quaternion operator*(float f, const Quaternion& q) {
    return q * f;
}

inline float Dot(const Quaternion& q1, const Quaternion& q2) {
    return Dot(q1.v, q2.v) + q1.w * q2.w;
}

inline Quaternion Normalize(const Quaternion& q) {
    return q / sqrtf(Dot(q, q));
}