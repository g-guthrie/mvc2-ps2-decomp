typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

/* Move-input record: type selects handler via D_00448F10; flags at +2 tested
   against masks (0x4000, 0x20, 0x800, ...) in func_0018A460; byte at +4 is
   compared with a state byte in func_00189310. */
typedef struct {
    u8 type;
    u8 pad;
    u16 flags;
    u32 id;
    u16 arg[4];
} MoveRec;
typedef char MoveRec_size_check[(sizeof(MoveRec) == 16) ? 1 : -1];
MoveRec data_u32_0045B720[8] = {
    { 3, 0, 0x0000, 0x00, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 3, 0, 0x9100, 0x02, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 4, 0, 0x000A, 0x03, { 0x0300, 0x0000, 0x0000, 0x0000 } },
    { 3, 0, 0x5080, 0x06, { 0x0800, 0x0000, 0x0800, 0x0300 } },
    { 3, 0, 0x1100, 0x0A, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 3, 0, 0x1100, 0x0B, { 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 3, 0, 0x8100, 0x08, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 3, 0, 0x1000, 0x03, { 0x0800, 0x1000, 0x1800, 0x0300 } },
};
