typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void func_003DF850();
extern void func_0011D8F8();
extern void func_001843A0();
extern void func_003DAA40();
extern void func_00185080();

void func_0016E950(void) { func_003DF850(99, 0); }

void func_00180DC0(u8 *p) { func_0011D8F8(p + 696, 0, 128); }

void func_001846B0(s32 *p) {
    p[23] = 0;
    p[24] = 0;
    p[26] = 0;
    p[27] = 0;
    func_001843A0(p);
}

void func_001612D0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    q[5]--;
    func_003DAA40(p);
}

void func_00185060(u8 *p) {
    *(s16 *)(p + 652) = 4;
    p[7]++;
    func_00185080(p);
}
