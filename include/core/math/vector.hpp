#pragma once

namespace Kronos::CoreSystems::Math
{
    struct Vector3
    {
        float x, y, z;

        Vector3();
        Vector3(float x, float y, float z);

        float& operator[](int i);
        const float& operator[](int i) const;

        Vector3 operator+(const Vector3& v) const;
        Vector3 operator-(const Vector3& v) const;
        Vector3 operator*(float s) const;
        Vector3 operator/(float s) const;
        Vector3 operator-() const;
        Vector3 operator+=(const Vector3& v);
        Vector3 operator-=(const Vector3& v);
        Vector3 operator*=(float s);
        Vector3 operator/=(float s);

        float magnitude() const;
        void normalize();
    };

    float dot(const Vector3& a, const Vector3& b);
    Vector3 cross(const Vector3& a, const Vector3& b);

    Vector3 project(const Vector3& a, const Vector3& b);
    Vector3 reject(const Vector3& a, const Vector3& b);
}