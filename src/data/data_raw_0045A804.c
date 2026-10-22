typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;
#pragma pack(1)
/* Tail slots of jtbl_0045A7F8, f32 (x,y) pairs D_0045A810 indexed by p[0x20B] * 8 (func_002D8A30), then padding and the
   skipped first byte of the u8 table D_0045A830. */
struct {
    u8 pad0[12];
    f32 pos[3][2];
    u8 pad1[8];
    u8 tab0;
} data_raw_0045A804 = {
    { 0 },
    { { -133.333328f, 308.571411f }, { -133.333328f, 308.571411f }, { 36.6666641f, 377.142853f } },
    { 0 },
    0
};
typedef char data_raw_0045A804_size_check[(sizeof(data_raw_0045A804) == 45) ? 1 : -1];
