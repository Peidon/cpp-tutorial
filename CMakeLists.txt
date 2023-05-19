cmake_minimum_required(VERSION 3.0.0)
project(tutorial VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(coost REQUIRED CONFIG)
add_subdirectory(letcode)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(tutorial main.cpp)
target_link_libraries(tutorial coost::co)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

configure_file(TutorialConfig.h.in TutorialConfig.h)