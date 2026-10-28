/* s5d: MW 3.0.3, ./try.sh src/s5d_g.c "-O3 -sdatathreshold 0" (also 3.0). Float truthiness (!p->f60) fixes the f0/f1 order. */
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
typedef struct { u8 pad[0x5C]; f32 f5c; f32 f60; f32 f64; f32 f68; u32 u6c; u8 pad2[0x215 - 0x70]; u8 b215; } B9;
void func_002E1520(B9 *p, u16 k)
{
    extern void func_001843A0(B9 *);
    extern void func_00184540(B9 *);
        if (k == 2) {
        if (p->b215 != 0) {
            p->f60 = 0.0f; p->f68 = 0.0f; p->f5c = 0.0f;
            p->u6c = 0xBF4DB6DB;
            func_001843A0(p);
            return;
        }
        if (!p->f60) {
            p->f60 = 0.0f; p->f68 = 0.0f; p->f5c = 0.0f;
            p->u6c = 0xBF4DB6DB;
        }
        func_00184540(p);
    } else {
        func_001843A0(p);
    }
}
