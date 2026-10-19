typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C29D4;

void func_003930B0(u8 *p) {
    extern void func_00175700();
    extern void func_00179160(void *, void *);
    extern s32 func_00393390();
    extern void func_003933A0();
    extern void func_0018FDB0();
    extern void func_00191480();
    extern void func_001E3710();
    u8 *s0, *s1;
    s16 t;
    s1 = *(u8 **)(p + 0x18);
    s0 = *(u8 **)(p + 0x1DC);
    s1[0x1FE] = 1;
    (*(u8 **)(p + 0x18))[0x201] = 2;
    (*(u8 **)(p + 0x18))[0x209] = 2;
    func_00175700(p);
    func_00179160(p, s0);
    if (func_00393390(p) != 0) {
        func_003933A0(p);
        return;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        *(s16 *)(p + 0x1C) = 2;
        s0[0x1B5] = 0x27;
        func_0018FDB0(p);
        func_00191480(s0, s1, 1);
        t = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = t;
        if ((t & 1) != 0) func_001E3710(p, 2);
    }
    if (*(s8 *)(D_004C29D4 + 9) >= 2) p[5]++;
}
