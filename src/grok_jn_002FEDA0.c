typedef unsigned char u8;
typedef float f32;

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x2C];
    f32 f34, f38;
    u8 pad3c[0x20];
    f32 f5c, f60, pad64, f68, f6c;
    u8 pad70[0x19D];
    u8 b20d;
    u8 pad20e[0x12D];
    u8 b33b, b33c;
    u8 pad33d[0xCF];
    u8 b40c, b40d;
    u8 pad40e[0x22];
    f32 f430;
} S;

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
extern void func_00175700(S *);
extern void func_00175C00(S *, int);
extern void func_00183D50(S *);
extern void func_001757E0(S *, int, int);
extern void func_001E3710(S *, int);

void func_002FEDA0(S *p, u8 *q)
{
    f32 *t5c = &p->f5c;
    f32 *t60 = &p->f60;
    f32 *t68 = &p->f68;
    f32 *t6c = &p->f6c;

    p->b40c = 2;
    p->b33c = 5;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->f430 - 68.57142639160156f > p->f38) {
        ((u8 *)p)[6]++;
        p->b20d = 0;
        p->f38 = p->f430;
        q[7] = 0;
        func_00175C00(p, 0);
        *t5c = 0;
        *t60 = 0;
        *t68 = 0;
        *t6c = 0;
        func_00183D50(p);
        func_001757E0(p, 0x16, 2);
        D_004F1F45[0] = 3;
        D_004F1F46[0] = 1;
        func_001E3710(p, 0x31);
        p->b40d = 0;
        p->b40c = 0;
        p->b33b = 0;
        p->b33c = 0;
    }
}
