typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x4C]; s8 b4C; u8 pad1[3]; s8 b50; u8 pad2[8]; s8 b59; } G5DA0;
typedef struct { u16 h[10]; } E5DA0;
extern G5DA0 *D_004C2840;
extern E5DA0 D_004F4484[];
extern E5DA0 D_004F4490[];

void func_003D5DA0(u8 *p, s32 i) {
    extern void func_003298B0();
    extern s32 func_003299D0();
    extern void func_001E3CE0();
    extern s32 func_001315E0();
    extern void func_0012FA40();
    s32 s = *(s8 *)(p + 0x1A);
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
        s32 o = *(s8 *)(p + 2);
        E5DA0 *q = &D_004F4484[i];
        E5DA0 *r = &D_004F4490[i];
        s32 v;
        if (((q->h[0] | r->h[0]) & 0x2000) != 0) p[2] = o - 1;
        if (((q->h[0] | r->h[0]) & 0x1000) != 0) {
            s8 t = p[2];
            p[2] = t + 1;
        }
        v = *(s8 *)(p + 2) + 2;
        p[2] = v % 2;
        if ((s8)o != *(s8 *)(p + 2)) func_001E3CE0(1);
        v = func_001315E0((s8)i);
        if (((v & 0xFFFF) & q->h[0]) != 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
            p[0x1B] = *(s8 *)(p + 2);
            func_001E3CE0(2);
            func_003298B0(0xFF000000, 10, 1);
        } else if ((q->h[0] & 0x100) != 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
            p[0x1B] = 1;
            func_003298B0(0xFF000000, 10, 1);
            func_001E3CE0(3);
        }
        break;
    }
    case 3:
        if (func_003299D0() != 0) break;
        if (*(s8 *)(p + 0x1B) == 0) {
            D_004C2840->b50 = 1;
            func_0012FA40(0);
            D_004C2840->b59 = D_004C2840->b4C;
        } else {
            p[0] = 0;
            p[0x1C] = 1;
        }
        p[0x1B] = 0;
        p[0x1A] = 0;
        break;
    default:
        break;
    }
}
