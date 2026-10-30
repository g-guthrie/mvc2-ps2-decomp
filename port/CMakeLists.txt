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
  "${MVC2_ROOT}/port/tools/hostify_tree.py" "${MVC2_ROOT}/port/tools/link_catalog.py"
  "${MVC2_ROOT}/port/tools/r12_regpass.csv"
  "${MVC2_ROOT}/port/tools/r12_regexpr.csv"
  "${MVC2_ROOT}/port/tools/r12_widen.csv"
  "${MVC2_ROOT}/port/tools/r12_tailfwd.csv")
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
  DEPENDS ${_hdr_in} ${HOSTIFY_DEPS} ${MVC2_SIGS_DEP} "${MVC2_ROOT}/port/host/host_impl.csv"
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
    DEPENDS ${_in} ${HOSTIFY_DEPS} ${MVC2_SIGS_DEP} "${MVC2_ROOT}/port/host/host_impl.csv"
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
# Port J: data TUs in EE address order after the hole before the first unit
# (hostify R18); mvc2_host links these objects directly, in this order.
mvc2_object_lib(mvc2_game_data "${MVC2_DATA_START}" ${MVC2_DATA_HSRC})
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
         "${GLUE}/mvc2_host_protos.h"
  COMMAND ${Python3_EXECUTABLE} "${MVC2_ROOT}/port/tools/gen_link_glue.py" glue
          --out "${GLUE}" --target ${_glue_target} ${_glue_sigs} "$<TARGET_FILE:mvc2_game>"
  DEPENDS mvc2_game "${MVC2_ROOT}/port/tools/gen_link_glue.py" "${MVC2_ROOT}/port/tools/link_catalog.py"
          ${MVC2_STUB_SRCS} ${MVC2_SIGS_DEP} "${MVC2_ROOT}/port/host/host_impl.csv"
  WORKING_DIRECTORY "${MVC2_ROOT}"
  COMMENT "gen_link_glue.py: BSS/data/stub glue for the host link")

# Port J: host implementations of game functions (port/host/host_impl.csv).
# core = port/host/*.c (here and in the mvc2 app); frontend = port/host/fe/*.c.
file(GLOB MVC2_HOST_CORE_SRCS CONFIGURE_DEPENDS "${MVC2_ROOT}/port/host/*.c")
set(MVC2_PLATFORM_CORE_SRCS "${MVC2_ROOT}/port/platform/fs.c" "${MVC2_ROOT}/port/platform/pad.c"
  "${MVC2_ROOT}/port/audio/tsd_client.c")
add_library(mvc2_host_core OBJECT ${MVC2_HOST_CORE_SRCS} ${MVC2_PLATFORM_CORE_SRCS})
target_include_directories(mvc2_host_core PRIVATE "${MVC2_ROOT}/port/stubs" "${MVC2_ROOT}/port/host"
  "${MVC2_ROOT}/port/platform" "${GLUE}")
target_compile_options(mvc2_host_core PRIVATE -fno-common -Wall -Wno-unused-function)
set_source_files_properties(${MVC2_HOST_CORE_SRCS} PROPERTIES OBJECT_DEPENDS "${GLUE}/mvc2_host_protos.h")

add_executable(mvc2_host ${MVC2_STUB_SRCS} ${GLUE_SRCS} $<TARGET_OBJECTS:mvc2_host_core>
  $<TARGET_OBJECTS:mvc2_game_data>)
target_include_directories(mvc2_host PRIVATE "${MVC2_ROOT}/port/stubs")
target_compile_options(mvc2_host PRIVATE -fno-common)
target_link_libraries(mvc2_host PRIVATE mvc2_game)
if(EMSCRIPTEN)
  # --fatal-warnings: any call/definition signature mismatch is a link error
  # (hostify R12 is expected to leave none).
  target_link_options(mvc2_host PRIVATE -Wl,--fatal-warnings
    -sINITIAL_MEMORY=134217728 -sALLOW_MEMORY_GROWTH=1 -sSTACK_SIZE=1048576 -sEXIT_RUNTIME=1
    # mvc2_host is the node (headless) runner: host files directly, named frames
    -sNODERAWFS=1 --profiling-funcs "-Wl,-Map=${CMAKE_BINARY_DIR}/mvc2_host.map"
    # keep every EE data unit (unreferenced ones too): the image must stay contiguous (R18)
    -Wl,--no-gc-sections)
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
  # --sort-section=name: the .data.ee_<address> sections in EE order (R18)
  target_link_options(mvc2_host PRIVATE -no-pie "@${GLUE}/link_extra.rsp" -Wl,--sort-section=name)
  target_link_libraries(mvc2_host PRIVATE m)
endif()

# ---- the app (Port J): mvc2 = game + host + frontend (SDL2, GL, audio) -------
# Native i386: SDL2 2.x i386 runtime (libsdl2-2.0-0:i386) + the system SDL2
# headers; GL is loaded through SDL.  Web: SDL2/WebGL2 port + port/web/shell.html
# (the same page as the viewer, so port/tools/pack_personal.py works on it).
option(MVC2_APP "build the mvc2 app (SDL2 frontend)" ON)
if(MVC2_APP)
  set(PORT_DIR "${MVC2_ROOT}/port")
  file(GLOB MVC2_FE_SRCS CONFIGURE_DEPENDS "${PORT_DIR}/host/fe/*.c")
  set(MVC2_APP_STUBS ${MVC2_STUB_SRCS})
  list(FILTER MVC2_APP_STUBS EXCLUDE REGEX "host_main\\.c$")
  set(MVC2_FE_PLATFORM ${PORT_DIR}/platform/gl_load.c ${PORT_DIR}/platform/touch.c
    ${PORT_DIR}/platform/platform_sdl.c ${PORT_DIR}/platform/png_write.c)
  set(MVC2_FE_RENDER ${PORT_DIR}/render/r_gl.c ${PORT_DIR}/render/r_char.c
    ${PORT_DIR}/render/r_mesh.c ${PORT_DIR}/render/decode.c)
  set(MVC2_FE_AUDIO ${PORT_DIR}/audio/adx.c ${PORT_DIR}/audio/vag.c ${PORT_DIR}/audio/hdbank.c
    ${PORT_DIR}/audio/resample.c ${PORT_DIR}/audio/synth.c ${PORT_DIR}/audio/tsd.c
    ${PORT_DIR}/audio/audio.c ${PORT_DIR}/audio/wav.c)
  add_library(mvc2_fe OBJECT ${MVC2_FE_SRCS} ${MVC2_FE_PLATFORM} ${MVC2_FE_RENDER} ${MVC2_FE_AUDIO})
  set_property(TARGET mvc2_fe PROPERTY C_STANDARD 11)
  target_include_directories(mvc2_fe PRIVATE "${MVC2_ROOT}/port/stubs" "${MVC2_ROOT}/port/host"
    "${MVC2_ROOT}/port/platform" "${GLUE}")
  set_source_files_properties(${MVC2_FE_SRCS} PROPERTIES OBJECT_DEPENDS "${GLUE}/mvc2_host_protos.h")
  add_executable(mvc2 ${MVC2_APP_STUBS} ${GLUE_SRCS} $<TARGET_OBJECTS:mvc2_host_core>
    $<TARGET_OBJECTS:mvc2_game_data> $<TARGET_OBJECTS:mvc2_fe>)
  target_include_directories(mvc2 PRIVATE "${MVC2_ROOT}/port/stubs")
  target_link_libraries(mvc2 PRIVATE mvc2_game)
  if(EMSCRIPTEN)
    target_compile_options(mvc2_fe PRIVATE -sUSE_SDL=2)
    set_target_properties(mvc2 PROPERTIES SUFFIX ".html")
    target_link_options(mvc2 PRIVATE -Wl,--fatal-warnings -Wl,--no-gc-sections
      -sUSE_SDL=2 -sMAX_WEBGL_VERSION=2 -sMIN_WEBGL_VERSION=2 -sFULL_ES3
      -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=268435456 -sMAXIMUM_MEMORY=2GB -sSTACK_SIZE=1048576
      -sFORCE_FILESYSTEM=1 -sEXPORTED_FUNCTIONS=_main,_viewer_open_js
      -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,FS,IDBFS,addRunDependency,removeRunDependency -lidbfs.js --profiling-funcs
      --shell-file ${PORT_DIR}/web/shell.html)
    if(MVC2_EMULATE_FPCASTS)
      target_link_options(mvc2 PRIVATE -sEMULATE_FUNCTION_POINTER_CASTS=1)
    endif()
    set_property(TARGET mvc2 APPEND PROPERTY LINK_DEPENDS ${PORT_DIR}/web/shell.html)
    option(PORT_SINGLE_FILE "inline wasm/js into mvc2.html (input to port/tools/pack_personal.py)" OFF)
    if(PORT_SINGLE_FILE)
      target_link_options(mvc2 PRIVATE -sSINGLE_FILE=1)
    endif()
    foreach(f manifest.webmanifest sw.js icon-192.png icon-512.png)
      configure_file(${PORT_DIR}/web/${f} ${CMAKE_CURRENT_BINARY_DIR}/${f} COPYONLY)
    endforeach()
  else()
    set(MVC2_SDL2_INCLUDE "/usr/include/SDL2" CACHE PATH "SDL2 headers")
    find_library(MVC2_SDL2_LIB NAMES SDL2-2.0 SDL2 libSDL2-2.0.so.0
      PATHS /usr/lib/i386-linux-gnu NO_DEFAULT_PATH)
    if(NOT MVC2_SDL2_LIB AND EXISTS /usr/lib/i386-linux-gnu/libSDL2-2.0.so.0)
      set(MVC2_SDL2_LIB /usr/lib/i386-linux-gnu/libSDL2-2.0.so.0)
    endif()
    # The system SDL2 headers are multiarch (x86_64): SDL_config.h includes
    # <SDL2/_real_SDL_config.h>, which already has the 32-bit branches.
    file(GLOB _sdl_real /usr/include/*-linux-gnu/SDL2/_real_SDL_config.h)
    if(_sdl_real)
      list(GET _sdl_real 0 _sdl_real)
      file(COPY ${_sdl_real} DESTINATION ${CMAKE_BINARY_DIR}/sdl2_shim/SDL2)
    endif()
    target_include_directories(mvc2_fe PRIVATE ${MVC2_SDL2_INCLUDE} ${CMAKE_BINARY_DIR}/sdl2_shim)
    target_link_options(mvc2 PRIVATE -no-pie "@${GLUE}/link_extra.rsp" -Wl,--sort-section=name)
    target_link_libraries(mvc2 PRIVATE ${MVC2_SDL2_LIB} m)
  endif()
endif()
