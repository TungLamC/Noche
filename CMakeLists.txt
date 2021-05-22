cmake_minimum_required(VERSION 3.17)
project(noche)

set(CMAKE_CXX_STANDARD 17)

# lua54
add_subdirectory(3rdparty/lua54)
# sol2
add_subdirectory(3rdparty/sol2)

add_executable(noche main.cpp)
target_link_libraries(noche lua54)
target_link_libraries(noche sol2)