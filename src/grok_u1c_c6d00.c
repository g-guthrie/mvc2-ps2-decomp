typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[6]; u8 f6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;
} S26;

void func_001C6D00(u8 *p, u8 *q) {
    extern int func_00175700(u8 *);
    extern int func_001757E0(u8 *, int, int);
    s16 d;
    f32 f;
    u32 t;
    func_00175700(p);
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    if (q[0x1E4] != 0x16) {
        p[7] = 4;
    } else {
        d = *(s16 *)(p + 0x140);
        if (d == 0) f = 51.666664f + *(f32 *)(q + 0x34);
        else f = *(f32 *)(q + 0x34) - 51.666664f;
        if ((d == 0 && *(f32 *)(p + 0x34) <= f) || (d != 0 && !(*(f32 *)(p + 0x34) < f))) {
            t = p[7];
            p[7] = t + 1;
            *(f32 *)(p + 0x34) = f;
            *(s16 *)(q + 0x1C) = 0;
            func_001757E0(p, 0x19, 0x14);
        }
    }
}
