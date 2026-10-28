# Bare wasm32 (no Emscripten): proves the game C compiles for the browser
# target's data model.  The Emscripten build uses emcmake instead.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR wasm32)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET wasm32-unknown-unknown)
set(CMAKE_AR llvm-ar CACHE FILEPATH "")
set(CMAKE_RANLIB llvm-ranlib CACHE FILEPATH "")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
