typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x1C]; s16 h1C; } PS;

extern f32 D_004F1F4C[];

void func_0027EF00(u8 *p) {
    extern int func_00174470(const void *);
    extern void func_00185490(u8 *);
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    extern void func_001E3210(u8 *, s32);
    f32 k;
    s16 h;
    u32 t;
    switch (p[6]) {
    case 0:
        if (func_00174470(p)) {
            p[6] = 2;
        } else {
            p[6] = 1;
            func_00185490(p);
            k = 106.66666412f * *(f32 *)(p + 0x50);
            if (p[0x1E6] != 0) k = -k;
            *(f32 *)(p + 0x34) = D_004F1F4C[0] + k;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            func_001757E0(p, 0, 4);
        }
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            t = p[6];
            p[6] = t + 1;
        }
        break;
    case 2:
        p[6] = p[6] + 1;
        func_001757E0(p, 0x13, 1);
        break;
    case 3:
        if ((s8)func_00175700(p) < 0) {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x13, 2);
            *(s16 *)(p + 0x1C) = 0x91;
        }
        break;
    case 4:
        h = *(s16 *)(p + 0x1C);
        if (h > 0) {
            h = h - 1;
            ((PS *)p)->h1C = h;
            if (h == 0) func_001E3210(p, 3);
        }
        func_00175700(p);
        break;
    }
}
