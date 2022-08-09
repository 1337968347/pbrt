#pragma once

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using std::max;
using std::min;
using std::swap;

// 插值
inline float Lerp(float t, float v1, float v2) {
    return (1.f - t) * v1 + t * v2;
}

inline float clamp(float val, float min, float max) {
    if (val < min)
        return min;
    if (val > max)
        return max;
    return val;
}