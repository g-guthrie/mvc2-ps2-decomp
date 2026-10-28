# Standalone build of the Port F front end (viewer). Native (any pointer size)
# or Emscripten; see CMakePresets.json here:
#   cmake --preset native && cmake --build --preset native
#   source /home/user/emsdk/emsdk_env.sh && cmake --preset web && cmake --build --preset web
cmake_minimum_required(VERSION 3.16)
project(mvc2_frontend C)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
get_filename_component(PORT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
include(${PORT_ROOT}/cmake/frontend.cmake)
