typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;

extern int func_00119098(f32);
extern int func_00118FA8(f32);
extern void func_001B0F40(u8 *, int);
extern void func_001757E0(u8 *, int, int);

typedef struct {
    f32 a, b, c, d, e, f, g;
} T28;
extern T28 D_00453BA0[];

void func_00260070(u8 *p)
{
    T28 *t;
    u16 i;
    f32 f;

    if (*(s16 *)(p + 0x1E) >= 4)
        return;
    i = (*(u16 *)(p + 0x354) & 0x3C00) >> 10;
    i = (u16)i;
    p[0x23] = (u8)i;
    t = &D_00453BA0[p[0x23]];
    p[0x21] = p[0x23];
    if (t->e == 0.0f)
        return;
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x1E;
    *(s16 *)(p + 0x1E) += 1;
    *(f32 *)(p + 0x5C) = t->a;
    *(f32 *)(p + 0x68) = t->b;
    *(f32 *)(p + 0x60) = t->c;
    *(f32 *)(p + 0x6C) = t->d;
    p[7] = (u8)func_00119098(t->g);
    f = t->f;
    if (f < 0.0f) {
        f = (f32)*(s16 *)(p + 0x140);
    } else {
        goto keep_f;
    }
keep_f:
    *(s16 *)(p + 0x140) = (s16)func_00118FA8(f);
    func_001B0F40(p, 0);
    func_001B0F40(p, 1);
    *(int *)(p + 0x48) = 0;
    func_001757E0(p, 0x16, 1);
}
