# 32-bit x86 host build (pointers fit the game's u32 fields).
# No 32-bit libc headers are needed: game TUs are freestanding.
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR i386)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_COMPILER_TARGET i386-linux-gnu)
set(CMAKE_C_FLAGS_INIT "-m32 -malign-double")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
