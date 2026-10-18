typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2988;
extern u16 *D_004C2984;

void func_00369580(u8 *o) {
    extern s8 func_00175700(u8 *);
    extern void func_0036A8A0(u8 *);
    extern s32 func_0036A5F0(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_00185870(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *s = *(u8 **)(o + 0x18);
    u8 *n;
    u32 t;
    s16 c;
    if (func_00175700(o) < 0) {
        *(s8 *)(D_004C2988 + 0xA) = -1;
        func_0036A8A0(o);
        return;
    }
    if (func_0036A5F0(o)) {
        t = o[5];
        o[5] = t + 1;
        return;
    }
    if (*(s8 *)(o + 0x1B2) != 0) {
        c = *(s16 *)(o + 0x1C);
        if (c == 0) {
            *(s16 *)(o + 0x1C) = c + 1;
            if (func_00185980(o)) {
                if (s[5] == 0) {
                    if (*D_004C2984 == *(u16 *)(s + 0x168)) {
                        t = o[5];
                        o[5] = t + 2;
                        s[0x1B1] = 0;
                        s[0x201] = 2;
                        s[0x209] = 2;
                        n = *(u8 **)(o + 0x1C4);
                        D_004C2988[0xA] = 1;
                        s[0x20B] = 0xC4;
                        func_00185870(o, n);
                        func_001757E0(o, 0x17, 0x19);
                        o[6] = 0;
                        o[0x21] = 0;
                        o[0x22] = *(s8 *)(o + 0x140) ^ 1;
                        *(f32 *)(n + 0x34) = *(f32 *)(o + 0x34);
                        func_001757E0(n, 0xD, 5);
                        return;
                    }
                }
            }
        }
    }
    func_001E7F60(o);
}
