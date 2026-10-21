#include "mvc2_record_triplet.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;
void func_0019FF60(u8 *entry, u8 *done, u8 *source)
{
    s32 remaining;
    u32 *destination;
    u32 *record;
    record = (u32 *)(source + 0xEC);
    destination = (u32 *)(entry + 0xEC);
    remaining = 0x31;
    entry[4]++;
    while (remaining > 0) {
        *destination++ = *record++;
        remaining--;
    }
    entry[0x13C] = 1;
    entry[2] = source[2];
    entry[1] = source[1];
    *(f32 *)(entry + 0x50) = *(f32 *)(source + 0x50);
    *(f32 *)(entry + 0x54) = *(f32 *)(source + 0x54);
    entry[0x1B7] = source[0x1B7];
    entry[0x1B8] = source[0x1B8];
    *(signed char *)(entry + 0x30) = *(signed char *)(source + 0x30);
    *(Vec3 *)(entry + 0x50) = *(Vec3 *)(source + 0x50);
    *(signed char *)(entry + 0x24) = *(signed char *)(source + 0x24);
    entry[0x13C] = 0;
    *done = 0;
}
