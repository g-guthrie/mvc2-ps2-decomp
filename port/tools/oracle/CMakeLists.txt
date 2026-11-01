# mvc2_oracle: the retail game in the Play! core, headless (see build.sh).
# -DPLAY_DIR=<Play! source tree with play.patch applied>
cmake_minimum_required(VERSION 3.18)
set(CMAKE_MODULE_PATH ${PLAY_DIR}/deps/Dependencies/cmake-modules ${CMAKE_MODULE_PATH})
include(Header)
project(mvc2_oracle)
set(CMAKE_CXX_STANDARD 17)
# the breakpoint prolog is the per-frame hook
add_compile_definitions(DEBUGGER_INCLUDED)
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(${PLAY_DIR}/Source ${CMAKE_CURRENT_BINARY_DIR}/Source)
add_executable(mvc2_oracle mvc2_oracle.cpp)
target_include_directories(mvc2_oracle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mvc2_oracle PlayCore)
