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
/* One resource record and its all-ones terminator, the same pair shape as
 * D_004A6F20 (src/initialize_runtime_menu_notice_00420560.c). The 32-byte
 * stride is shown by sa28_b.c (T3 D_004468D0[2], D_004468F0[2]).
 * q1_g.c writes payload D_004468F8; sa28_b.c passes &D_004468D0[1] to func_00415140. */
typedef struct { ResourceRecordInit records[2]; } ResourceRecordPairInit;
ResourceRecordPairInit D_004468F0 = {
    { { 64, 0x0040u, 0x00000102u, 0x00000000u, 0 },
      { -1, 0xFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, -1 } }
};
