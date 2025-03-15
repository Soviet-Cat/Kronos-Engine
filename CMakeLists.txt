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
add_library(KronosCoreSystems SHARED
        "${SOURCE_DIR}/core/math.cpp"
)
set_target_properties(KronosCoreSystems PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR}
)
target_include_directories(KronosCoreSystems PUBLIC
        "${INCLUDE_DIR}/core"
)
