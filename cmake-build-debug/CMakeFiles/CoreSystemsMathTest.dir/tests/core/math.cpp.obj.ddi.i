# 0 "E:/GitHub/Kronos Engine/tests/core/math.cpp"
# 1 "E:\\GitHub\\Kronos Engine\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "E:/GitHub/Kronos Engine/tests/core/math.cpp"
# 1 "E:/GitHub/Kronos Engine/include/core/math/math.hpp" 1
       

# 1 "E:/GitHub/Kronos Engine/include/core/math/vector.hpp" 1
       

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
# 4 "E:/GitHub/Kronos Engine/include/core/math/math.hpp" 2
# 1 "E:/GitHub/Kronos Engine/include/core/math/matrix.hpp" 1
       

namespace Kronos::CoreSystems::Math
{
    struct Matrix3x3
    {
    private:
        float m[3][3];
    public:
        Matrix3x3();
        Matrix3x3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);

        float& operator()(int i, int j);
        const float& operator()(int i, int j) const;

        Matrix3x3 operator*(const Matrix3x3& m) const;
        Matrix3x3 operator*=(const Matrix3x3& m);

        float determinant() const;

    };

    Matrix3x3 makeXAxisRotationMatrix(float t);
    Matrix3x3 makeYAxisRotationMatrix(float t);
    Matrix3x3 makeZAxisRotationMatrix(float t);
}
# 5 "E:/GitHub/Kronos Engine/include/core/math/math.hpp" 2
# 1 "E:/GitHub/Kronos Engine/include/core/math/quaternion.hpp" 1
       


namespace Kronos::CoreSystems::Math
{
    struct Quaternion
    {
        float x, y, z, w;

        Quaternion();
        Quaternion(float x, float y, float z);
        Quaternion(float x, float y, float z, float w);

        float& operator[](int i);
        const float& operator[](int i) const;

        Quaternion operator*(const Quaternion& q) const;
        Quaternion& operator*=(const Quaternion& q);

        Matrix3x3 getRotationMatrix() const;
        void setRotationMatrix(const Matrix3x3& m);
    };
}
# 6 "E:/GitHub/Kronos Engine/include/core/math/math.hpp" 2
# 1 "E:/GitHub/Kronos Engine/include/core/math/common.hpp" 1
       





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
# 7 "E:/GitHub/Kronos Engine/include/core/math/math.hpp" 2
# 2 "E:/GitHub/Kronos Engine/tests/core/math.cpp" 2

using namespace Kronos::CoreSystems::Math;

int main()
{

}
