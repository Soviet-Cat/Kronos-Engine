# 0 "E:/GitHub/Kronos Engine/src/core/math/matrix.cpp"
# 1 "E:\\GitHub\\Kronos Engine\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "E:/GitHub/Kronos Engine/src/core/math/matrix.cpp"
# 1 "E:/GitHub/Kronos Engine/include/core/math/matrix.hpp" 1
       
# 1 "E:/GitHub/Kronos Engine/include/core/math/vector.hpp" 1
       

namespace Kronos::CoreSystems::Math
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

        float dot(const Vector3D& vector) const;
        Vector3D cross(const Vector3D& vector) const;

        Vector3D project(const Vector3D& vector) const;
        Vector3D reject(const Vector3D& vector) const;
    };
}
# 3 "E:/GitHub/Kronos Engine/include/core/math/matrix.hpp" 2

namespace Kronos::CoreSystems::Math
{
    struct Matrix3D
    {
    private:
        float n[3][3];

    public:
        Matrix3D() = default;
        Matrix3D(float n00, float n01, float n02,
                 float n10, float n11, float n12,
                 float n20, float n21, float n22);
        Matrix3D(const Vector3D& vector_a, const Vector3D& vector_b, const Vector3D& vector_c);

        float& operator()(int index_x, int index_y);
        const float& operator()(int index_x, int index_y) const;
        Vector3D& operator[](int index_y);
        const Vector3D& operator[](int index_y) const;

        Matrix3D operator*(const Matrix3D& matrix);
        Vector3D operator*(const Vector3D& vector);
        Matrix3D operator-();

        float determinant();
        Matrix3D inverse();
    };
}
# 2 "E:/GitHub/Kronos Engine/src/core/math/matrix.cpp" 2

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
