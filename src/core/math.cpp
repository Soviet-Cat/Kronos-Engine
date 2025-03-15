#include "math.hpp"

using namespace Kronos::CoreSystems::Math;

const Vector2 Vector2::ZERO(0.0f, 0.0f);
const Vector3 Vector3::ZERO(0.0f, 0.0f, 0.0f);
const Vector4 Vector4::ZERO(0.0f, 0.0f, 0.0f, 0.0f);

const Matrix2x2 Matrix2x2::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
const Matrix3x3 Matrix3x3::ZERO(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Matrix4x4 Matrix4x4::ZERO(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

const Matrix2x2 Matrix2x2::IDENTITY(1.0f, 0.0f, 0.0f, 1.0f);
const Matrix3x3 Matrix3x3::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
const Matrix4x4 Matrix4x4::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

const Quaternion Quaternion::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
const Quaternion Quaternion::IDENTITY(0.0f, 0.0f, 0.0f, 1.0f);

const DualQuaternion DualQuaternion::ZERO({0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f});
const DualQuaternion DualQuaternion::IDENTITY({0.0f, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 0.0f});