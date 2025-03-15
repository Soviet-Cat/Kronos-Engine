#pragma once

#include <cmath>
#include <math.hpp>

#define M_PI 3.14159265359f
#define M_PI_OVER_180 (M_PI / 180.0f)
#define M_180_OVER_PI (180.0f / M_PI)

namespace Kronos::CoreSystems::Math
{
    inline float radToDeg(const float t) { return t * M_180_OVER_PI; }
    inline float degToRad(const float t) { return t * M_PI_OVER_180; }

    struct Vector2
    {
        float x, y;

        Vector2() : x(0), y(0) {}
        Vector2(const float x, const float y) : x(x), y(y) {}
        ~Vector2() {}

        float operator[](const int i) { return (&x)[i]; }
        const float& operator[](const int i) const { return (&x)[i]; }

        float magnitude() const { return std::sqrt(x * x + y * y); }
        float squaredMagnitude() const { return x * x + y * y; }

        void normalize() { if (!isZero()) { const float m = magnitude(); x /= m; y /= m; } }

        bool isUnit() const { return magnitude() == 1.0f; }
        bool isZero() const { return magnitude() == 0.0f; }

        float dot(const Vector2& v) const { return x * v.x + y * v.y; }
        float cross(const Vector2& v) const { return x * v.y - y * v.x; }

        static const Vector2 ZERO;
    };

    struct Vector3
    {
        float x, y, z;

        Vector3() : x(0), y(0), z(0) {}
        Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
        explicit Vector3(const Vector2& v) : x(v.x), y(v.y), z(0) {}
        Vector3(const Vector3& v, const float z) : x(v.x), y(v.y), z(z) {}
        ~Vector3() {}

        float operator[](const int i) { return (&x)[i]; }
        const float& operator[](const int i) const { return (&x)[i]; }

        float magnitude() const { return std::sqrt(x * x + y * y + z * z); }
        float squaredMagnitude() const { return x * x + y * y + z * z; }

        void normalize() { if (!isZero()) { const float m = magnitude(); x /= m; y /= m; z /= m; } }

        bool isUnit() const { return magnitude() == 1.0f; }
        bool isZero() const { return magnitude() == 0.0f; }

        float dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
        Vector3 cross(const Vector3& v) const { return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x }; }

        static const Vector3 ZERO;
    };

    struct Vector4
    {
        float x, y, z, w;

        Vector4() : x(0), y(0), z(0), w(0) {}
        Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}
        explicit Vector4(const Vector3& v) : x(v.x), y(v.y), z(v.z), w(0) {}
        Vector4(const Vector3& v, const float w) : x(v.x), y(v.y), z(v.z), w(w) {}
        ~Vector4() {}

        float operator[](const int i) { return (&x)[i]; }
        const float& operator[](const int i) const { return (&x)[i]; }

        float magnitude() const { return std::sqrt(x * x + y * y + z * z + w * w); }
        float squareMagnitude() const { return x * x + y * y + z * z + w * w; }

        void normalize() { if (!isZero()) { const float m = magnitude(); x /= m; y /= m; z /= m; w /= m; } }

        bool isUnit() const { return magnitude() == 1.0f; }
        bool isZero() const { return magnitude() == 0.0f; }

        float dot(const Vector4& v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
        Vector4 cross(const Vector4& v) const { return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0 }; }

        static const Vector4 ZERO;
    };

    inline Vector2 operator*(const Vector2& a, const Vector2& b) { return {a.x * b.x, a.y * b.y}; }
    inline Vector2 operator*(const Vector2& a, const float s) { return {a.x * s, a.y * s}; }
    inline Vector2 operator/(const Vector2& a, const Vector2& b) { return {a.x / b.x, a.y / b.y}; }
    inline Vector2 operator/(const Vector2& a, const float s) { if (s != 0.0f ) { const float rec = 1.0f / s ; return {a.x * rec, a.y * rec}; } return {a.x, a.y}; }
    inline Vector2 operator+(const Vector2& a, const Vector2& b) { return {a.x + b.x, a.y + b.y}; }
    inline Vector2 operator-(const Vector2& a, const Vector2& b) { return {a.x - b.x, a.y - b.y}; }
    inline Vector2 operator*=(Vector2& a, const Vector2& b) { a.x *= b.x; a.y *= b.y; return a; }
    inline Vector2 operator*=(Vector2& a, const float s) { a.x *= s; a.y *= s; return a; }
    inline Vector2 operator/=(Vector2& a, const Vector2& b) { a.x /= b.x; a.y /= b.y; return a; }
    inline Vector2 operator/=(Vector2& a, const float s) { if (s != 0.0f) { const float rec = 1.0f / s; a.x *= rec; a.y *= rec; return a; } return a; }
    inline Vector2 operator+=(Vector2& a, const Vector2& b) { a.x += b.x; a.y += b.y; return a; }
    inline Vector2 operator-=(Vector2& a, const Vector2& b) { a.x -= b.x; a.y -= b.y; return a; }
    inline Vector2 operator-(const Vector2& a) { return {-a.x, -a.y}; }

    inline Vector3 operator*(const Vector3& a, const Vector3& b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
    inline Vector3 operator*(const Vector3& a, const float s) { return {a.x * s, a.y * s, a.z * s}; }
    inline Vector3 operator/(const Vector3& a, const Vector3& b) { return {a.x / b.x, a.y / b.y, a.z / b.z}; }
    inline Vector3 operator/(const Vector3& a, const float s) { if (s != 0.0f) { const float rec = 1.0f / s; return {a.x * rec, a.y * rec, a.z * rec}; } return {a.x, a.y, a.z}; }
    inline Vector3 operator+(const Vector3& a, const Vector3& b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
    inline Vector3 operator-(const Vector3& a, const Vector3& b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
    inline Vector3 operator*=(Vector3& a, const Vector3& b) { a.x *= b.x; a.y *= b.y; a.z *= b.z; return a; }
    inline Vector3 operator*=(Vector3& a, const float s) { a.x *= s; a.y *= s; a.z *= s; return a; }
    inline Vector3 operator/=(Vector3& a, const Vector3& b) { a.x /= b.x; a.y /= b.y; a.z /= b.z; return a; }
    inline Vector3 operator/=(Vector3& a, const float s) { if (s != 0.0f) { const float rec = 1.0f / s; a.x *= rec; a.y *= rec; a.z *= rec; return a; } return a; }
    inline Vector3 operator+=(Vector3& a, const Vector3& b) { a.x += b.x; a.y += b.y; a.z += b.z; return a; }
    inline Vector3 operator-=(Vector3& a, const Vector3& b) { a.x -= b.x; a.y -= b.y; a.z -= b.z; return a; }
    inline Vector3 operator-(const Vector3& a) { return {-a.x, -a.y, -a.z}; }

    inline Vector4 operator*(const Vector4& a, const Vector4& b) { return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }
    inline Vector4 operator*(const Vector4& a, const float s) { return {a.x * s, a.y * s, a.z * s, a.w * s}; }
    inline Vector4 operator/(const Vector4& a, const Vector4& b) { return {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w}; }
    inline Vector4 operator/(const Vector4& a, const float s) { if (s != 0.0f) { const float rec = 1.0f / s; return {a.x * rec, a.y * rec, a.z * rec, a.w * rec}; } return {a.x, a.y, a.z, a.w}; }
    inline Vector4 operator+(const Vector4& a, const Vector4& b) { return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
    inline Vector4 operator-(const Vector4& a, const Vector4& b) { return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
    inline Vector4 operator*=(Vector4& a, const Vector4& b) { a.x *= b.x; a.y *= b.y; a.z *= b.z; a.w *= b.w; return a; }
    inline Vector4 operator*=(Vector4& a, const float s) { a.x *= s; a.y *= s; a.z *= s; a.w *= s; return a; }
    inline Vector4 operator/=(Vector4& a, const Vector4& b) { a.x /= b.x; a.y /= b.y; a.z /= b.z; a.w /= b.w; return a; }
    inline Vector4 operator/=(Vector4& a, const float s) { if (s != 0.0f) { const float rec = 1.0f / s; a.x *= rec; a.y *= rec; a.z *= rec; a.w *= rec; return a; } return a; }
    inline Vector4 operator+=(Vector4& a, const Vector4& b) { a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w; return a; }
    inline Vector4 operator-=(Vector4& a, const Vector4& b) { a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w; return a; }
    inline Vector4 operator-(const Vector4& a) { return {-a.x, -a.y, -a.z, -a.w}; }

    struct Matrix2x2
    {
        float m00, m01,
              m10, m11;

        Matrix2x2() : m00(0), m01(0), m10(0), m11(0) {}
        Matrix2x2(const float m00, const float m01, const float m10, const float m11) : m00(m00), m01(m01), m10(m10), m11(m11) {}
        ~Matrix2x2() {}

        float determinant() const { return m00 * m11 - m01 * m10; }
        Matrix2x2 transpose() const;
        Matrix2x2 inverse() const
        {
            if (const float det = determinant(); det != 0.0f)
            {
                const float invDet = 1.0f / det;
                return { m11 * invDet, -m01 * invDet, -m10 * invDet, m00 * invDet };
            }
            return *this;
        };

        bool isZero() const { return determinant() == 0.0f; }

        static const Matrix2x2 IDENTITY;
        static const Matrix2x2 ZERO;
    };

    struct Matrix3x3
    {
        float m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22;

        Matrix3x3() : m00(0), m01(0), m02(0), m10(0), m11(0), m12(0), m20(0), m21(0), m22(0) {}
        Matrix3x3(const float m00, const float m01, const float m02,
                  const float m10, const float m11, const float m12,
                  const float m20, const float m21, const float m22) :
                  m00(m00), m01(m01), m02(m02),
                  m10(m10), m11(m11), m12(m12),
                  m20(m20), m21(m21), m22(m22) {}
        ~Matrix3x3() {}

        float determinant() const
        {
            return m00 * Matrix2x2(m11, m12, m21, m22).determinant() -
                   m01 * Matrix2x2(m10, m12, m20, m22).determinant() +
                   m02 * Matrix2x2(m10, m11, m20, m21).determinant();
        }
        Matrix3x3 transpose() const;
        Matrix3x3 inverse() const
        {
            const Vector3& a {m00, m01, m02};
            const Vector3& b {m10, m11, m12};
            const Vector3& c {m20, m21, m22};
            const Vector3 r0 = b.cross(c);
            const Vector3 r1 = c.cross(a);
            const Vector3 r2 = a.cross(b);
            const float invDet = 1.0f / r2.dot(c);
            return { r0.x * invDet, r0.y * invDet, r0.z * invDet,
                        r1.x * invDet, r1.y * invDet, r1.z * invDet,
                        r2.x * invDet, r2.y * invDet, r2.z * invDet};
        }

        bool isZero() const { return determinant() == 0.0f; }

        static const Matrix3x3 IDENTITY;
        static const Matrix3x3 ZERO;
    };

    struct Matrix4x4
    {
        float m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33;

        Matrix4x4() : m00(0), m01(0), m02(0), m03(0), m10(0), m11(0), m12(0), m13(0), m20(0), m21(0), m22(0), m23(0), m30(0), m31(0), m32(0), m33(0) {}
        Matrix4x4(const float m00, const float m01, const float m02, const float m03,
                  const float m10, const float m11, const float m12, const float m13,
                  const float m20, const float m21, const float m22, const float m23,
                  const float m30, const float m31, const float m32, const float m33) :
                  m00(m00), m01(m01), m02(m02), m03(m03),
                  m10(m10), m11(m11), m12(m12), m13(m13),
                  m20(m20), m21(m21), m22(m22), m23(m23),
                  m30(m30), m31(m31), m32(m32), m33(m33) {}
        ~Matrix4x4() {}

        float determinant() const
        {
            return m00 * Matrix3x3(m11, m12, m13, m21, m22, m23, m31, m32, m33).determinant() -
                   m01 * Matrix3x3(m10, m12, m13, m20, m22, m23, m30, m32, m33).determinant() +
                   m02 * Matrix3x3(m10, m11, m13, m20, m21, m23, m30, m31, m33).determinant() -
                   m03 * Matrix3x3(m10, m11, m12, m20, m21, m22, m30, m31, m32).determinant();
        }
        Matrix4x4 transpose() const;
        Matrix4x4 inverse() const
        {
            const Vector3& a {m00, m01, m02};
            const Vector3& b {m10, m11, m12};
            const Vector3& c {m20, m21, m22};
            const Vector3& d {m30, m31, m32};
            const float& x = m03;
            const float& y = m13;
            const float& z = m23;
            const float& w = m33;
            Vector3 s = a.cross(b);
            Vector3 t = c.cross(d);
            Vector3 u = a * y - b * x;
            Vector3 v = c * w - d * z;
            const float invDet = 1.0f / (s.dot(v) + t.dot(u));
            s *= invDet;
            t *= invDet;
            u *= invDet;
            v *= invDet;
            const Vector3 r0 = b.cross(v) + t * y;
            const Vector3 r1 = v.cross(a) - t * x;
            const Vector3 r2 = d.cross(u) + s * w;
            const Vector3 r3 = u.cross(c) - s * z;
            return { r0.x, r0.y, r0.z, -b.dot(t),
                     r1.x, r1.y, r1.z, a.dot(t),
                     r2.x, r2.y, r2.z, -d.dot(s),
                     r3.x, r3.y, r3.z, c.dot(s)};
        }

        bool isZero() const { return determinant() == 0.0f; }

        static const Matrix4x4 IDENTITY;
        static const Matrix4x4 ZERO;
    };

    inline Matrix2x2 operator*(const Matrix2x2& a, const Matrix2x2& b) { return {a.m00 * b.m00 + a.m01 * b.m10, a.m00 * b.m01 + a.m01 * b.m11,
                                                                                    a.m10 * b.m00 + a.m11 * b.m10, a.m10 * b.m01 + a.m11 * b.m11}; }
    inline Matrix2x2 operator*(const Matrix2x2& a, const float s) {  return {a.m00 * s, a.m01 * s, a.m10 * s, a.m11 * s};  }
    inline Matrix2x2 operator*(const float s, const Matrix2x2& a) { return a * s; }
    inline Matrix2x2 operator+(const Matrix2x2& a, const Matrix2x2& b) { return {a.m00 + b.m00, a.m01 + b.m01, a.m10 + b.m10, a.m11 + b.m11}; }
    inline Matrix2x2 operator*=(Matrix2x2& a, const Matrix2x2& b) { a = a * b;return a; }
    inline Matrix2x2 operator*=(Matrix2x2& a, const float s) { a = a * s; return a; }
    inline Matrix2x2 operator+=(Matrix2x2& a, const Matrix2x2& b) { a = a + b; return a; }
    inline Matrix2x2 operator-(const Matrix2x2& a) { return a.inverse(); }

    inline Matrix3x3 operator*(const Matrix3x3& a, const Matrix3x3& b) {
        return { a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20, a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21, a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22,
                    a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20, a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21, a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22,
                    a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20, a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21, a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 }; }
    inline Matrix3x3 operator*(const Matrix3x3& a, const float s) {
        return { a.m00 * s, a.m01 * s, a.m02 * s,
                    a.m10 * s, a.m11 * s, a.m12 * s,
                    a.m20 * s, a.m21 * s, a.m22 * s }; }
    inline Matrix3x3 operator*(const float s, const Matrix3x3& a) { return a * s; }
    inline Matrix3x3 operator+(const Matrix3x3& a, const Matrix3x3& b) {
        return { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02,
                    a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12,
                    a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22 }; }
    inline Matrix3x3 operator*=(Matrix3x3& a, const Matrix3x3& b) { a = a * b; return a; }
    inline Matrix3x3 operator*=(Matrix3x3& a, const float s) { a = a * s; return a; }
    inline Matrix3x3 operator+=(Matrix3x3& a, const Matrix3x3& b) { a = a + b; return a; }
    inline Matrix3x3 operator-(const Matrix3x3& a) { return a.inverse(); }

    inline Matrix4x4 operator*(const Matrix4x4& a, const Matrix4x4& b) {
        return { a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30, a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31,
                    a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32,a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33,
                    a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30, a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31,
                    a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32, a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33,
                    a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30, a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31,
                    a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32, a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33,
                    a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30, a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31,
                    a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32, a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33 }; }
    inline Matrix4x4 operator*(const Matrix4x4& a, const float s) {
        return { a.m00 * s, a.m01 * s, a.m02 * s, a.m03 * s,
                    a.m10 * s, a.m11 * s, a.m12 * s, a.m13 * s,
                    a.m20 * s, a.m21 * s, a.m22 * s, a.m23 * s,
                    a.m30 * s, a.m31 * s, a.m32 * s, a.m33 * s }; }
    inline Matrix4x4 operator*(const float s, const Matrix4x4& a) { return a * s; }
    inline Matrix4x4 operator+(const Matrix4x4& a, const Matrix4x4& b) {
        return { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03,
                    a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13,
                    a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23,
                    a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33 }; }
    inline Matrix4x4 operator*=(Matrix4x4& a, const Matrix4x4& b) { a = a * b; return a; }
    inline Matrix4x4 operator*=(Matrix4x4& a, const float s) { a = a * s; return a; }
    inline Matrix4x4 operator+=(Matrix4x4& a, const Matrix4x4& b) { a = a + b; return a; }
    inline Matrix4x4 operator-(const Matrix4x4& a) { return a.inverse(); }

    inline Vector2 operator*(const Matrix2x2& a, const Vector2& b) { return {a.m00 * b.x + a.m01 * b.y, a.m10 * b.x + a.m11 * b.y}; }
    inline Vector2 operator*(const Vector2& a, const Matrix2x2& b) { return b * a; }
    inline Vector2 operator*=(Vector2& a, const Matrix2x2& b) { a = a * b; return a; }

    inline Vector3 operator*(const Matrix3x3& a, const Vector3& b) {
        return { a.m00 * b.x + a.m01 * b.y + a.m02 * b.z,
                    a.m10 * b.x + a.m11 * b.y + a.m12 * b.z,
                    a.m20 * b.x + a.m21 * b.y + a.m22 * b.z }; }
    inline Vector3 operator*(const Vector3& a, const Matrix3x3& b) { return b * a; }
    inline Vector3 operator*=(Vector3& a, const Matrix3x3& b) { a = a * b; return a; }

    inline Vector4 operator*(const Matrix4x4& a, const Vector4& b) {
        return { a.m00 * b.x + a.m01 * b.y + a.m02 * b.z + a.m03 * b.w,
                    a.m10 * b.x + a.m11 * b.y + a.m12 * b.z + a.m13 * b.w,
                    a.m20 * b.x + a.m21 * b.y + a.m22 * b.z + a.m23 * b.w,
                   a.m30 * b.x + a.m31 * b.y + a.m32 * b.z + a.m33 * b.w }; }
    inline Vector4 operator*(const Vector4& a, const Matrix4x4& b) { return b * a; }
    inline Vector4 operator*=(Vector4& a, const Matrix4x4& b) { a = a * b; return a; }

    struct Quaternion
    {
        float x, y, z, w;

        Quaternion() : x(0), y(0), z(0), w(0) {}
        Quaternion(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}
        Quaternion(const Vector3& a, const float angle) { w = std::cos(degToRad(angle) * 0.5f);
                                                          const Vector3& v = a * std::sin(degToRad(angle) * 0.5);
                                                          x = v.x; y = v.y; z = v.z; }
        explicit Quaternion(const Vector4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }

        static const Quaternion IDENTITY;
        static const Quaternion ZERO;
    };

    struct DualQuaternion
    {
        Quaternion real;
        Quaternion imag;

        DualQuaternion() {}
        DualQuaternion(const Quaternion& a, const Quaternion& b) : real(a), imag(b) {}
        DualQuaternion(const Quaternion& r, const Vector3& t) {}

        static const DualQuaternion IDENTITY;
        static const DualQuaternion ZERO;
    };
};
