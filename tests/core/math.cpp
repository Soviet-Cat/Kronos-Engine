#include "vector.hpp"
#include <iostream>

using namespace Kronos::CoreSystems::Maths;

int main()
{
    Vector3D vec = Vector3D(1.0, 1.0, 1.0);
    Vector3D vec_inverse = -vec;
    std::cout << vec_inverse.x << std::endl;
    std::cout << vec_inverse.y << std::endl;
    std::cout << vec_inverse.z << std::endl;
}