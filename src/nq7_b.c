typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef unsigned long long u64; typedef long long s64; typedef float f32;
void func_0024C460(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_0024D670(u8 *);
    extern void func_00126400();
    s32 a;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
if (func_0024D670(p) != 0 || (a = p[0x269]) == 4 || a == 5) { { u32 t = p[6]; p[6] = t + 1; } } else if (*(s8 *)(p + 0x151) != 1) { u32 t = p[6]; p[6] = t + 2; func_00126400(); return; } }
