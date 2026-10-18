typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O_00374680 {
    u8 p0[6]; u8 b6; u8 p1[0x11]; struct O_00374680 *w18; u8 pp[0x18]; f32 f34; f32 f38; u8 p3[0x20]; u32 w5c; u32 w60; u8 p4[4]; u32 w68; u32 w6c;
    u8 p5[0xCC]; u8 b13c; u8 p6[3]; s16 h140;
} O_00374680;
extern void func_001757E0();
void func_00374680(O_00374680 *p) {
    O_00374680 *q;
    f32 a;
    u32 t = p->b6;
    p->b6 = t + 1;
    p->b13c = 1;
    p->w5c = 0xC0555555;
    p->w68 = 0x3C555555;
    a = -33.3333321f;
    q = p->w18;
    p->f34 = q->f34;
    p->f38 = q->f38;
    if (q->h140 != 0) {
        p->w5c = 0x40555555;
        p->w68 = 0xBC555555;
        a = -a;
    }
    p->f34 += a;
    p->f38 += 77.1428528f;
    p->w60 = 0x412B6DB6;
    p->w6c = 0xBEF00000;
    func_001757E0(p, 0x16, 0xF);
}

