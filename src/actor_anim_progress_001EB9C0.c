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
void func_001EB9C0(u8 *p) {
    extern void func_00183d50(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    extern s32 func_00175700(u8 *);
    extern void func_001EB830(u8 *);
    s16 v;
    u32 t;
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6] = 3;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 1, 3);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x15, 0xA);
            return;
        }
    }
    func_00175700(p);
    func_001EB830(p);
}
