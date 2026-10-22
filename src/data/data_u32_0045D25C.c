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

typedef struct Tbl_0045D25C {
    u16 m0[2];
    InputRec4 m1[5];
    InputRec6 m2[1];
} Tbl_0045D25C;
typedef char Tbl_0045D25C_size_check[(sizeof(Tbl_0045D25C) == 116) ? 1 : -1];

Tbl_0045D25C data_u32_0045D25C = {
    { 0x0000, 0x0000 },
    {
    { 0x0028, 0x1000, 0, {0,0,0}, {0x0400, 0x0800, 0x0300, 0x0000} },
    { 0x0028, 0x1000, 1, {0,0,0}, {0x1000, 0x2000, 0x0300, 0x0000} },
    { 0x0003, 0x9100, 2, {0,0,0}, {0x1000, 0x1400, 0x0400, 0x0300} },
    { 0x0003, 0x9100, 3, {0,0,0}, {0x1000, 0x1800, 0x0800, 0x0300} },
    { 0x0003, 0x9100, 4, {0,0,0}, {0x1000, 0x1800, 0x0800, 0x0060} },
    },
    {
    { 0x0005, 0x1000, 5, {0,0,0}, {0x0800, 0x1800, 0x1000, 0x1400, 0x0400, 0x0060}, {0,0,0} },
    },
};
