typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002B6F20(u8 *p)
{
    unsigned int offset;
    s8 v;
    int clearFlag;
    u8 *c1b5;
    u16 *c1c0;
    s8 *c1b2;
    int *c1d8;
    u8 *c2;

    func_00175700(p);
    v = (s8)p[0x150];
    if (v != 0) {
        c1b5 = p + 0x1B5;
        c1c0 = (u16 *)(p + 0x1C0);
        c1b2 = (s8 *)(p + 0x1B2);
        *c1b5 = (u8)v;
        clearFlag = *c1b2 = *c1c0 = 0;
        *(int *)(p + 0x1D8) = 0;
        c1d8 = (int *)(p + 0x1D8);
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(short *)(offset + 0x7C);
        p[0x150] = 0;
        --*(s16 *)(p + 0x1C);
        c2 = p + 2;
        if (*(s16 *)(p + 0x1C) <= 0) {
            p[6]++;
            *c1b5 = 0x4E;
            *c1c0 = 0;
            *c1b2 = (s8)clearFlag;
            *c1d8 = 0;
            ((s16 *)(D_004C2794 + 0x7C))[*c2]++;
            func_001757E0(p, 22, 5);
        }
    }
}
