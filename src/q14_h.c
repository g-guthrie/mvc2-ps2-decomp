typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_0044FDE0[];
extern s8 func_00175700(u8 *p);
extern void func_00175C00(u8 *p, s32 a);
extern void func_00176160(u8 *p, s32 a, s32 b, s32 c);
void func_001FE720(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 q = p[5]; p[5] = q + 1;
        func_00175C00(p, 0);
        return;
    }
    if (*(s8*)(p + 0x150) != 0) {
        s8 t = *(s8*)(p + 0x150);
        if (t == 0x60) {
            func_00175C00(p, 0);
        } else {
            func_00176160(p, 0, t + D_0044FDE0[p[0x25]], 1);
        }
        *(s8*)(p + 0x150) = 0;
    }
}
