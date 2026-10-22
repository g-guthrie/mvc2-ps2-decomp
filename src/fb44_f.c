typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u16 h[10]; } E5FD0;
extern E5FD0 D_004F4484[];
extern E5FD0 D_004F4490[];

void func_003D5FD0(u8 *p, s32 i) {
    extern void func_003298B0();
    extern s32 func_003299D0();
    extern void func_001E3CE0();
    extern s32 func_001315E0();
    extern void func_003CED60();
    extern void func_003CEE10();
    s32 n;
    u8 *u;
    s32 s;
    u = 0;
    n = 0;
    s = *(s8 *)(p + 0x1A);
    switch (s) {
    case 0:
        p[0x1A] = s + 1;
        func_003298B0(0xFF000000, 10, 0);
        break;
    case 1:
        if (func_003299D0() == 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
        }
        break;
    case 2: {
        s32 o = *(s8 *)(p + 3);
        E5FD0 *q = &D_004F4484[i];
        E5FD0 *r = &D_004F4490[i];
        s32 v;
        if (((q->h[0] | r->h[0]) & 0x2000) != 0) p[3] = o - 1;
        if (((q->h[0] | r->h[0]) & 0x1000) != 0) {
            s8 t = p[3];
            p[3] = t + 1;
        }
        v = *(s8 *)(p + 3) + 6;
        p[3] = v % 6;
        if ((s8)o != *(s8 *)(p + 3)) func_001E3CE0(1);
        if ((q->h[0] & 0x100) != 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
            func_003298B0(0xFF000000, 10, 1);
            func_001E3CE0(3);
            return;
        }
        switch (*(s8 *)(p + 3)) {
        case 0:
            u = p + 5;
            n = 4;
            break;
        case 1:
            u = p + 6;
            n = 3;
            break;
        case 2:
            u = p + 7;
            n = 2;
            break;
        case 3:
            u = p + 8;
            n = 2;
            break;
        case 4:
            n = -1;
            v = func_001315E0((s8)i);
            if (((v & 0xFFFF) & q->h[0]) != 0) {
                p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0;
                func_001E3CE0(2);
            }
            break;
        case 5:
            n = -1;
            v = func_001315E0((s8)i);
            if (((v & 0xFFFF) & q->h[0]) != 0) {
                s8 t = p[0x1A];
                p[0x1A] = t + 1;
                func_003298B0(0xFF000000, 10, 1);
                func_001E3CE0(2);
            }
            break;
        }
        break;
    }
    case 3:
        if (func_003299D0() == 0) {
            p[0x1C] = 3;
            p[0x1B] = 0;
            p[0x1A] = 0;
            p[0] = 1;
            p[2] = *(s8 *)(p + 4);
            p[3] = 0;
            func_003CED60();
            func_003CEE10();
        }
        break;
    default:
        break;
    }
    if (n > 0) {
        E5FD0 *r;
        E5FD0 *q;
        s32 o;
        o = *(s8 *)u;
        q = &D_004F4484[i];
        r = &D_004F4490[i];
        if (((q->h[0] | r->h[0]) & 0x800) != 0) *u = o - 1;
        if (((q->h[0] | r->h[0]) & 0x400) != 0) {
            s8 t = *u;
            *u = t + 1;
        }
        *u = (*(s8 *)u + n) % n;
        if ((s8)o != *(s8 *)u) func_001E3CE0(4);
    }
}
