typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00175700(u8 *);
extern void func_001C8830(u8 *);
extern void func_0038E3B0(u8 *, s32, f32, f32);
void func_002997B0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x151] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001C8830(p);
        func_0038E3B0(p, 0, 195.0f, 113.57142639160156f);
    }
}
extern void func_003DAA40();
extern f32 D_00445260[];
void func_0015D620(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C);
    if (v > 15) {
        func_003DAA40();
    } else {
        *(f32 *)(p + 0x74) = D_00445260[v];
        *(f32 *)(p + 0x50) += 0.12f;
        *(f32 *)(p + 0x54) += 0.12f;
        *(s16 *)(p + 0x1C) += 1;
    }
}
