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
typedef struct {
    u8 type;
    u8 pad;
    u16 flags;
    u32 id;
    u16 arg[6];
} MoveRec5;
typedef struct {
    u32 pad0[3];       /* tail of the preceding table */
    MoveRec r0, r1;
    MoveRec5 r2;
    u32 pad1[3];
    MoveRec r3, r4, r5;
} MoveBlock;
typedef char MoveBlock_size_check[(sizeof(MoveBlock) == 124) ? 1 : -1];
MoveBlock data_u32_0045B3B4 = {
    { 0, 0, 0 },
    { 3, 0, 0x0000, 0x02, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 3, 0, 0x1000, 0x0C, { 0x1000, 0x1800, 0x0800, 0x0060 } },
    { 5, 0, 0x1000, 0x00, { 0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300 } },
    { 0, 0, 0 },
    { 3, 0, 0x8000, 0x05, { 0x1000, 0x1400, 0x0400, 0x0060 } },
    { 3, 0, 0x9100, 0x01, { 0x1000, 0x1800, 0x0800, 0x0300 } },
    { 3, 0, 0x9100, 0x06, { 0x1000, 0x1800, 0x0800, 0x0060 } },
};
