/* residual_0035A0F0: ./try30.sh src/gr18_b.c "-O3 -Op -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x430]; f32 f430; } O35A0F0;
typedef struct { u8 pad0[0x18]; O35A0F0 *w18; u8 pad1[5]; u8 b21; u8 pad2[0x12]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; u8 pad5[0xCC]; s8 b13C; } P35A0F0;
void residual_0035A0F0(P35A0F0 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_0035ADE0();
    extern void func_0035AE70();
    extern void func_0035ACA0();
    extern void func_0035A7B0();
    O35A0F0 *o = p->w18;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_0035ADE0(p, q);
    if (p->f38 < 34.28571319580078f + o->f430) {
        p->f38 = 34.28571319580078f + o->f430;
        p->b21 = 0;
        func_0035AE70(p, q);
    }
    func_0035ACA0(p, q);
    if (p->b13C != 0) {
        func_0035A7B0(p, q);
    }
}
