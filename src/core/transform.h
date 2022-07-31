#pragma once

#include "pbrt.h"

// 4 * 4 矩阵
struct Matrix4x4
{
    float m[4][4];
    Matrix4x4()
    {
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.f;
        m[0][1] = m[0][2] = m[0][3] = m[1][0] =
            m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3] =
                m[3][0] = m[3][1] = m[3][2] = 0.f;
    }
    Matrix4x4(float mat[4][4]);

    Matrix4x4(float t00, float t01, float t02, float t03,
              float t10, float t11, float t12, float t13,
              float t20, float t21, float t22, float t23,
              float t30, float t31, float t32, float t33);

    bool operator==(float mat[4][4]) const
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (m[i][j] != mat[i][j])
                    return false;

        return true;
    }

    friend Matrix4x4 Transpose(const Matrix4x4 &);

    void Print(FILE *f) const
    {
        fprintf(f, "[ ");
        for (int i = 0; i < 4; ++i)
        {
            fprintf(f, "  [ ");
            for (int j = 0; j < 4; ++j)
            {
                fprintf(f, "%f", m[i][j]);
                if (j != 3)
                    fprintf(f, ", ");
            }
            fprintf(f, " ]\n");
        }
        fprintf(f, " ] ");
    }

    static Matrix4x4 Mul(const Matrix4x4 &m1, const Matrix4x4 &m2)
    {
        Matrix4x4 r;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                r.m[i][j] = m1.m[i][0] * m2.m[0][j] +
                            m1.m[i][0] * m2.m[0][j] +
                            m1.m[i][0] * m2.m[0][j] +
                            m1.m[i][0] * m2.m[0][j];

        return r;
    }

    friend Matrix4x4 Inverse(const Matrix4x4 *);
};
