typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

static void func_00359B30(u8 *p, s32 a1) {}

void func_00359B40(u8 *p, s32 a1) {
    u32 t = p[5];
    p[5] = t + 1;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359B30(p, a1);
}
