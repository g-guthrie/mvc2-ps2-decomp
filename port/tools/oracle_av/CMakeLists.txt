# mvc2_av: mvc2_oracle + Play!'s OpenGL GS (headless EGL/GLES) and the SPU2
# output, for the picture/sound comparison (see build.sh, compare_av.py).
# -DPLAY_DIR=<Play! source tree with ../oracle/play.patch and play_av.patch>
cmake_minimum_required(VERSION 3.18)
set(CMAKE_MODULE_PATH ${PLAY_DIR}/deps/Dependencies/cmake-modules ${CMAKE_MODULE_PATH})
include(Header)
project(mvc2_av)
set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(DEBUGGER_INCLUDED)
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
# GLES through EGL (no GLEW, no window system): Mesa's surfaceless platform
set(USE_GLES ON CACHE BOOL "" FORCE)
add_subdirectory(${PLAY_DIR}/Source ${CMAKE_CURRENT_BINARY_DIR}/Source)
add_subdirectory(${PLAY_DIR}/Source/gs/GSH_OpenGL ${CMAKE_CURRENT_BINARY_DIR}/GSH_OpenGL)
find_package(PNG REQUIRED)
add_executable(mvc2_av mvc2_av.cpp)
target_include_directories(mvc2_av PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../oracle ${PLAY_DIR}/Source)
target_link_libraries(mvc2_av gsh_opengl PlayCore PNG::PNG EGL GLESv2)
