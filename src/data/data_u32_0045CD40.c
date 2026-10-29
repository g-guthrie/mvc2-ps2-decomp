typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Record table passed (as $a1) to func_00189310, which compares the s8 at +4
   with a state byte and tests flag bits (0x20/0x100/0x800/0x1000/0x2000/0x4000)
   of the u16 at +2 in func_0018A460. */
typedef struct InputRec4 {
    u16 type;
    u16 flags;
    s8 idx;
    u8 pad[3];
    u16 w[4];
} InputRec4;
typedef char InputRec4_size_check[(sizeof(InputRec4) == 16) ? 1 : -1];

typedef struct InputRec6 {
    u16 type;
    u16 flags;
    s8 idx;
    u8 pad[3];
    u16 w[6];
    u32 pad2[3];
} InputRec6;
typedef char InputRec6_size_check[(sizeof(InputRec6) == 32) ? 1 : -1];

typedef struct Tbl_0045CD40 {
    InputRec4 m1[3];
    InputRec6 m2[2];
} Tbl_0045CD40;
typedef char Tbl_0045CD40_size_check[(sizeof(Tbl_0045CD40) == 112) ? 1 : -1];

Tbl_0045CD40 data_u32_0045CD40 = {
    {
    { 0x0003, 0x9100, 0, {0,0,0}, {0x1000, 0x1800, 0x0800, 0x0300} },
    { 0x0003, 0x9100, 1, {0,0,0}, {0x1000, 0x1800, 0x0800, 0x0060} },
    { 0x0003, 0x8100, 8, {0,0,0}, {0x1000, 0x1400, 0x0400, 0x0300} },
    },
    {
    { 0x0005, 0x1000, 2, {0,0,0}, {0x0400, 0x1400, 0x1000, 0x1800, 0x0800, 0x0300}, {0,0,0} },
    { 0x0005, 0x1000, 3, {0,0,0}, {0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0300}, {0,0,0} },
    },
};
