#pragma once
#include <vector.hpp>

namespace Kronos::CoreSystems::Math
{
    struct Matrix3D
    {
    private:
        float n[3][3];

    public:
        Matrix3D() = default;
        Matrix3D(float n00, float n01, float n02,
                 float n10, float n11, float n12,
                 float n20, float n21, float n22);
        Matrix3D(const Vector3D& vector_a, const Vector3D& vector_b, const Vector3D& vector_c);

        float& operator()(int index_x, int index_y);
        const float& operator()(int index_x, int index_y) const;
        Vector3D& operator[](int index_y);
        const Vector3D& operator[](int index_y) const;

        Matrix3D operator*(const Matrix3D& matrix);
        Vector3D operator*(const Vector3D& vector);
        Matrix3D operator-();

        float determinant();
        Matrix3D inverse();
    };
}
