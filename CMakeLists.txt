cmake_minimum_required(VERSION 3.14)
project(MMGI)

set(CMAKE_CXX_STANDARD 14)

add_executable(MMGI main.cpp vector3.h scene.h light.h object.h camera.h ray.h sphere.h)