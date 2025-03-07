#include "vector.hpp"
#include <iostream>

using namespace Kronos::CoreSystems::Math;

int main()
{
    Vector3D vec = Vector3D(1.0, 1.0, 1.0);
    Vector3D vec2 = vec + Vector3D(1.0, 1.0, 1.0);
    std::cout << vec2.x << std::endl;
    std::cout << vec2.y << std::endl;
    std::cout << vec2.z << std::endl;
    std::cout << vec2.magnitude() << std::endl;
}