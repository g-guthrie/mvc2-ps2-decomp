typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 D_00450C60[];
extern void func_00212DA0();
void func_00212E50(u8 *a0, u8 *a1) {
    s32 t = D_00450C60[(s8)((*(u16*)(a0+0x35E) & 0x3C00) >> 10)];
    if (t >= 0) {
        s32 c = a1[0];
        if (t != c) {
            if (((t - c) & 0xF) < 8) {
                a1[0] = c + 1;
            } else {
                a1[0] = c - 1;
            }
            { u32 u = a1[0]; a1[0] = u & 0xF; }
        }
    }
    func_00212DA0(a0, a1);
}
