#pragma once

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
