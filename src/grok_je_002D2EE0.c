typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad8[0x1E - 8];
    s16 s1e;
    u8 pad20[0x34 - 0x20];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f6c;
    u8 pad70[0x430 - 0x70];
    f32 f430;
} P_002D2EE0;

extern s8 func_00175700(P_002D2EE0 *);
extern void func_001757E0(P_002D2EE0 *, int, int);
extern void func_001E3710(P_002D2EE0 *, int);

void func_002D2EE0(P_002D2EE0 *p)
{
    f32 *p5c;
    f32 *p60;
    f32 *p68;
    f32 *p6c;
    s16 t;

    func_00175700(p);
    p5c = &p->f5c;
    p68 = &p->f68;
    p60 = &p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    p6c = &p->f6c;
    if (p->b7 == 0) {
        t = p->s1e - 1;
        p->s1e = t;
        if (t <= 0) {
            p->b7++;
            func_001757E0(p, 0x12, 1);
        }
    } else if (p->f38 <= p->f430) {
        p->b6++;
        p->f38 = p->f430;
        p->f34 = p->f64;
        *p5c = 0;
        *p60 = 0;
        *p68 = 0;
        *p6c = 0;
        func_001757E0(p, 0x12, 3);
        func_001E3710(p, 0x34);
    }
}
