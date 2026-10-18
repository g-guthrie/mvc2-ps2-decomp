typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_001E3210(void *p, s32 a);
extern s32 func_001E3710(void *p, s32 a);
s32 func_00190C60(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1CC);
    if (q) {
        if (q[1] == 0x1E) {
            if (p[0x1B6] == 0x22) {
                return func_001E3210(q, 0x20);
            }
        }
    }
    return func_001E3710(q, 0x43);
}

extern u8 D_00459C30[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990();
extern void func_002CAFC0(void *p);
extern void func_00186A60(void *p, s32 a);

s32 func_002C52D0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_00459C30, p + 0x380) == 0) {
        return 0;
    }
    if (*q != 0) {
        return 0;
    }
    func_0018A990(p, p + 0x380);
    if (p[0x215] != 0) {
        func_002CAFC0(p);
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 *D_0044CBA0[];

void func_001C4010(u8 *p, u8 *q, u32 t) {
    q = *(u8 **)(p + 0x18);
    if (q[0x1E4] == 0x15) {
        t = q[0x1FD];
        if (t == 7 || t == 4 || t == 5 || t == 0xD) {
            q[0x2BB] = 0;
            t = p[4];
            p[4] = t + 1;
            p[7] = 0;
            p[6] = 0;
            p[5] = 0;
            p[0x13C] = 0;
            return;
        }
    }
    p[0x13C] = ((s8 *)q)[0x13C];
    ((void (*)(void *))D_0044CBA0[p[6]])(p);
}

extern void func_001E7F60();

void func_003B1020(u8 *p) {
    s8 *sb = (s8 *)p;
    if (sb[0x1B3] != 0) {
        p[4] = 2;
        p[6] = 1;
        p[7] = 0;
    } else {
        func_001E7F60();
        if (sb[0x1B2] != 0) {
            s32 w = (sb[0x1B2] << 24) >> 24;
            if ((w & 1) || (w & 0x10)) {
                p[4] = 2;
                p[6] = 1;
                p[7] = 0;
            } else {
                p[4] = 2;
                p[6] = 2;
                p[7] = 0;
            }
        }
    }
}
