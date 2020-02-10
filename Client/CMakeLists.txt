project(SocketPong)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 REQUIRED graphics window system)

set(SOURCES
    main.cpp
)

add_executable(pong ${SOURCES})

target_link_libraries(pong ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})