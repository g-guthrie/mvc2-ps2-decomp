typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u16 D_004F4480[];
extern u16 D_004F4484[];
extern u8 D_004B5658[];

void func_00172E30(u8 *p) {
    extern void func_001740C0(u8 *);
    extern void func_003D7350(u8, u8, s32, u8 *, s32);
    extern void func_00173FF0(u8 *);
    extern void func_00174030(u8 *);
    extern void func_00131340(s32);
    s32 t;
    s32 c;
    *(s8 *)(D_004C2840 + 0x8E) += *(s8 *)(p + 0x4DC);
    if (*(s8 *)(D_004C2840 + 0x8C) != 0) {
        *(s8 *)(D_004C2840 + 0x8E) -= *(s8 *)(p + 0x4DC);
        func_001740C0(p);
        return;
    }
    if (*(s8 *)(D_004C2840 + 0x19) != 0 || *(s8 *)(D_004C2840 + 0x91) != 0) return;
    {
        t = (*(s8 *)(p + 0x538) == 1) ? 0x78 : 0xC;
        *(s16 *)(p + 0x4D6) = *(s16 *)(p + 0x4D6) - 1;
        if (*(s16 *)(p + 0x4D6) == 0) {
            *(s16 *)(p + 0x4D6) = 0x78;
            *(s16 *)(p + 0x4D4) = *(s16 *)(p + 0x4D4) - 1;
        }
        c = *(s16 *)(p + 0x4D4);
        if (c == 0) {
            func_003D7350(t, D_004C2840[0xB6], 0xB, D_004B5658, c);
        } else {
            func_003D7350(t, D_004C2840[0xB6], 0xB, D_004B5658, c - 1);
        }
        if (*(u16 *)((u8 *)D_004F4480 + (*(s8 *)(p + 0x538) & 1) * 20) & 0x8000) {
            func_00173FF0(p);
            func_00174030(p);
            func_00131340(0x64);
        }
        c = *(s16 *)(p + 0x4D4);
        if (c < 8 && c != 0 && *(s8 *)(p + 0x4D0) == 2 &&
            (*(u16 *)((u8 *)D_004F4484 + (*(s8 *)(p + 0x538) & 1) * 20) & 0x3F0) != 0) {
            *(s16 *)(p + 0x4D4) = c - 1;
        }
        if (*(s16 *)(p + 0x4D4) == 0) {
            *(s8 *)(D_004C2840 + 0x8E) -= *(s8 *)(p + 0x4DC);
            func_001740C0(p);
        }
    }
}
