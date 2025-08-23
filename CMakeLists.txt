cmake_minimum_required(VERSION 3.10)
project(SDL2Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

# Executable and sources
add_executable(SnakeGame 
    src/main.cpp 
    src/game.cpp 
    src/controller.cpp 
    src/renderer.cpp 
    src/snake.cpp
    src/highscore.cpp
    src/GameObject.cpp
    src/Food.cpp
    src/FastFood.cpp
    src/SlowFood.cpp
)

message(STATUS "SDL2 Libraries: ${SDL2_LIBRARIES}")


target_compile_definitions(SnakeGame PRIVATE SDL_MAIN_HANDLED)

target_link_libraries(SnakeGame SDL2::SDL2main SDL2::SDL2)
