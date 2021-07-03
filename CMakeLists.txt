cmake_minimum_required(VERSION 3.17)
project(noche)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

aux_source_directory(application application)
aux_source_directory(object object)
aux_source_directory(debug debug)
aux_source_directory(io io)
aux_source_directory(reflection reflection)
aux_source_directory(event event)

# 3rdparty
include_directories(3rdparty)
include_directories(3rdparty/slimsig/include)

# spdlog
include_directories(3rdparty/spdlog/include)
add_subdirectory(3rdparty/spdlog)
# glad
include_directories(3rdparty/glad/include)
aux_source_directory(3rdparty/glad/src glad)
# glfw
include_directories(3rdparty/glfw/include)
add_subdirectory(3rdparty/glfw)
# yaml-cpp
include_directories(3rdparty/yaml-cpp/include)
add_subdirectory(3rdparty/yaml-cpp)
# lua54
add_subdirectory(3rdparty/lua54)
# sol2
add_subdirectory(3rdparty/sol2)
# imgui
include_directories(3rdparty/imgui)
include_directories(3rdparty/imgui/backends)
aux_source_directory(3rdparty/imgui imgui)
#aux_source_directory(3rdparty/imgui/backends imgui_backends)
set(imgui_backends 3rdparty/imgui/backends/imgui_impl_win32.cpp 3rdparty/imgui/backends/imgui_impl_glfw.cpp 3rdparty/imgui/backends/imgui_impl_opengl3.cpp)
# boehm
#include_directories(3rdparty/boehm-collector/include)
#add_subdirectory(3rdparty/boehm-collector)

add_executable(noche main.cpp ${object} ${debug} ${application} ${event} ${glad} ${imgui} ${imgui_backends})
target_link_libraries(noche glfw)
target_link_libraries(noche spdlog)
target_link_libraries(noche lua54)
target_link_libraries(noche sol2)
target_link_libraries(noche yaml-cpp)
#SET_TARGET_PROPERTIES(noche PROPERTIES COMPILE_DEFINITIONS GC_NOT_DLL)
#target_link_libraries(noche gc-lib)