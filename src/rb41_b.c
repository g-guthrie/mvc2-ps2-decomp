typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0xD0]; u32 fD0; } OS;
typedef struct { V3 a; V3 b; f32 pad; } E28;
typedef struct { f32 f[4]; } V4;
extern u32 D_004C2804;
extern u32 D_004C27E4;
extern V4 D_004439B0;
extern u8 *D_00443480[];
extern u8 residual_001487B0[];

u8 *func_00147920(u8 *p, u32 n, s32 idx) {
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_00147D20(u8 *);
    u8 *o;
    u8 *q;
    s32 i;

    q = D_00443480[idx];
    i = 1;
    for (;;) {
        o = func_003DA750(p, 0xD, 3);
        if (o == 0) break;
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)residual_001487B0;
        o[0x23] = n;
        o[0x20] = p[0x20];
        o[0x21] = i++;
        *(u32 *)(o + 0xC8) = (u32)(p + 0x88);
        if (!(*(s8 *)(q + 0x1A) & 0x80)) {
            *(u16 *)(o + 0xCC) = *(u16 *)(q + 0x18);
            *(u32 *)(o + 0x84) = D_004C2804;
        } else {
            *(u16 *)(o + 0xCC) = *(u16 *)(q + 0x18);
            *(u32 *)(o + 0x84) = D_004C27E4;
        }
        *(V3 *)(o + 0x34) = *(V3 *)(q);
        *(V3 *)(o + 0x50) = *(V3 *)(q + 0xC);
        *(u32 *)((s32)o + 0xD0) = 0x431;
        *(V4 *)(o + 0x74) = D_004439B0;
        if (*(u16 *)(q + 0x18) == 0x57) ((OS *)o)->fD0 |= 0x800000;
        o[4] = 1;
        *(s32 *)(o + 0xD4) = *(s8 *)(q + 0x1A);
        func_00147D20(o);
        if (*(s8 *)(q + 0x1B) < 0) break;
        q += 0x1C;
    }
    return o;
}
