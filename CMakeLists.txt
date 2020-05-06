cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
project(Pong)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} src include)


add_executable(Pong src/main.cpp src/renderer.cpp src/controller.cpp src/game.cpp src/ball.cpp src/paddle.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Pong ${SDL2_LIBRARIES})
