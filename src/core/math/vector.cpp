#include "vector.hpp"
#include <cmath>

namespace Kronos::CoreSystems::Math
{
    Vector3::Vector3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Vector3::Vector3(const float x, const float y, const float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float& Vector3::operator[](const int i)
    {
        return (&x)[i];
    }

    const float& Vector3::operator[](const int i) const
    {
        return (&x)[i];
    }

    Vector3 Vector3::operator+(const Vector3& v) const
    {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vector3 Vector3::operator-(const Vector3& v) const
    {
        return {x - v.x, y - v.y, z - v.z};
    }

    Vector3 Vector3::operator*(const float s) const
    {
        return {x * s, y * s, z * s};
    }

    Vector3 Vector3::operator/(const float s) const
    {
        if (s != 0.0f)
        {
            const float rec = 1.0f / s;
            return {x * rec, y * rec, z * rec};
        }
        return {};
    }

    Vector3 Vector3::operator-() const
    {
        return {-x, -y, -z};
    }

    Vector3 Vector3::operator+=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3 Vector3::operator-=(const Vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3 Vector3::operator*=(const float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3 Vector3::operator/=(const float s)
    {
        if (s != 0.0f)
        {
            const float rec = 1.0f / s;
            x *= rec;
            y *= rec;
            z *= rec;
            return *this;
        }
        return *this;
    }

    float Vector3::magnitude() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    void Vector3::normalize()
    {
        if (const float m = magnitude(); m != 0.0f)
        {
            x /= m;
            y /= m;
            z /= m;
        }
    }

    float dot(const Vector3& a, const Vector3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    Vector3 cross(const Vector3& a, const Vector3& b)
    {
        return {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    Vector3 project(const Vector3& a, const Vector3& b)
    {
        return b * (dot(a, b) / dot(b, b));
    }


    Vector3 reject(const Vector3& a, const Vector3& b)
    {
        return a - b * (dot(a, b) / dot(b, b));
    }


}
