typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00452190[];

void func_003B51F0(u8 *p, u8 *q) {
    extern void func_003B5560();
    extern void func_003B54E0();
    extern void func_003B5530();
    f32 *a2, *a3;
    f32 z = 0.0f;
    f32 f1 = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x90);
    f32 f0 = *(f32 *)(p + 0x34) - f1;
    a2 = (f32 *)(p + 0x88);
    a3 = (f32 *)(q + 0x2B8);
    if (*(s16 *)(p + 0x140) == 0) f0 = -f0;
    if (f0 <= z) {
        *(f32 *)(p + 0x34) = f1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + a2[3];
        a2[4] = z;
        *(s16 *)(p + 0x1C) = 3;
        ((u8 *)a3)[4] = 1;
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
        func_003B5560(p, q);
    } else {
        func_003B54E0(p, q);
        func_003B5530(p, q);
    }
}

void func_002365D0(u8 *p, u8 *q) {
    extern s32 func_00189310();
    extern void func_0018A990();
    if (p[0x20] != 0 && p[0x20D] == 2 && *(s8 *)(p + 0x539) == 0 && *(s8 *)(q + 6) != 0) {
        p[0x1E4] = 3;
        if (func_00189310(p, D_00452190, p + 0x3E0) == 0) {
            p[0x1E4] = 0x15;
            return;
        }
        {
            s32 t = *(s8 *)(q + 6);
            *(s8 *)(q + 6) = t - 1;
        }
        *(s16 *)(p + 0x140) = *(s16 *)(p + 0x140) ^ 1;
        { u32 t = p[0x1E6]; p[0x1E6] = t ^ 1; }
        func_0018A990(p, p + 0x3E0);
        p[6] = 0;
        p[7] = 0;
        p[0x1FD] = 2;
        p[0x1E4] = 0x15;
    }
}
