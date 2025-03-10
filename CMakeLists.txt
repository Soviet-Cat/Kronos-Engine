# set cmake required
cmake_minimum_required(VERSION 3.31)

# create project
project(KronosEngine)

# set cmake cpp version requirements
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set directories
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party")
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")

# create core library
add_library(CoreSystems SHARED
        # math
        "${SOURCE_DIR}/core/math/vector.cpp"
        "${SOURCE_DIR}/core/math/matrix.cpp"
        "${SOURCE_DIR}/core/math/quaternion.cpp"
        "${SOURCE_DIR}/core/math/common.cpp"
)
set_target_properties(CoreSystems PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR}
)
target_include_directories(CoreSystems PUBLIC
        # math
        "${INCLUDE_DIR}/core/math"
)

# create core library tests
add_executable(CoreSystemsMathTest "${TEST_DIR}/core/math.cpp")
set_target_properties(CoreSystemsMathTest PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)
target_include_directories(CoreSystemsMathTest PUBLIC "${INCLUDE_DIR}/core/math")
target_link_libraries(CoreSystemsMathTest CoreSystems)
