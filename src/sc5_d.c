typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x18]; s8 b18; u8 pad1[0x6F]; s8 b88; s8 b89; u8 pad2[6]; s8 b90; } G5700;
typedef struct { u16 h[10]; } E5700;
extern G5700 *D_004C2840;
extern E5700 D_004F4484[];
extern E5700 D_004F4490[];
extern u8 D_004F7F6B[];
extern u8 D_004D18A6[];

void func_003D5410(u8 *p, s32 i) {
    extern void func_003298B0();
    extern s32 func_003299D0();
    extern void func_001E3CE0();
    extern s32 func_001315E0();
    extern void func_003D5360();
    extern void func_003D51E0();
    extern void func_003CED60();
    extern void func_003CEE10();
    extern void func_003CFBA0();
    extern void func_003CEB10();
    extern void func_003CEBC0();
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
        s32 o = *(s8 *)(p + 1);
        E5700 *q = &D_004F4484[i];
        E5700 *r = &D_004F4490[i];
        s32 v;
        if (((q->h[0] | r->h[0]) & 0x2000) != 0) p[1] = o - 1;
        if (((q->h[0] | r->h[0]) & 0x1000) != 0) {
            s8 t = p[1];
            p[1] = t + 1;
        }
        v = *(s8 *)(p + 1) + 5;
        p[1] = v % 5;
        if ((s8)o != *(s8 *)(p + 1)) func_001E3CE0(1);
        v = func_001315E0((s8)i);
        if (((v & 0xFFFF) & q->h[0]) != 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
            p[0x1B] = *(s8 *)(p + 1);
            func_001E3CE0(2);
            if (*(s8 *)(p + 0x1B) != 0)
                func_003298B0(0xFF000000, 10, 1);
        } else if ((q->h[0] & 0x100) != 0) {
            p[0x1C] = 0;
            func_003D51E0(p);
            p[0x1B] = 0;
            p[0x1A] = 0;
            func_001E3CE0(3);
        }
        break;
    }
    case 3:
        if (func_003299D0() != 0) break;
        {
            s32 m = *(s8 *)(p + 0x1B);
            switch (m) {
            case 0:
                p[0x1C] = 0;
                func_003D51E0(p);
                p[0x1B] = 0;
                p[0x1A] = 0;
                D_004D18A6[0] = D_004F7F6B[0];
                break;
            case 1:
                p[0x1C] = 3;
                p[0] = *(s8 *)(p + 1);
                p[2] = *(s8 *)(p + 4);
                p[3] = 0;
                func_003CED60();
                func_003CEE10();
                break;
            case 2:
                func_003CFBA0();
                p[0x1C] = 3;
                p[0] = *(s8 *)(p + 1);
                p[2] = 0;
                p[3] = 0;
                break;
            case 3:
                D_004C2840->b88 = 0;
                D_004C2840->b89 = D_004C2840->b18;
                D_004C2840->b90 = D_004C2840->b18;
                p[0x1C] = 0;
                func_003D5360();
                break;
            case 4:
                p[0] = 3;
                p[2] = 1;
                p[3] = 0;
                p[0x1C] = 5;
                func_003CEB10();
                func_003CEBC0();
                break;
            default:
                break;
            }
            p[0x1B] = 0;
            p[0x1A] = 0;
        }
        break;
    default:
        break;
    }
}
