# MvC2 native port - host build of the decompiled game C (Port A).
#
# Compiles every credited game source (config/matches.csv) and data source
# (config/data_matches.csv) for a 32-bit host.  Sources are never edited:
# port/tools/hostify.py writes filtered copies into the build tree and
# port/include/ps2_compat.h is force-included.  Nothing here touches the
# matching build (tools/compile_matching.sh, make match/hybrid).
#
# PRIMARY target - browser (Emscripten, wasm32, 32-bit pointers):
#   source /home/user/emsdk/emsdk_env.sh
#   emcmake cmake -S port -B build/port-em -G Ninja
#   ninja -C build/port-em mvc2_game
# Desktop debug build (i386, 32-bit pointers; no 32-bit libc needed):
#   cmake -S port -B build/port-i386 -G Ninja \
#         -DCMAKE_TOOLCHAIN_FILE=$PWD/port/cmake/i386-clang.cmake
#   ninja -C build/port-i386 mvc2_game
# (port/cmake/wasm32-clang.cmake: bare wasm32-unknown-unknown, no emsdk.)
# The toolchain path must be absolute.  Fast per-TU probe with failure
# classes: python3 port/tools/probe_host_build.py --target emscripten|i386
#
# Stage 1 is compile-only: the static library is not linked into anything
# yet (functions with no honest C are listed by port/tools/list_c_less.py).
cmake_minimum_required(VERSION 3.20)
project(mvc2_port C)

get_filename_component(MVC2_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "mvc2 host port needs a 32-bit target (pointers live in u32 fields); "
                      "use port/cmake/i386-clang.cmake or port/cmake/wasm32-clang.cmake")
endif()

# ---- source lists (regenerated when the credit catalogs change) ----------
set(MVC2_LISTS "${CMAKE_BINARY_DIR}/mvc2_sources.cmake")
execute_process(
  COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/host_sources.py" "${MVC2_LISTS}" 200
  RESULT_VARIABLE _rc)
if(NOT _rc EQUAL 0)
  message(FATAL_ERROR "port/tools/host_sources.py failed")
endif()
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
  "${MVC2_ROOT}/config/matches.csv" "${MVC2_ROOT}/config/data_matches.csv")
include("${MVC2_LISTS}")

# ---- filtered source tree --------------------------------------------------
set(HSRC "${CMAKE_BINARY_DIR}/hsrc")
set(HOSTIFY_DEPS "${MVC2_ROOT}/port/tools/hostify.py" "${MVC2_ROOT}/port/tools/host_overrides.py" "${MVC2_ROOT}/port/tools/hostify_tree.py")

set(_hdr_out "")
set(_hdr_in "")
foreach(h IN LISTS MVC2_HEADERS)
  list(APPEND _hdr_out "${HSRC}/${h}")
  list(APPEND _hdr_in "${MVC2_ROOT}/${h}")
endforeach()
add_custom_command(
  OUTPUT ${_hdr_out}
  COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/hostify_tree.py" "${HSRC}" --headers
  DEPENDS ${_hdr_in} ${HOSTIFY_DEPS}
  WORKING_DIRECTORY "${MVC2_ROOT}"
  COMMENT "hostify: project headers")
add_custom_target(mvc2_hostify_headers DEPENDS ${_hdr_out})

math(EXPR _last "${MVC2_CHUNK_COUNT} - 1")
foreach(i RANGE 0 ${_last})
  set(_out "")
  set(_in "")
  foreach(s IN LISTS MVC2_CHUNK_${i})
    list(APPEND _out "${HSRC}/${s}")
    list(APPEND _in "${MVC2_ROOT}/${s}")
  endforeach()
  add_custom_command(
    OUTPUT ${_out}
    COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/hostify_tree.py" "${HSRC}" ${MVC2_CHUNK_${i}}
    DEPENDS ${_in} ${HOSTIFY_DEPS}
    WORKING_DIRECTORY "${MVC2_ROOT}"
    COMMENT "hostify: chunk ${i}")
endforeach()

set(MVC2_GAME_HSRC "")
foreach(s IN LISTS MVC2_GAME_SOURCES)
  list(APPEND MVC2_GAME_HSRC "${HSRC}/${s}")
endforeach()
set(MVC2_DATA_HSRC "")
foreach(s IN LISTS MVC2_DATA_SOURCES)
  list(APPEND MVC2_DATA_HSRC "${HSRC}/${s}")
endforeach()

# ---- flags (mirror port/tools/host_flags.py) ------------------------------
set(MVC2_HOST_OPTIONS
  -std=gnu99 -ffreestanding -nostdlibinc -fno-builtin -fno-common -fsigned-char
  -w
  -Wno-error=implicit-function-declaration -Wno-error=int-conversion
  -Wno-error=incompatible-pointer-types -Wno-error=implicit-int
  -Wno-error=return-type -Wno-error=incompatible-function-pointer-types
  "SHELL:-include ${MVC2_ROOT}/port/include/ps2_compat.h")
set(MVC2_HOST_INCLUDES
  "${HSRC}/src" "${HSRC}/src/data" "${MVC2_ROOT}/src" "${MVC2_ROOT}/src/data")

function(mvc2_object_lib name)
  add_library(${name} OBJECT ${ARGN})
  target_compile_options(${name} PRIVATE ${MVC2_HOST_OPTIONS})
  target_include_directories(${name} PRIVATE ${MVC2_HOST_INCLUDES})
  target_compile_definitions(${name} PRIVATE MVC2_HOST=1)
  add_dependencies(${name} mvc2_hostify_headers)
endfunction()

mvc2_object_lib(mvc2_game_code ${MVC2_GAME_HSRC})
mvc2_object_lib(mvc2_game_data ${MVC2_DATA_HSRC})

add_library(mvc2_game STATIC
  $<TARGET_OBJECTS:mvc2_game_code> $<TARGET_OBJECTS:mvc2_game_data>)
set_target_properties(mvc2_game PROPERTIES LINKER_LANGUAGE C)
