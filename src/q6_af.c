typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00359990(u8 *p, s32 a1) {
    extern void func_00359710(u8 *, s32, u8);
    extern void func_001757E0(u8 *, u8, u8);
    extern void func_0035AD20(u8 *, s32);
    extern void func_00359840(u8 *, s32);
    u8 *q;
    u32 t = p[6];
    q = *(u8 **)(p + 0x18);
    p[6] = t + 1;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    func_00359710(p, a1, p[0x21] - 1);
    switch (p[0x21]) {
    case 4:
    case 1:
        p[0x168] = 0x15;
        break;
    case 5:
    case 2:
        p[0x168] = 0x16;
        break;
    case 6:
    case 3:
        p[0x168] = 0x17;
        break;
    }
    p[0x169] = 0x17;
    func_001757E0(p, p[0x169], p[0x168]);
    func_0035AD20(p, a1);
    func_00359840(p, a1);
}
