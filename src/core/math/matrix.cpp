#include "matrix.hpp"
#include <cmath>

using namespace Kronos::CoreSystems::Math;

Matrix3D::Matrix3D(const float n00, const float n01, const float n02,
                 const float n10, const float n11, const float n12,
                 const float n20, const float n21, const float n22)
{
    n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
    n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
    n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
}

Matrix3D::Matrix3D(const Vector3D& vector_a, const Vector3D& vector_b, const Vector3D& vector_c)
{
    n[0][0] = vector_a.x; n[0][1] = vector_a.y; n[0][2] = vector_a.z;
    n[1][0] = vector_b.x; n[1][1] = vector_b.y; n[1][2] = vector_b.z;
    n[2][0] = vector_c.x; n[2][1] = vector_c.y; n[2][2] = vector_c.z;
}

float& Matrix3D::operator()(const int index_x, const int index_y)
{
    return n[index_y][index_x];
}

const float& Matrix3D::operator()(const int index_x, const int index_y) const
{
    return n[index_y][index_x];
}

Vector3D& Matrix3D::operator[](const int index_y)
{
    return *reinterpret_cast<Vector3D*>(n[index_y]);
}

const Vector3D& Matrix3D::operator[](const int index_y) const
{
    return *reinterpret_cast<const Vector3D*>(n[index_y]);
}

Matrix3D Matrix3D::operator*(const Matrix3D& matrix)
{
    return {
        (*this)(0, 0) * matrix(0, 0) + (*this)(0, 1) * matrix(1, 0) + (*this)(0, 2) * matrix(2, 0),
        (*this)(0, 0) * matrix(0, 1) + (*this)(0, 1) * matrix(1, 1) + (*this)(0, 2) * matrix(2, 1),
        (*this)(0, 0) * matrix(0, 2) + (*this)(0, 1) * matrix(1, 2) + (*this)(0, 2) * matrix(2, 2),
        (*this)(1, 0) * matrix(0, 0) + (*this)(1, 1) * matrix(1, 0) + (*this)(1, 2) * matrix(2, 0),
        (*this)(1, 0) * matrix(0, 1) + (*this)(1, 1) * matrix(1, 1) + (*this)(1, 2) * matrix(2, 1),
        (*this)(1, 0) * matrix(0, 2) + (*this)(1, 1) * matrix(1, 2) + (*this)(1, 2) * matrix(2, 2),
        (*this)(2, 0) * matrix(0, 0) + (*this)(2, 1) * matrix(1, 0) + (*this)(2, 2) * matrix(2, 0),
        (*this)(2, 0) * matrix(0, 1) + (*this)(2, 1) * matrix(1, 1) + (*this)(2, 2) * matrix(2, 1),
        (*this)(2, 0) * matrix(0, 2) + (*this)(2, 1) * matrix(1, 2) + (*this)(2, 2) * matrix(2, 2),
    };
}

Vector3D Matrix3D::operator*(const Vector3D& vector)
{
    return {
        (*this)(0, 0) * vector.x + (*this)(0, 1) * vector.y + (*this)(0, 2) * vector.z,
        (*this)(1, 0) * vector.x + (*this)(1, 1) * vector.y + (*this)(1, 2) * vector.z,
        (*this)(2, 0) * vector.x + (*this)(2, 1) * vector.y + (*this)(2, 2) * vector.z
    };
}

float Matrix3D::determinant()
{
    return (*this)(0, 0) * ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) +
           (*this)(0, 1) * ((*this)(1, 2) * (*this)(2, 0) - (*this)(1, 0) * (*this)(2, 2)) +
           (*this)(0, 2) * ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0));
}

Matrix3D Matrix3D::inverse()
{
    const Vector3D& a = (*this)[0];
    const Vector3D& b = (*this)[1];
    const Vector3D& c = (*this)[2];

    const Vector3D d = b.cross(c);
    const Vector3D e = c.cross(a);
    const Vector3D f = a.cross(b);

    const float det = 1.0f / f.dot(c);

    return {
        d.x * det, d.y * det, d.z * det,
        e.x * det, e.y * det, e.z * det,
        f.x * det, f.y * det, f.z * det,
    };
}

Matrix3D Matrix3D::operator-()
{
    return inverse();
}

void Matrix3D::zero()
{
    n[0][0] = 0.0f; n[0][1] = 0.0f; n[0][2] = 0.0f;
    n[1][0] = 0.0f; n[1][1] = 0.0f; n[1][2] = 0.0f;
    n[2][0] = 0.0f; n[2][1] = 0.0f; n[2][2] = 0.0f;
}

void Matrix3D::rotateX(const float angle)
{
    const float radians = angle * (M_PI / 180.0f);
    const float cos = std::cos(radians);
    const float sin = std::sin(radians);
    n[0][0] = 1.0f; n[0][1] = 0.0f; n[0][2] = 0.0f;
    n[1][0] = 0.0f; n[1][1] = cos; n[1][2] = -sin;
    n[2][0] = 0.0f; n[2][1] = sin; n[2][2] = cos;
}

void Matrix3D::rotateY(const float angle)
{
    const float radians = angle * (M_PI / 180.0f);
    const float cos = std::cos(radians);
    const float sin = std::sin(radians);
    n[0][0] = cos; n[0][1] = 0.0f; n[0][2] = sin;
    n[1][0] = 0.0f; n[1][1] = 1.0f; n[1][2] = 0.0f;
    n[2][0] = -sin; n[2][1] = 0.0f; n[2][2] = cos;
}

void Matrix3D::rotateZ(const float angle)
{
    const float radians = angle * (M_PI / 180.0f);
    const float cos = std::cos(radians);
    const float sin = std::sin(radians);
    n[0][0] = cos; n[0][1] = -sin; n[0][2] = 0.0f;
    n[1][0] = sin; n[1][1] = cos; n[1][2] = 0.0f;
    n[2][0] = 0.0f; n[2][1] = 0.0f; n[2][2] = 1.0f;
}

void Matrix3D::rotate(const float angle, const Vector3D& axis)
{
    const float radians = angle * (M_PI / 180.0f);
    const float cos = std::cos(radians);
    const float sin = std::sin(radians);
    const float d = 1.0f - cos;

    const float x = axis.x * d;
    const float y = axis.y * d;
    const float z = axis.z * d;
    const float axay = axis.x * axis.y;
    const float axaz = axis.x * axis.z;
    const float ayaz = axis.y * axis.z;

    n[0][0] = cos + x * axis.x; n[0][1] = axay - sin * axis.z; n[0][2] = axaz + sin * axis.y;
    n[1][0] = axay + sin * axis.z; n[1][1] = cos + y * axis.y; n[1][2] = ayaz - sin * axis.x;
    n[2][0] = axaz - sin * axis.y; n[2][1] = ayaz + sin * axis.x; n[2][2] = cos + z * axis.z;
}

void Matrix3D::reflect(const Vector3D& vector)
{
    const float x = vector.x * -2.0f;
    const float y = vector.y * -2.0f;
    const float z = vector.z * -2.0f;
    const float axay = x * vector.y;
    const float axaz = x * vector.z;
    const float ayaz = y * vector.z;

    n[0][0] = x * vector.x + 1.0f; n[0][1] = axay; n[0][2] = axaz;
    n[1][0] = axay; n[1][1] = y * vector.y + 1.0f; n[1][2] = ayaz;
    n[2][0] = axaz; n[2][1] = ayaz; n[2][2] = z * vector.z + 1.0f;
}

void Matrix3D::involution(const Vector3D& vector)
{
    const float x = vector.x * 2.0f;
    const float y = vector.y * 2.0f;
    const float z = vector.z * 2.0f;
    const float axay = x * vector.y;
    const float axaz = x * vector.z;
    const float ayaz = y * vector.z;

    n[0][0] = x * vector.x - 1.0f; n[0][1] = axay; n[0][2] = axaz;
    n[1][0] = axay; n[1][1] = y * vector.y - 1.0f; n[1][2] = ayaz;
    n[2][0] = axaz; n[2][1] = ayaz; n[2][2] = z * vector.z - 1.0f;
}

void Matrix3D::scale(const float x, const float y, const float z)
{
    n[0][0] = x; n[0][1] = 0.0f; n[0][2] = 0.0f;
    n[1][0] = y; n[1][1] = 0.0f; n[1][2] = 0.0f;
    n[2][0] = 0.0f; n[2][1] = 0.0f; n[2][2] = z;
}

void Matrix3D::scale(const float scale, const Vector3D& axis)
{
    const float s = scale - 1.0f;
    const float x = axis.x * s;
    const float y = axis.y * s;
    const float z = axis.z * s;
    const float axay = axis.x * axis.y;
    const float axaz = axis.x * axis.z;
    const float ayaz = axis.y * axis.z;

    n[0][0] = x * axis.x + 1.0f; n[0][1] = axay; n[0][2] = axaz;
    n[1][0] = axay; n[1][1] = y * axis.y + 1.0f; n[1][2] = ayaz;
    n[2][0] = axaz; n[2][1] = ayaz; n[2][2] = z * axis.z + 1.0f;
}

void Matrix3D::skew(const float angle, const Vector3D& vector_a, const Vector3D& vector_b)
{
    const float radians = angle * (M_PI / 180.0f);
    const float tan = std::tan(radians);
    const float x = vector_a.x * tan;
    const float y = vector_a.y * tan;
    const float z = vector_a.z * tan;

    n[0][0] = x * vector_b.x + 1.0f; n[0][1] = x * vector_b.y; n[0][2] = x * vector_b.z;
    n[1][0] = y * vector_b.x; n[1][1] = y * vector_b.y + 1.0f; n[1][2] = y * vector_b.z;
    n[2][0] = z * vector_b.x; n[2][1] = z * vector_b.y; n[2][2] = z * vector_b.z + 1.0f;
}

