#include "vector.hpp"
#include <iostream>
#include "matrix.hpp"

using namespace Kronos::CoreSystems::Math;

int main()
{
    Vector3D vec = Vector3D(0.0, 1.0, 0.0);
    Matrix3D mat = Matrix3D();
    mat.rotateX(90.0f);
    Vector3D vec2 = mat * vec;
    std::cout << vec2.x << std::endl;
    std::cout << vec2.y << std::endl;
    std::cout << vec2.z << std::endl;
}