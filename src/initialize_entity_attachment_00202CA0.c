typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_001E3A40(u8 *);

void func_00202CA0(u8 *p) {
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 34;
        *(s8 *)(p + 0x1E6) = *(s8 *)(p + 0x140);
        *(s16 *)(q + 0x140) = (u8)p[0x1E6] ^ 1;
        *(s8 *)(q + 0x1E6) = *(s8 *)(q + 0x140);
        *(u32 *)(p + 0x5C) = 0x41200000;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (*(s16 *)(p + 0x140) != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 1, 2);
        func_001E3A40(p);
    }
}
