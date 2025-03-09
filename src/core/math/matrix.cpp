#include "matrix.hpp"
#include <cmath>

namespace Kronos::CoreSystems::Math
{
    Matrix3x3::Matrix3x3()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f;
    }

    Matrix3x3::Matrix3x3(const float m00, const float m01, const float m02, const float m10, const float m11, const float m12, const float m20, const float m21, const float m22)
    {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
    }

    float& Matrix3x3::operator()(const int i, const int j)
    {
        return m[j][i];
    }

    const float& Matrix3x3::operator()(const int i, const int j) const
    {
        return m[j][i];
    }

    Matrix3x3 Matrix3x3::operator*(const Matrix3x3& m) const
    {
        Matrix3x3 n = *this;
        return {
            n(0, 0) * m(0, 0) + n(0, 1) * m(1, 0) + n(0, 2) * m(2, 0),
            n(0, 0) * m(0, 1) + n(0, 1) * m(1, 1) + n(0, 2) * m(2, 1),
            n(0, 0) * m(0, 2) + n(0, 1) * m(1, 2) + n(0, 2) * m(2, 2),
            n(1, 0) * m(0, 0) + n(1, 1) * m(1, 0) + n(1, 2) * m(2, 0),
            n(1, 0) * m(0, 1) + n(1, 1) * m(1, 1) + n(1, 2) * m(2, 1),
            n(1, 0) * m(0, 2) + n(1, 1) * m(1, 2) + n(1, 2) * m(2, 2),
            n(2, 0) * m(0, 0) + n(2, 1) * m(1, 0) + n(2, 2) * m(2, 0),
            n(2, 0) * m(0, 1) + n(2, 1) * m(1, 1) + n(2, 2) * m(2, 1),
            n(2, 0) * m(0, 2) + n(2, 1) * m(1, 2) + n(2, 2) * m(2, 2)
        };
    }

    Matrix3x3 Matrix3x3::operator*=(const Matrix3x3& m)
    {
        auto n = *this;
        this->m[0][0] = n(0, 0) * m(0, 0) + n(0, 1) * m(1, 0) + n(0, 2) * m(2, 0);
        this->m[0][1] = n(0, 0) * m(0, 1) + n(0, 1) * m(1, 1) + n(0, 2) * m(2, 1);
        this->m[0][2] = n(0, 0) * m(0, 2) + n(0, 1) * m(1, 2) + n(0, 2) * m(2, 2);
        this->m[1][0] = n(1, 0) * m(0, 0) + n(1, 1) * m(1, 0) + n(1, 2) * m(2, 0);
        this->m[1][1] = n(1, 0) * m(0, 1) + n(1, 1) * m(1, 1) + n(1, 2) * m(2, 1);
        this->m[1][2] = n(1, 0) * m(0, 2) + n(1, 1) * m(1, 2) + n(1, 2) * m(2, 2);
        this->m[2][0] = n(2, 0) * m(0, 0) + n(2, 1) * m(1, 0) + n(2, 2) * m(2, 0);
        this->m[2][1] = n(2, 0) * m(0, 1) + n(2, 1) * m(1, 1) + n(2, 2) * m(2, 1);
        this->m[2][2] = n(2, 0) * m(0, 2) + n(2, 1) * m(1, 2) + n(2, 2) * m(2, 2);
        return *this;
    }

    float Matrix3x3::determinant() const
    {

        auto n = *this;
        return n(0, 0) * (n(1, 1) * n(2, 2) - n(1, 2) * n(2, 1)) +
               n(0, 1) * (n(1, 2) * n(2, 0) - n(1, 0) * n(2, 2)) +
               n(0, 2) * (n(1, 0) * n(2, 1) - n(1, 1) * n(2, 0));
    }

    Matrix3x3 makeXAxisRotationMatrix(const float t)
    {
        const float r = t * (M_PI / 180.0f);
        const float c = std::cos(r);
        const float s = std::sin(r);
        return {
            1.0f, 0.0f, 0.0f,
            0.0f, c, -s,
            0.0f, s, c
        };
    }

    Matrix3x3 makeYAxisRotationMatrix(const float t)
    {
        const float r = t * (M_PI / 180.0f);
        const float c = std::cos(r);
        const float s = std::sin(r);
        return {
            c, 0.0f, s,
            0.0f, 1.0f, 0.0f,
            -s, 0.0f, c
        };
    }

    Matrix3x3 makeZAxisRotationMatrix(const float t)
    {
        const float r = t * (M_PI / 180.0f);
        const float c = std::cos(r);
        const float s = std::sin(r);
        return {
            c, -s, 0.0f,
            s, c, 0.0f,
            0.0f, 0.0f, 1.0f
        };
    }


}
