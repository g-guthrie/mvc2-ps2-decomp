typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x1E - 7];
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
    u8 pad70[0x1E6 - 0x70];
    u8 b1e6;
    u8 pad1e7[0x20D - 0x1E7];
    u8 b20d;
    u8 pad20e[0x211 - 0x20E];
    s8 b211;
    u8 pad212[0x430 - 0x212];
    f32 f430;
} P_002D46F0;

extern s8 func_00175700(P_002D46F0 *);
extern void func_001757E0(P_002D46F0 *, int, int);
extern void func_00183d50(P_002D46F0 *);
extern void func_001E3710(P_002D46F0 *, int);
extern void func_001266A0(P_002D46F0 *, int, int);

void func_002D46F0(P_002D46F0 *p)
{
    f32 *p5c;
    f32 *p60;
    f32 *p68;
    f32 *p6c;
    int a0;

    func_00175700(p);
    p5c = &p->f5c;
    p68 = &p->f68;
    p60 = &p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    p6c = &p->f6c;
    if (!(p->f430 <= p->f38)) {
        p->b6 = 5;
        p->f38 = p->f430;
        p->b20d = 0;
        *p5c = 0;
        *p60 = 0;
        *p68 = 0;
        *p6c = 0;
        func_001757E0(p, 1, 4);
        func_00183d50(p);
        func_001E3710(p, 0x34);
        return;
    }
    p->s1e--;
    if (p->s1e < 0) {
        a0 = p->b211;
        if (a0 != 0) {
            if (p->b1e6) {
                if (((s8)a0 & 1) == 0)
                    return;
            } else if (((s8)a0 & 2) == 0) {
                return;
            }
            p->b6++;
            *p5c = 0;
            *p60 = 0;
            *p68 = 0;
            *p6c = 0;
            func_001757E0(p, 0x15, 0x11);
            func_001E3710(p, 0x34);
        }
        func_001266A0(p, 1, 0xD);
    }
}
