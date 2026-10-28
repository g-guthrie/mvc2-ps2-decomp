typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_004D18A0;
static void func_00134120(u8 *p, u8 *owner_unused) {
    if (D_004D18A0) {
        p[5] = 0;
        p[0x20] = 0;
        p[0x21] = 0;
    }
}
void func_00134150(u8 *p, u8 *b)
{
    extern void func_001345B0(u8 *, u8 *);
    u32 t = p[5];
    if (t == 0) {
        p[5] = t + 1;
        func_001345B0(p, b);
    }
    func_00134120(p, b);
}
