typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_002482C0();
extern s8 func_00175700();
extern void func_00184540();
extern void func_00248320();
extern void func_00360530();
void func_00246400(u8 *p) {
    s32 i;
    s8 t;
    func_002482C0(p);
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    func_00248320(p);
    t = p[0x151];
    if (t & 1) {
        p[0x151] = t & ~1;
        i = 10;
        do {
            func_00360530(p, 0, (u8)i);
            i++;
        } while (i < 15);
    }
    t = p[0x151];
    if (t & 2) {
        p[0x151] = t & ~2;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
