typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(void *);
extern void func_00176160(u8 *, int, int, int);
extern int func_001757E0(void *, int, int);
extern u8 *D_004C2840;

void func_002529E0(u8 *p)
{
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00176160(p, 4, 1, 1);
    *(s16 *)(p + 0x1E) = *(s16 *)(D_004C2840 + 0x1C) & 1;
    func_001757E0(p, 0x15, (*(s16 *)(p + 0x1E) + 0x13) & 0xFF);
}
