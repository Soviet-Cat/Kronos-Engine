#include "quaternion.hpp"
#include <cmath>

namespace Kronos::CoreSystems::Math
{
    Quaternion::Quaternion()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }

    Quaternion::Quaternion(const float x, const float y, const float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        w = 1.0f;
    }

    Quaternion::Quaternion(const float x, const float y, const float z, const float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    float& Quaternion::operator[](const int i)
    {
        return (&x)[i];
    }

    const float& Quaternion::operator[](const int i) const
    {
        return (&x)[i];
    }

    Quaternion Quaternion::operator*(const Quaternion& q) const
    {
        const Quaternion u = *this;
        return {
            u.w * q.x + u.x * q.w + u.y * q.z - u.z * q.y,
            u.w * q.y - u.x * q.z + u.y * q.w + u.z * q.x,
            u.w * q.z + u.x * q.y - u.y * q.x + u.z * q.w,
            u.w * q.w - u.x * q.x - u.y * q.y - u.z * q.z,
        };
    }

    Matrix3x3 Quaternion::getRotationMatrix() const
    {
        const float x2 = x * x;
        const float y2 = y * y;
        const float z2 = z * z;
        const float xy = x * y;
        const float xz = x * z;
        const float yz = y * z;
        const float wx = w * x;
        const float wy = w * y;
        const float wz = w * z;

        return {
            1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy),
            2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx),
            2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2),
        };
    }

    void Quaternion::setRotationMatrix(const Matrix3x3& m)
    {
        const float m00 = m(0, 0);
        const float m11 = m(1, 1);
        const float m22 = m(2, 2);

        if (const float sum = m00 + m11 + m22; sum > 0.0f)
        {
            w = std::sqrt(sum + 1.0f) * 0.5f;
            const float f = 0.25 / w;
            x = (m(2, 1) - m(1, 2)) * f;
            y = (m(0, 2) - m(2, 0)) * f;
            z = (m(1, 0) - m(0, 1)) * f;
        }
        else if ((m00 > m11) && (m00 > m22))
        {
            x = std::sqrt(m00 - m11 - m22 + 1.0f) * 0.5f;
            const float f = 0.25f / x;

            y = (m(1, 0) + m(0, 1)) * f;
            z = (m(0, 2) + m(2, 0)) * f;
            w = (m(2, 1) - m(1, 2)) * f;
        }
        else if (m11 > m22)
        {
            y = std::sqrt(m11 - m00 - m22 + 1.0f) * 0.5f;
            const float f = 0.25f / y;

            x = (m(1, 0) + m(0, 1)) * f;
            z = (m(2, 1) + m(1, 2)) * f;
            w = (m(0, 2) - m(2, 0)) * f;
        }
        else
        {
            z = std::sqrt(m22 - m00 - m11 + 1.0f) * 0.5f;
            const float f = 0.25f / z;

            x = (m(0, 2) + m(2, 0)) * f;
            y = (m(2, 1) + m(1, 2)) * f;
            w = (m(1, 0) - m(0, 1)) * f;
        }
    }


}
