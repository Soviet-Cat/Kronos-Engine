#include "vector.hpp"
#include <cmath>

using namespace Kronos::CoreSystems::Maths;

float& Vector3D::operator[](const int index)
{
    return ((&x)[index]);
}

const float& Vector3D::operator[](const int index) const
{
    return ((&x)[index]);
}

Vector3D Vector3D::operator*(const float scalar) const
{
    return {x * scalar, y * scalar, z * scalar};
}

Vector3D Vector3D::operator/(const float scalar) const
{
    const float reciprocal = 1.0f / scalar;
    return {x * reciprocal, y * reciprocal, z * reciprocal};
}

Vector3D Vector3D::operator*=(const float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3D Vector3D::operator/=(const float scalar)
{
    const float reciprocal = 1.0f / scalar;
    x *= reciprocal;
    y *= reciprocal;
    z *= reciprocal;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& vector) const
{
    return {x + vector.x, y + vector.y, z + vector.z};
}

Vector3D Vector3D::operator-(const Vector3D& vector) const
{
    return {x - vector.x, y - vector.y, z - vector.z};
}

Vector3D Vector3D::operator-() const
{
    return {-x, -y, -z};
}

Vector3D Vector3D::operator+=(const Vector3D& vector)
{
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector3D Vector3D::operator-=(const Vector3D& vector)
{
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

float Vector3D::magnitude() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalized() const
{
    return *this / magnitude();
}

void Vector3D::normalize()
{
    const Vector3D vec = normalized();
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
}

