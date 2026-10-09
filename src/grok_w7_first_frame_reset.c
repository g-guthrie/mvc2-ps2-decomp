typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00185490(u8 *);
extern void func_002F1DF0(u8 *);
extern u8 *D_004C2794;

void func_002F11B0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_00185490(p);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 1;
        p[0x1B5] = 8;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 20, 7);
        return;
    }
    if ((s8)func_00175700(p) < 0)
        func_002F1DF0(p);
}
