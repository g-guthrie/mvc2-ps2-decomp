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
# Stage 2 (Port G) links it: `ninja mvc2_host` builds the game library with
# hostify R11-R16, generates the link glue (port/tools/gen_link_glue.py) and
# links port/stubs + glue + mvc2_game into an executable (mvc2_host, or
# mvc2_host.js/.wasm on Emscripten).  See port/docs/LINK_NOTES.md.
#   MVC2_HOST_SIGS=<host_sigs.json>  reuse a signature table (default: the
#   build runs the raw wasm build itself into <build>/sigs_raw, ~2 min)
#   MVC2_HOST_SIGS=OFF               no R12-R14 (i386 only; wasm needs them)
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

# ---- canonical signatures (hostify R12-R14) ---------------------------------
set(HOSTIFY_DEPS "${MVC2_ROOT}/port/tools/hostify.py" "${MVC2_ROOT}/port/tools/host_overrides.py"
  "${MVC2_ROOT}/port/tools/hostify_tree.py" "${MVC2_ROOT}/port/tools/link_catalog.py")
set(MVC2_HOST_SIGS "" CACHE STRING "host_sigs.json for hostify R12-R14 (empty: generate; OFF: none)")
set(MVC2_SIGS_ARGS "")
set(MVC2_SIGS_DEP "")
if(MVC2_HOST_SIGS STREQUAL "OFF")
  if(EMSCRIPTEN)
    message(FATAL_ERROR "the wasm link needs hostify R12-R14 (MVC2_HOST_SIGS must not be OFF)")
  endif()
elseif(MVC2_HOST_SIGS STREQUAL "")
  set(_sigs "${CMAKE_BINARY_DIR}/host_sigs.json")
  file(GLOB _stub_srcs "${MVC2_ROOT}/port/stubs/*.c" "${MVC2_ROOT}/port/stubs/*.h")
  add_custom_command(
    OUTPUT "${_sigs}"
    COMMAND ${CMAKE_COMMAND} -E env --unset=MVC2_HOST_SIGS
            ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/gen_link_glue.py" sigs
            --out "${_sigs}" --raw-build "${CMAKE_BINARY_DIR}/sigs_raw"
    DEPENDS ${HOSTIFY_DEPS} ${_stub_srcs} "${MVC2_ROOT}/port/tools/host_sigs.py"
            "${MVC2_ROOT}/port/tools/wasm_obj.py" "${MVC2_ROOT}/port/tools/probe_host_build.py"
            "${MVC2_ROOT}/config/matches.csv" "${MVC2_ROOT}/config/data_matches.csv"
            "${MVC2_ROOT}/config/symbol_addrs.txt"
    WORKING_DIRECTORY "${MVC2_ROOT}"
    USES_TERMINAL
    COMMENT "host_sigs.json: raw wasm build + signature scan (gen_link_glue.py sigs)")
  set(MVC2_SIGS_ARGS --sigs "${_sigs}")
  set(MVC2_SIGS_DEP "${_sigs}")
  set(MVC2_SIGS_FILE "${_sigs}")
else()
  set(MVC2_SIGS_ARGS --sigs "${MVC2_HOST_SIGS}")
  set(MVC2_SIGS_DEP "${MVC2_HOST_SIGS}")
  set(MVC2_SIGS_FILE "${MVC2_HOST_SIGS}")
endif()

# ---- filtered source tree --------------------------------------------------
set(HSRC "${CMAKE_BINARY_DIR}/hsrc")

set(_hdr_out "")
set(_hdr_in "")
foreach(h IN LISTS MVC2_HEADERS)
  list(APPEND _hdr_out "${HSRC}/${h}")
  list(APPEND _hdr_in "${MVC2_ROOT}/${h}")
endforeach()
add_custom_command(
  OUTPUT ${_hdr_out}
  COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/hostify_tree.py" "${HSRC}" ${MVC2_SIGS_ARGS} --headers
  DEPENDS ${_hdr_in} ${HOSTIFY_DEPS} ${MVC2_SIGS_DEP}
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
    COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/hostify_tree.py" "${HSRC}" ${MVC2_SIGS_ARGS} ${MVC2_CHUNK_${i}}
    DEPENDS ${_in} ${HOSTIFY_DEPS} ${MVC2_SIGS_DEP}
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
if(EMSCRIPTEN)
  # emsdk clang directly for the 16k freestanding game TUs (emcc's Python
  # start-up per file would dominate the build).
  set_target_properties(mvc2_game_code mvc2_game_data PROPERTIES
    C_COMPILER_LAUNCHER "${CMAKE_CURRENT_SOURCE_DIR}/cmake/emcc-direct.sh")
endif()

add_library(mvc2_game STATIC
  $<TARGET_OBJECTS:mvc2_game_code> $<TARGET_OBJECTS:mvc2_game_data>)
set_target_properties(mvc2_game PROPERTIES LINKER_LANGUAGE C)

# ---- link (Port G): glue + stubs + game -> mvc2_host -------------------------
set(GLUE "${CMAKE_BINARY_DIR}/glue")
set(GLUE_SRCS "${GLUE}/mvc2_glue_data.c" "${GLUE}/mvc2_glue_stubs.c" "${GLUE}/mvc2_glue_table.c")
if(EMSCRIPTEN)
  set(_glue_target emscripten)
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "wasm32")
  set(_glue_target wasm32)
else()
  set(_glue_target i386)
endif()
set(_glue_sigs "")
if(MVC2_SIGS_FILE)
  set(_glue_sigs --sigs "${MVC2_SIGS_FILE}")
endif()
file(GLOB MVC2_STUB_SRCS "${MVC2_ROOT}/port/stubs/*.c")
add_custom_command(
  OUTPUT ${GLUE_SRCS} "${GLUE}/link_extra.rsp" "${GLUE}/stubs.csv" "${GLUE}/link_glue.csv"
  COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/gen_link_glue.py" glue
          --out "${GLUE}" --target ${_glue_target} ${_glue_sigs} "$<TARGET_FILE:mvc2_game>"
  DEPENDS mvc2_game "${MVC2_ROOT}/port/tools/gen_link_glue.py" "${MVC2_ROOT}/port/tools/link_catalog.py"
          ${MVC2_STUB_SRCS} ${MVC2_SIGS_DEP}
  WORKING_DIRECTORY "${MVC2_ROOT}"
  COMMENT "gen_link_glue.py: BSS/data/stub glue for the host link")

add_executable(mvc2_host ${MVC2_STUB_SRCS} ${GLUE_SRCS})
target_include_directories(mvc2_host PRIVATE "${MVC2_ROOT}/port/stubs")
target_compile_options(mvc2_host PRIVATE -fno-common)
target_link_libraries(mvc2_host PRIVATE mvc2_game)
if(EMSCRIPTEN)
  # --fatal-warnings: any call/definition signature mismatch is a link error
  # (hostify R12 is expected to leave none).
  target_link_options(mvc2_host PRIVATE -Wl,--fatal-warnings
    -sINITIAL_MEMORY=134217728 -sALLOW_MEMORY_GROWTH=1 -sSTACK_SIZE=1048576 -sEXIT_RUNTIME=1)
  # Direct calls are exact after R12, but the game also calls through
  # callback tables whose element type rarely matches each callee (MIPS does
  # not care); a wasm call_indirect with another type traps.  Emscripten's
  # function-pointer-cast emulation adapts those calls at run time.
  option(MVC2_EMULATE_FPCASTS "Emscripten EMULATE_FUNCTION_POINTER_CASTS for callback tables" ON)
  if(MVC2_EMULATE_FPCASTS)
    target_link_options(mvc2_host PRIVATE -sEMULATE_FUNCTION_POINTER_CASTS=1)
  endif()
  set_target_properties(mvc2_host PROPERTIES SUFFIX ".js")
else()
  target_link_options(mvc2_host PRIVATE -no-pie "@${GLUE}/link_extra.rsp")
  target_link_libraries(mvc2_host PRIVATE m)
endif()
