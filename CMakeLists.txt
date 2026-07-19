cmake_minimum_required(VERSION 3.16)
project(chip8 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED CONFIG)

add_executable(chip8
    src/main.cpp
    src/chip8.cpp
)

target_link_libraries(chip8 PRIVATE SDL2::SDL2)
