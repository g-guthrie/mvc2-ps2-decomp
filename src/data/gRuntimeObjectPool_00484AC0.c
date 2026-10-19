/* Free runtime-object slots: 004000F8 clears 0xA00 bytes, 00400AF8 scans 40 slots.
 * The initializer and both allocators use the shared, verified 64-byte layout. */
#include "../runtime_object_storage.h"

RuntimeObjectStorage gRuntimeObjectPool_00484AC0[MVC2_RUNTIME_OBJECT_COUNT]
    __attribute__((section(".data"))) = { { 0 } };
