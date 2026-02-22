cmake_minimum_required(VERSION 3.10.0)
project(tutorial VERSION 0.1.0)

include(CTest)
enable_testing()

# find_package(coost REQUIRED CONFIG)
add_subdirectory(vendor/coost)
add_subdirectory(letcode)
add_subdirectory(boost_tutorial)
add_subdirectory(raii)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tutorial main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

configure_file(TutorialConfig.h.in TutorialConfig.h)