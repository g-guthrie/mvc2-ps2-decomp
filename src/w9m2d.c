typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00185490(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
void func_00187650(u8 *p) {
    func_00185490(p);
    p[0x20D] = 2;
    p[0x1F1] = 0;
    if (p[0x215] == 0) {
        if (!(*(f32 *)(p + 0x6C) <= -0.0669642836f)) {
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        }
    }
    if (p[0x1E5] != 0x12 && p[0x1E5] != 0x13) {
        p[0x1F2] = 0;
    }
    func_001757E0(p, 6, 0);
}

extern void func_00175700(void *p);
extern void func_00183d50(void *p);
void func_0022B340(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < 0.0f) {
        *(u32 *)(p + 0x6C) = 0xBF9A4924;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
    } else if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
}
