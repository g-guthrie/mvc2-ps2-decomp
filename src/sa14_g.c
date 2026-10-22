typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G1;
extern G1 *D_004C2794;

void func_002EF9C0(u8 *p)
{
    extern void func_001E3210(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_003A8B10(u8 *);
    extern s32 func_0018AB10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 t;
    s16 v;
    u32 u;
    u8 x;
    *(s32 *)(p + 0x308) = 4;
    t = *(s32 *)(p + 0x2EC) - 1;
    *(s32 *)(p + 0x2EC) = t;
    if (t < 0) {
        *(s32 *)(p + 0x2EC) = 0x10;
        func_001E3210(p, 3);
    }
    func_00175700(p);
    x = p[0x15B];
    if (x != 0) {
        { s32 sum = (s8)x; sum += (s8)p[0x2D4]; p[0x1B5] = sum; }
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x15B] = 0;
    }
    if ((s8)p[0x151] < 0) {
        p[0x151] = 0;
        func_003A8B10(p);
    }
    if (func_0018AB10(p) == 0 || (s8)p[0x539] != 0) {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u = p[6];
            p[6] = u + 1;
            u = p[0x168];
            func_001757E0(p, 0x15, (u8)(u + 1));
        }
    } else {
        *(s16 *)(p + 0x1C) = 0x1E;
    }
}
