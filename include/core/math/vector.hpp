#pragma once

namespace Kronos::CoreSystems::Maths
{
    struct Vector3D
    {
        float x, y, z;
        Vector3D() = default;
        Vector3D(const float x, const float y, const float z) : x(x), y(y), z(z) {}
        float& operator[](int index);
        const float& operator[](int index) const;
        Vector3D operator*(float scalar) const;
        Vector3D operator/(float scalar) const;
        Vector3D operator*=(float scalar);
        Vector3D operator/=(float scalar);
        Vector3D operator+(const Vector3D& vector) const;
        Vector3D operator-(const Vector3D& vector) const;
        Vector3D operator-() const;
        Vector3D operator+=(const Vector3D& vector);
        Vector3D operator-=(const Vector3D& vector);
        float magnitude() const;
        Vector3D normalized() const;
        void normalize();
    };
}
