cmake_minimum_required(VERSION 3.0.0)
project(raytracer VERSION 0.1.0 LANGUAGES CXX)

#set to c++20
set(CMAKE_CXX_STANDARD 20)

set(SOURCE
    src/main.cpp
    src/vec3.h
    src/color.h
    src/ray.h
)


add_executable(raytracer ${SOURCE})