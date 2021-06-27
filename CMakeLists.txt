cmake_minimum_required(VERSION 3.17)
project(noche)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

aux_source_directory(entry entry)
aux_source_directory(debug debug)
aux_source_directory(io io)
aux_source_directory(reflection reflection)

# 3rdparty
include_directories(3rdparty)

# spdlog
include_directories(3rdparty/spdlog/include)
add_subdirectory(3rdparty/spdlog)
# lua54
add_subdirectory(3rdparty/lua54)
# sol2
add_subdirectory(3rdparty/sol2)
# yaml-cpp
include_directories(3rdparty/yaml-cpp/include)
add_subdirectory(3rdparty/yaml-cpp)

add_executable(noche main.cpp ${debug} ${entry})
target_link_libraries(noche spdlog)
target_link_libraries(noche lua54)
target_link_libraries(noche sol2)
target_link_libraries(noche yaml-cpp)