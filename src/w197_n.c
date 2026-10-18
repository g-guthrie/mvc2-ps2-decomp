typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G197n;
typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 b6; u8 b7; f32 f8; } T197n;
extern G197n *D_004C2794;
extern T197n *D_004C2974;

void func_003668F0(u8 *p) {
    extern void func_001E7F60(u8 *);
    extern void func_003670B0(u8 *);
    s16 v;
    switch (*(s16 *)(p + 0x1E) & 3) {
    case 0:
        *(f32 *)(p + 0x34) = D_004C2974->f8;
        break;
    case 1:
        *(f32 *)(p + 0x34) = D_004C2974->f8 - 3.3333332539f;
        break;
    case 2:
        *(f32 *)(p + 0x34) = D_004C2974->f8;
        break;
    case 3:
        *(f32 *)(p + 0x34) = 3.3333332539f + D_004C2974->f8;
        break;
    }
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        *(f32 *)(p + 0x34) = D_004C2974->f8;
        if (D_004C2974->b6 != 0) {
            p[5] = 9;
        } else {
            p[5] = 0;
            D_004C2974->b4 = 1;
            p[0x1B5] = 0x32;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            func_001E7F60(p);
        }
        func_003670B0(p);
    }
}
