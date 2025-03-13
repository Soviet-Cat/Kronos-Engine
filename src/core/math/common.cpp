#include "common.hpp"
#include <cmath>

namespace Kronos::CoreSystems::Math
{
    Vector3 operator*(const Matrix3x3& m, const Vector3& v)
    {
        return {
            m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z,
            m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z,
            m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z,
        };
    }

    Vector3 operator*(const Vector3& v, const Matrix3x3& m)
    {
        return m * v;
    }

    Vector3 operator*=(Vector3& v, const Matrix3x3& m)
    {
        const float old_x = v.x;
        const float old_y = v.y;
        const float old_z = v.z;
        v.x = m(0, 0) * old_x + m(0, 1) * old_y + m(0, 2) * old_z;
        v.y = m(1, 0) * old_x + m(1, 1) * old_y + m(1, 2) * old_z;
        v.z = m(2, 0) * old_x + m(2, 1) * old_y + m(2, 2) * old_z;
        return v;
    }

    Matrix3x3 operator-(const Matrix3x3& m)
    {
        const auto a = Vector3(m(0, 0), m(1, 0), m(2, 0));
        const auto b = Vector3(m(0, 1), m(1, 1), m(2, 1));
        const auto c = Vector3(m(0, 2), m(1, 2), m(2, 2));

        const Vector3 bc = cross(b, c);
        const Vector3 ca = cross(c, a);
        const Vector3 ab = cross(a, b);

        const float det = 1.0f / dot(ab, c);

        return {
            bc.x * det, bc.y * det, bc.z * det,
            ca.x * det, ca.y * det, ca.z * det,
            ab.x * det, ab.y * det, ab.z * det
        };
    }

    Matrix3x3 makeRotationMatrix(float t, const Vector3& a)
    {
        const float r = t * (M_PI / 180.0f);
        const float c = std::cos(r);
        const float s = std::sin(r);
        const float d = 1.0f - c;

        const float x = a.x * d;
        const float y = a.y * d;
        const float z = a.z * d;
        const float axay = x * a.y;
        const float axaz = x * a.z;
        const float ayaz = y * a.z;

        return {
            c + x * a.x, axay -s * a.z, axaz + s * a.y,
            axay + s * a.z, c + y * a.y, axaz - s * a.x,
            axaz - s * a.y, ayaz + s * a.x, c + z * a.z,
        };
    }

    Matrix3x3 makeReflectionMatrix(const Vector3& v)
    {
        const float x = v.x * -2.0f;
        const float y = v.y * -2.0f;
        const float z = v.z * -2.0f;
        const float axay = x * v.y;
        const float axaz = x * v.z;
        const float ayaz = y * v.z;

        return {
            x * v.x + 1.0f, axay, axaz,
            axay, y * v.y + 1.0f, ayaz,
            axaz, ayaz, z * v.z + 1.0f
        };
    };

    Matrix3x3 makeSkewMatrix(const float t, const Vector3& a, const Vector3& b)
    {
        const float r = t * (M_PI / 180.0f);
        const float tan = std::tan(r);
        const float x = a.x * tan;
        const float y = a.y * tan;
        const float z = a.z * tan;

        return {
            x * b.x + 1.0f, x * b.y, x * b.z,
            y * b.x, y * b.y + 1.0f, y * b.z,
            z * b.x, y * b.y, z * b.z + 1.0f
        };
    }
    Matrix3x3 makeScaleMatrix(const float s, const Vector3& v)
    {
        const float t = s - 1.0f;
        const float x = v.x * t;
        const float y = v.y * t;
        const float z = v.z * t;
        const float axay = x * v.y;
        const float axaz = x * v.z;
        const float ayaz = y * v.z;

        return {
            x * v.x + 1.0f, axay, axaz,
            axay, y * v.y + 1.0f, ayaz,
            axaz, ayaz, z * v.x + 1.0f
        };
    }
    Matrix3x3 makeScaleMatrix(float sx, float sy, float sz)
    {
        return {
            sx, 0.0f, 0.0f,
            0.0f, sy, 0.0f,
            0.0f, 0.0f, sz
        };
    }
    Matrix3x3 makeInvolutionMatrix(const Vector3& v)
    {
        const float x = v.x * 2.0f;
        const float y = v.y * 2.0f;
        const float z = v.z * 2.0f;
        const float axay = x * v.y;
        const float axaz = x * v.z;
        const float ayaz = y * v.z;

        return {
            x * v.x - 1.0f, axay, axaz,
            axay, y * v.y - 1.0f, ayaz,
            axaz, ayaz, z * v.z - 1.0f
        };
    }

    Vector3 operator*(const Vector3& v, const Quaternion& q)
    {
        const auto a = Vector3(q.x, q.y, q.z);
        const float a2 = a.x * a.x + a.y * a.y + a.z * a.z;
        return v * (q.w * q.w - a2) + a * (dot(v, a) * 2.0f) + cross(a, v) * (q.w * 2.0f);
    }

    float radians(const float t)
    {
        return t * (M_PI / 180.0f);
    }

    float degrees(const float t)
    {
        return t * (180.0f / M_PI);
    }


}
