typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G;
extern G *D_004C2794;

typedef struct { u8 pad0[0x5C]; f32 f5c, f60; u8 pad64[4]; f32 f68, f6c; } T;

void func_00264E40(u8 *p)
{
    extern void func_00185490(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D10(u8 *);
    extern void func_00175C00(u8 *, s32);
    T *q = (T *)p;
    f32 x;
    f32 z = 0.0f;
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x18;
    *(s16 *)(p + 0x1E) = 0x1E;
    func_00185490(p);
    func_0018C4B0(p, 5);
    x = (p[0x1E6] != 0) ? 0.8333333f : -0.8333333f;
    q->f5c = x;
    q->f68 = z;
    if (p[0x20D] == 2) {
        q->f5c /= 16.0f;
        q->f60 /= 8.0f;
        q->f6c /= 64.0f;
        q->f68 = z;
        p[0x1B5] = 0x33;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 4);
    } else {
        p[0x20D] = 0;
        func_00183D10(p);
        p[0x1B5] = 0x33;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 2);
    }
    func_00175C00(p, 0);
}
