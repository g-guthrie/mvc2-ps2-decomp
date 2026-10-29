# Port F front end: platform layer (SDL2), GL ES 3 / WebGL2 renderer, apps.
#
# Additive to Port A's port/CMakeLists.txt (target mvc2_game): it only defines
#   port_platform  (static)  port/platform/*.c
#   port_render    (static)  port/render/*.c (2D, characters, meshes)
#   viewer         (exe)     port/apps/viewer.c   (-> viewer.html/.js/.wasm on Emscripten)
#   port_audio     (static)  port/audio/*.c        (Port I: music, SE/voice driver, SDL output)
#   soundtest      (exe)     port/apps/soundtest.c (-> soundtest.html on Emscripten)
# and never links mvc2_game. Include it from any project with
#   set(PORT_ROOT <path to port/>) ; include(${PORT_ROOT}/cmake/frontend.cmake)
# Standalone builds (native 64-bit debug or web): port/frontend/CMakeLists.txt.
# Nothing here assumes 32-bit pointers.
if(NOT PORT_ROOT)
  get_filename_component(PORT_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
endif()

add_library(port_platform STATIC
  ${PORT_ROOT}/platform/gl_load.c ${PORT_ROOT}/platform/fs.c ${PORT_ROOT}/platform/pad.c
  ${PORT_ROOT}/platform/touch.c ${PORT_ROOT}/platform/platform_sdl.c ${PORT_ROOT}/platform/png_write.c)
add_library(port_render STATIC
  ${PORT_ROOT}/render/r_gl.c ${PORT_ROOT}/render/r_char.c ${PORT_ROOT}/render/r_mesh.c
  ${PORT_ROOT}/render/decode.c)
set_property(TARGET port_platform port_render PROPERTY C_STANDARD 11)
# Port I audio: ADX / VAG decoders, HD bank, hsyn-style synth, Tamsoft driver,
# the game's TSD client boundary, ADXT-shaped BGM player, SDL output.
add_library(port_audio STATIC
  ${PORT_ROOT}/audio/adx.c ${PORT_ROOT}/audio/vag.c ${PORT_ROOT}/audio/hdbank.c
  ${PORT_ROOT}/audio/resample.c ${PORT_ROOT}/audio/synth.c ${PORT_ROOT}/audio/tsd.c
  ${PORT_ROOT}/audio/tsd_client.c ${PORT_ROOT}/audio/audio.c ${PORT_ROOT}/audio/wav.c)
set_property(TARGET port_audio PROPERTY C_STANDARD 11)
add_executable(soundtest ${PORT_ROOT}/apps/soundtest.c)
set_property(TARGET soundtest PROPERTY C_STANDARD 11)
target_link_libraries(soundtest PRIVATE port_audio port_render port_platform)
add_executable(viewer ${PORT_ROOT}/apps/viewer.c)
set_property(TARGET viewer PROPERTY C_STANDARD 11)
target_link_libraries(viewer PRIVATE port_render port_platform)

if(EMSCRIPTEN)
  # SDL2 + WebGL2 from the emsdk ports; no threads; rAF main loop.
  # If the port download is blocked: git clone -b release-2.32.10 SDL and
  # export EMCC_LOCAL_PORTS=sdl2=/path/to/SDL (see port/docs/RENDERER.md).
  foreach(t port_platform port_render port_audio viewer soundtest)
    target_compile_options(${t} PRIVATE -sUSE_SDL=2)
  endforeach()
  set_target_properties(soundtest PROPERTIES SUFFIX ".html")
  target_link_options(soundtest PRIVATE
    -sUSE_SDL=2 -sMAX_WEBGL_VERSION=2 -sMIN_WEBGL_VERSION=2 -sFULL_ES3
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB -sMAXIMUM_MEMORY=2GB
    -sFORCE_FILESYSTEM=1
    -sEXPORTED_FUNCTIONS=_main,_viewer_open_js
    -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,FS
    --shell-file ${PORT_ROOT}/web/shell.html)
  set_target_properties(viewer PROPERTIES SUFFIX ".html")
  target_link_options(viewer PRIVATE
    -sUSE_SDL=2 -sMAX_WEBGL_VERSION=2 -sMIN_WEBGL_VERSION=2 -sFULL_ES3
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB -sMAXIMUM_MEMORY=2GB
    -sFORCE_FILESYSTEM=1
    -sEXPORTED_FUNCTIONS=_main,_viewer_open_js
    -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,FS
    --shell-file ${PORT_ROOT}/web/shell.html)
  set_property(TARGET viewer APPEND PROPERTY LINK_DEPENDS ${PORT_ROOT}/web/shell.html)
  # One .html with the wasm and JS inlined (input to port/tools/pack_personal.py).
  option(PORT_SINGLE_FILE "inline wasm/js into the .html" OFF)
  if(PORT_SINGLE_FILE)
    target_link_options(viewer PRIVATE -sSINGLE_FILE=1)
  endif()
  # Local testing only: bake a file from private/ into viewer.data as /disc.iso.
  set(PORT_PRELOAD "" CACHE STRING "file to --preload-file as /disc.iso (local testing only)")
  if(PORT_PRELOAD)
    target_link_options(viewer PRIVATE --preload-file ${PORT_PRELOAD}@/disc.iso)
  endif()
  foreach(f manifest.webmanifest sw.js icon-192.png icon-512.png)
    configure_file(${PORT_ROOT}/web/${f} ${CMAKE_CURRENT_BINARY_DIR}/${f} COPYONLY)
  endforeach()
else()
  find_package(SDL2 REQUIRED)
  target_include_directories(port_platform PUBLIC ${SDL2_INCLUDE_DIRS})
  target_link_libraries(port_platform PUBLIC ${SDL2_LIBRARIES} m)
  target_include_directories(viewer PRIVATE ${SDL2_INCLUDE_DIRS})
  target_include_directories(port_audio PUBLIC ${SDL2_INCLUDE_DIRS})
  target_link_libraries(port_audio PUBLIC ${SDL2_LIBRARIES} m)
  if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    foreach(t port_platform port_render port_audio viewer soundtest)
      target_compile_options(${t} PRIVATE -Wall -Wextra -Wno-unused-parameter)
    endforeach()
  endif()
endif()
