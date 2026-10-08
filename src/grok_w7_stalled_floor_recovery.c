typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);
extern u8 *D_004C2794;

void func_002E6C00(u8 *p)
{
    p[0x1FE] = 1;
    p[0x206] = 3;

    /* Retail c.lt.s(vy, 0) / bc1t skips updates only for ordered negatives. */
    if (!(*(f32 *)(p + 0x60) < 0.0f)) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }

    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(u32 *)(p + 0x60) = 0xC1BC9249;
        *(u32 *)(p + 0x6C) = 0;
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 21, 15);
        return;
    }

    if (*(s8 *)(p + 0x151) != 0) {
        u8 *child;
        p[0x151] = 0;
        p[0x22] = 16;
        p[0x1FE] = 0;
        child = *(u8 **)(p + 0x1DC);
        *(u32 *)(child + 0x1C8) = (u32)p;
        child[0x20A] = 1;
        child[0x1E6] = p[0x1E6];
        child[0x1B5] = 0x23;
        child[0x24A] = 0;
        func_001266A0(p, 0, 0);
    }
}
