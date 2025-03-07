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
