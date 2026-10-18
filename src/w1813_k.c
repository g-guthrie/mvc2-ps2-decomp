typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD0;

void func_00206E80(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001266A0();
    extern void func_00206A80(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_0034CC60(u8 *, s32);
    f32 f;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_001E3710(p, 0x32);
    }
    p[0x209] = 3;
    if (*(s8 *)(p + 0x151) != 0) {
        func_001266A0(p, 7, 7);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        f = *(f32 *)(p + 0x38);
        if (f > D_004F1FD0) {
            t = p[6] + 1;
            p[6] = t;
            *(s16 *)(p + 0x1C) = 0x20;
            p[0x22] = 0xFF;
            *(s32 *)(p + 0x118) = 0;
            *(s32 *)(p + 0x50) = 0;
            *(s32 *)(p + 0x54) = 0;
            *(s16 *)(p + 0x140) = 0;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_001266A0(p, 0, 0, t);
            func_00206A80(p);
            func_001757E0(p, 0x16, 0x15);
            func_001E3210(p, 0x10);
            func_0034CC60(p, 0);
            func_0034CC60(p, 1);
        }
    }
}
