typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s16 a; s16 b; s16 c; } T6;
extern T6 D_0044C0E0[];
typedef struct {
    u8 p0[4]; u8 b4; u8 p5[0x1B]; u8 b20; u8 p21[3]; s8 b24; u8 p25[0xC]; s8 b31; u8 p32[2];
    f32 f34; f32 f38; u8 p3c[0x18]; f32 f54; u8 p58[0xE4]; u8 b13c; u8 p13d[3]; s16 h140;
} Pf;
typedef struct {
    u8 p0[0x24]; s8 b24; u8 p25[0xF]; f32 f34; f32 f38; u8 p3c[0x104]; s16 h140; u8 p142[0xE];
    s8 b150; u8 p151[0x17]; u16 h168; u8 p16a[0x7A]; u8 b1e4; u8 p1e5[0x18]; u8 b1fd;
} Qf;
void func_001BD3B0(Pf *p, Qf *q) {
    extern void func_00175670();
    T6 *t;
    s16 v;
    if (q->b1e4 != 0x15 || q->b1fd != 6 || q->h168 != 0x1507 || q->b150 == 0) {
        p->b4++;
        p->b13c = 0;
    } else {
        *(u32 *)&p->f54 = 0x3FACCCCD;
        t = &D_0044C0E0[p->b20];
        v = q->h140;
        p->h140 = v;
        if (v == 0) {
            p->f34 = q->f34 + 1.6666666269302368f * t->a;
        } else {
            p->f34 = q->f34 - 1.6666666269302368f * t->a;
        }
        p->f38 = q->f38 + 2.142857074737549f * t->b;
        p->b24 = q->b24;
        p->b31 = -2;
        func_00175670(p);
    }
}
