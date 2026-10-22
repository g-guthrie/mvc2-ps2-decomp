typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
extern volatile s32 D_004C22B0;

void func_00404B08(u8 *p, s32 a, s32 b) {
    extern void func_00404BD0();
    extern s32 func_004003C8();
    extern void func_00400BB8();
    extern void func_00400658();
    extern void func_004007A0();
    extern void func_004006E8();
    extern void func_004052E0();
    extern void func_004052C0();
    s32 r;
    s32 t;
    t = D_004C22B0;
    func_00404BD0(p);
    r = func_004003C8(a, b, 0, 0xFFFFF, *(s32 *)(p + 0x8C));
    *(s32 *)(p + 8) = r;
    if (r == 0) {
        p[1] = 4;
    } else {
        func_00400BB8(r, 0x7FFFFFFF, 0x7FFFFFFF);
        func_00400658(*(s32 *)(p + 8), 0);
        func_004007A0(*(s32 *)(p + 8), 3);
        func_004006E8(*(s32 *)(p + 8));
        func_004052E0(*(s32 *)(p + 4), 1);
        func_004052C0(*(s32 *)(p + 4));
        p[1] = 1;
    }
}
