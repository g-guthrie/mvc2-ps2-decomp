typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static s32 func_0028A490(u8 *p) {
    u8 v = p[0x1E6];
    u8 *o = *(u8 **)(p + 0x220);
    if (v == 0) {
        if (*(f32 *)(p + 0x34) < *(f32 *)(o + 0x34)) return 1;
    }
    if (v != 0) {
        if (*(f32 *)(p + 0x34) <= *(f32 *)(o + 0x34)) return 0;
        return 1;
    }
    return 0;
}

void func_0028A600(u8 *p, u8 *q) {
    extern void func_0028A530();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0028B0B0(u8 *);
    if (func_0028A490(p)) {
        p[7] = 6;
        q[0x18] = 0;
        func_0028A530();
        return;
    }
    if (q[0x18] == 0) {
        q[0x18] = (u8)(q[0x18] + 1);
        q[0x19] = 0;
        func_001757E0(p, 0x16, 8);
    }
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x34) += -5.0f;
    } else {
        *(f32 *)(p + 0x34) += 5.0f;
    }
    func_0028B0B0(p);
}
