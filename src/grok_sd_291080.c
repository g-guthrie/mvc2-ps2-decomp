typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00291150(u8 *);

void func_00291080(u8 *p)
{
    p[7]++;
    func_00185490(p);
    *(float *)(p + 0x5C) /= 8.0f;
    *(u32 *)(p + 0x68) = 0;
    *(float *)(p + 0x60) /= 8.0f;
    *(float *)(p + 0x6C) /= 64.0f;
    func_0018C4B0(p, 10);
    p[0x1B5] = 52;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 5);
    func_00291150(p);
}
