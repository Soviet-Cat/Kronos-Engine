#pragma once

#include "matrix.hpp"
#include "vector.hpp"
#include "quaternion.hpp"

namespace Kronos::CoreSystems::Math
{
    Vector3 operator*(const Vector3& v, const Matrix3x3& m);
    Vector3 operator*(const Matrix3x3& m, const Vector3& v);
    Vector3 operator*=(Vector3& v, const Matrix3x3& m);

    Matrix3x3 operator-(const Matrix3x3& m);

    Matrix3x3 makeRotationMatrix(float t, const Vector3& a);
    Matrix3x3 makeReflectionMatrix(const Vector3& v);
    Matrix3x3 makeSkewMatrix(float t, const Vector3& a, const Vector3& b);
    Matrix3x3 makeScaleMatrix(float s, const Vector3& v);
    Matrix3x3 makeScaleMatrix(float sx, float sy, float sz);
    Matrix3x3 makeInvolutionMatrix(const Vector3& v);

    Vector3 operator*(const Vector3& v, const Quaternion& q);
    Vector3 operator*=(Vector3& v, const Quaternion& q);

    float radians(float t);
    float degrees(float t);
}
