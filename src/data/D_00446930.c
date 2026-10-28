typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Same layout as ResourceRecord (src/runtime_resource_record.h); the
 * payload is the serialized u32 offset form so the -1 terminator can be
 * spelled. */
typedef struct {
    s16 id;
    u16 type;
    u32 flags;
    u32 payload;
    s32 attributes;
} ResourceRecordInit;
typedef char ResourceRecordInit_size_check[(sizeof(ResourceRecordInit) == 16) ? 1 : -1];
/* All-ones terminator record copied whole by func_0016FD80
 * (src/resource_record_passes_0016fd80.c: rows[4] = D_00446930). */
ResourceRecordInit D_00446930 = { -1, 0xFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, -1 };
