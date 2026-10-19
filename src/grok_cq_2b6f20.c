typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002B6F20(u8 *p)
{
    s8 v;
    u8 *b15;
    u16 *t1c0;
    u8 *b12;
    u32 *w1d8;
    u8 *id;
    u8 z;

    func_00175700(p);
    v = p[0x150];
    if (v != 0) {
        p[0x1B5] = v;
        b15 = p + 0x1B5;
        z = (u16)0;
        *(u16 *)(p + 0x1C0) = 0;
        p[0x1B2] = z;
        *(u32 *)(p + 0x1D8) = 0;
        t1c0 = (u16 *)(p + 0x1C0);
        b12 = p + 0x1B2;
        w1d8 = (u32 *)(p + 0x1D8);
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        p[0x150] = 0;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        id = p + 2;
        if (*(s16 *)(p + 0x1C) > 0)
            return;
        p[6]++;
        *b15 = 0x4E;
        *t1c0 = 0;
        *b12 = (s8)z;
        *w1d8 = 0;
        ((s16 *)(D_004C2794 + 124))[*id]++;
        func_001757E0(p, 22, 5);
    }
}
