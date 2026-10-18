typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_003DAA40(u8 *);
void func_003C0940(u8 *p) {
    u8 *q;
    f32 x;
    func_00175700(p);
    q = *(u8 **)(p + 0xD8);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    x = *(f32 *)(p + 0x68);
    if (*(s16 *)(q + 0x140)) x = -x;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + x;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x6C);
    if ((*(u8 **)(p + 0x18))[4] > 1) {
        p[0x13C] = 0;
        func_003DAA40(p);
    }
}

