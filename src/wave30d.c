typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00147870(s32 a, s8 b);
extern void func_001E7F60(u8 *p);
extern struct { s32 pad0; s32 n; s32 pad[2]; f32 f[129]; } D_004F1D20;

void func_00148990(void) {
    s32 i;
    i = 0;
    do {
        func_00147870(1, i);
        i++;
    } while (i < 9);
    func_00147870(2, 0);
}

void func_0016D1C0(void) {
    s32 i;
    for (i = 0; i < D_004F1D20.n; i++) {
        D_004F1D20.f[i] = 1.0f - (f32)i / (f32)D_004F1D20.n;
    }
    for (; i < 129; i++) {
        *(s32 *)&D_004F1D20.f[i] = 0;
    }
}

void func_003B07D0(u8 *a) {
    s8 t;
    if (*(s8 *)(a + 435)) {
        a[4] = 2;
        a[6] = 1;
        a[7] = 0;
    } else {
        func_001E7F60(a);
        t = *(s8 *)(a + 434);
        if (t) {
            if ((t & 1) || (t & 16)) {
                a[4] = 2;
                a[6] = 1;
                a[7] = 0;
            } else {
                a[4] = 2;
                a[6] = 2;
                a[7] = 0;
            }
        }
    }
}

extern void func_00186A60();
extern s32 func_00189310(u8 *p, void *q, u8 *r);
extern void func_0018A990(u8 *p, u8 *q);
extern u8 D_0045D700[];
extern u8 D_0044FB80[];

s32 func_00317070(u8 *a) {
    if (func_00189310(a, D_0045D700, a + 920) == 0) {
        return 0;
    } else if (**(s8 **)(a + 1056) == 0) {
        return 0;
    } else if (*(s8 *)(a + 703)) {
        return 0;
    } else {
        func_0018A990(a, a + 920);
        a[5] = 0;
        a[7] = 0;
        a[6] = 0;
        a[509] = 6;
        func_00186A60(a, 29);
        return 1;
    }
}

s32 func_001F7A20(u8 *p) {
    if (func_00189310(p, D_0044FB80, p + 920) == 0) {
        return 0;
    } else if (**(s8 **)(p + 1056) == 0) {
        return 0;
    } else {
        p[620] = 3;
        p[439] = 1;
        return 1;
    }
}
