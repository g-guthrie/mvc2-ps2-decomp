typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 D_004C1DC8[];
extern u8 D_004C1DCC[];
extern u8 D_004C1DD0[];
typedef struct {
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u32 e;
} PtrRec;
typedef struct {
    s16 a;
    s16 b;
    u32 c;
    u16 d0;
    s16 d1;
    u32 e;
} Rec16;
typedef struct {
    s16 a;
    s16 b;
    u32 c;
} Tail8;
typedef struct {
    PtrRec p;
    Rec16 r[6];
    Tail8 t;
} Tab;
Tab data_u32_00471978 = {
    {D_004C1DC8, D_004C1DCC, D_004C1DD0, 0x00000000u},
    {
        {-30696, 0, 0x00009058u, 0x9058u, 0, 0x00000000u},
        {0, 0, 0x00000000u, 0x0000u, -10, 0x00000000u},
        {-13, 34, 0x00004011u, 0x0000u, -10, 0x00000000u},
        {7, 81, 0x0000410Fu, 0x0000u, -10, 0x00000000u},
        {23, 31, 0x0000420Du, 0x8000u, -8, 0x00000000u},
        {-7, 96, 0x0000430Bu, 0x8000u, -8, 0x00000000u},
    },
    {-20, 99, 0x0000430Bu},
};
