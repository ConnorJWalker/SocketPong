cmake_minimum_required(VERSION 3.0)

project(SocketPong)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 REQUIRED graphics window system)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(pong ${SOURCES})

target_link_libraries(pong ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})