cmake_minimum_required(VERSION 3.17)
project(noche)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

aux_source_directory(debug debug)

# 3rdparty
include_directories(3rdparty)

# spdlog
include_directories(3rdparty/spdlog/include)
add_subdirectory(3rdparty/spdlog)
# lua54
add_subdirectory(3rdparty/lua54)
# sol2
#include_directories(3rdparty/sol2/single/single/include)
add_subdirectory(3rdparty/sol2)

add_executable(noche main.cpp ${debug})
target_link_libraries(noche spdlog)
target_link_libraries(noche lua54)
target_link_libraries(noche sol2)