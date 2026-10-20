typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x2C];
    f32 f34, f38;
    u8 pad3c[0x20];
    f32 f5c, f60, pad64, f68, f6c;
    u8 pad70[0xE1];
    s8 b151, b152;
    u8 pad153[0x3E6];
    s8 b539;
} S12;

extern u8 D_004F1F45, D_004F1F46;

void func_001F11B0(S12 *p)
{
    extern int func_00175700(S12 *);
    extern s32 func_0018AAC0(S12 *);
    extern s32 func_001864A0(S12 *);
    extern void func_001F72E0(S12 *);
    extern int func_001757E0(S12 *, int, int);
    s8 *b = (s8 *)((u8 *)p + 0x2B8);
    f32 *s1 = &p->f5c;
    f32 *s2 = &p->f60;
    f32 *s3 = &p->f68;
    f32 *s4 = &p->f6c;
    ((u8 *)p)[0x1FE] = 1;
    ((u8 *)p)[0x201] = 2;
    ((u8 *)p)[0x209] = 2;
    ((u8 *)p)[0x206] = 3;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (func_0018AAC0(p) != 0) {
        if (p->b539 != 0) {
            if (p->b151 != 0) {
                s32 v;
                p->b151 = 0;
                v = p->b152;
                if (v != 1)
                    p->b152 = v - 1;
            }
        } else
            p->b152 = 1;
        b[2]++;
        if (b[2] > 20)
            b[2] = 20;
    }
    if (func_001864A0(p) != 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        *s4 = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001F72E0(p);
        func_001757E0(p, 0xF, 0xD);
    }
}
