typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 a; V3 b; f32 pad; } E28;
typedef struct { f32 f[4]; } V4;
typedef struct { u8 pad[8]; s16 idx; } G;
extern void func_001757E0(u8 *, int, int);
extern G *D_004C2840;
extern u32 D_004C2804;
extern E28 D_00442B50[];
extern V4 D_004439B0;
extern u32 D_00446CE0[];
extern void func_0018C970(u8 *);
extern u32 func_002810D0(u8 *);
extern s32 func_00280750(u8 *);
extern void func_00280D80(u8 *);
extern u32 func_00280AE0(u8 *, u32);
extern u32 D_00455470[];

void func_0018C8A0(u8 *p, u8 *q, u8 *r) {
    u8 f, g, idx;
    *(u16*)(p+0x1C2) = *(u16*)(q+0x1C0);
    r = *(u8**)(p+0x1D0);
    if ((*(u16*)(p+0x1C2) & 0x1000) != 0) {
        func_0018C970(p);
        *(f32*)(p+0x5C) = *(f32*)(p+0x22C);
    } else {
        f = r[3];
        if ((f & 0x78) != 0) {
            if ((f & 8) != 0) idx = 4;
            else idx = ((f & 0x70) >> 4) - 1;
        } else {
            g = r[9];
            idx = 0;
            if (g >= 5) idx++;
            if (g >= 0xC) idx++;
        }
        *(u32*)(p+0x228) = D_00446CE0[idx];
        *(u32*)(p+0x5C) = 0;
    }
}

