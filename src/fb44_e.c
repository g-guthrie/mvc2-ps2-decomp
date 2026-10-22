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

void func_003D5700(u8 *p, s32 i) {
    extern void func_003298B0();
    extern s32 func_003299D0();
    extern void func_001E3CE0();
    extern s32 func_001315E0();
    extern void func_003D5360();
    extern void func_003CEF10();
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
        E5700 *q = &D_004F4484[i];
        E5700 *r = &D_004F4490[i];
        s32 v;
        if (((q->h[0] | r->h[0]) & 0x2000) != 0) p[2] = o - 1;
        if (((q->h[0] | r->h[0]) & 0x1000) != 0) {
            s8 t = p[2];
            p[2] = t + 1;
        }
        v = *(s8 *)(p + 2) + 4;
        p[2] = v % 4;
        if ((s8)o != *(s8 *)(p + 2)) func_001E3CE0(1);
        v = func_001315E0((s8)i);
        if (((v & 0xFFFF) & q->h[0]) != 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
            p[0x1B] = *(s8 *)(p + 2);
            func_003298B0(0xFF000000, 10, 1);
            func_001E3CE0(2);
        } else if ((q->h[0] & 0x100) != 0) {
            s8 t = p[0x1A];
            p[0x1A] = t + 1;
            p[0x1B] = 3;
            func_003298B0(0xFF000000, 10, 1);
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
                if (*(s8 *)(p + 4) != 0) {
                    s32 b = 1 << i;
                    p[4] = 0;
                    p[0xF] = b;
                    p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0;
                    D_004C2840->b18 = b;
                    D_004C2840->b88 = 0;
                    D_004C2840->b89 = D_004C2840->b18;
                    D_004C2840->b90 = D_004C2840->b18;
                    func_003D5360();
                } else {
                    p[0x1C] = 4;
                    p[0] = 4;
                    func_003CEF10();
                }
                break;
            case 1:
                p[4] = 1;
                *(s8 *)(p + 0xF) = -1;
                p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0;
                D_004C2840->b18 = 1 << i;
                D_004C2840->b88 = 0;
                D_004C2840->b89 = D_004C2840->b18;
                D_004C2840->b90 = D_004C2840->b18;
                func_003D5360();
                break;
            case 2:
                p[4] = 2;
                p[0xF] = 0;
                p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0;
                D_004C2840->b18 = 3;
                D_004C2840->b88 = 0;
                D_004C2840->b89 = D_004C2840->b18;
                D_004C2840->b90 = D_004C2840->b18;
                func_003D5360();
                break;
            case 3:
                p[0] = 0;
                p[0x1C] = 1;
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
