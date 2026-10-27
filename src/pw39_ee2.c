typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_00408EA0(s32);
extern void func_0040DFA0(s32);
extern s32 func_00409708(s32, s32 *, s32, s32 *, s32);
extern s32 D_00632140[3];
extern s32 D_00632240[];

void func_0040E868(u8 *p) {
    s32 i;
    s32 v;
    for (i = 0; i < *(s32 *)(p + 4); i++) {
        s32 e = *(s32 *)(p + 0x10 + i * 4);
        if (e != 0) func_00408EA0(e);
    }
    v = *(s32 *)(p + 0x20);
    func_00409708(9, &v, 1, 0, 0);
    for (i = 0; i < *(s32 *)(p + 4); i++) {
        s32 e = *(s32 *)(p + 8 + i * 4);
        if (e != 0) func_0040DFA0(e);
    }
    *p = 0;
}

s32 func_00410B20(s32 a, s32 b, s32 c, s32 *out) {
    D_00632140[0] = a;
    D_00632140[1] = b;
    D_00632140[2] = c;
    func_00409708(0x2A, D_00632140, 3, D_00632240, 1);
    *out = D_00632240[1];
    return D_00632240[0];
}
