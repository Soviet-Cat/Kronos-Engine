#pragma once
#include <matrix.hpp>

namespace Kronos::CoreSystems::Math
{
    struct Quaternion
    {
        float x, y, z, w;

        Quaternion();
        Quaternion(float x, float y, float z);
        Quaternion(float x, float y, float z, float w);

        float& operator[](int i);
        const float& operator[](int i) const;

        Quaternion operator*(const Quaternion& q) const;
        Quaternion& operator*=(const Quaternion& q);

        Matrix3x3 getRotationMatrix() const;
        void setRotationMatrix(const Matrix3x3& m);
    };
}
