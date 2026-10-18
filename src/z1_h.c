typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[1]; } G94;
extern G94 *D_004C2794;

typedef struct { f32 x, y, z; } V3;

typedef struct {
    u8 pad0[0x34];
    V3 v34;
    u8 pad40[0x15B - 0x40];
    u8 b15B;
    u8 pad15C[0x168 - 0x15C];
    s16 h168;
} O382;

void func_00382120(u8 *p) {
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_001E7F60(u8 *);
    O382 *o = *(O382 **)(p + 0x18);
    u32 r;
    p[0x13C] = 0;
    r = o->b15B;
    if (r == 0xFF || *(s16 *)(p + 0x1E) != o->h168) {
        p[4] = 2;
        return;
    }
    if (r == 0) return;
    p[0x13C] = 1;
    *(V3 *)(p + 0x34) = o->v34;
    if (o->b15B != p[0x22]) {
        p[0x22] = o->b15B;
        func_00175910(p, 0x17, 4, p[0x22] - 1);
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            p[0x1B5] = *(volatile s8 *)(p + 0x15B) + 0x38;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->h7C[p[2]]++;
        }
    }
    func_001E7F60(p);
}

void func_00300E40(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 D_004C1468[2];
    extern u8 D_004C146C[2];
    extern u8 D_004C1470[2];
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(u8 **)(p + 0x408) = D_004C1468;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(u8 **)(p + 0x408) = D_004C146C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(u8 **)(p + 0x408) = D_004C1470;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}
