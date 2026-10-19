typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 D_004C12F8[] __attribute__((section(".sdata")));
extern u8 D_004C1300[] __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_0018C4B0(u8 *, int);

void func_002F4610(u8 *p, void *context)
{
    u32 counterOffset;
    p[6]++;
    (*(signed char *)(p + 0x1E8))++;
    p[0x1E9] = 0;
    func_00185490(p);
    p[0x20D] = 2;
    *(f32 *)(p + 0x5C) /= 8.0f;
    *(f32 *)(p + 0x60) /= 8.0f;
    *(f32 *)(p + 0x6C) /= 16.0f;
    *(u16 *)context = p[0x1B7];
    func_001757E0(p, 0x15, D_004C12F8[p[0x1B7]]);
    p[0x1B5] = D_004C1300[p[0x1B7]];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    counterOffset = p[2] * 2;
    counterOffset += (u32)D_004C2794;
    counterOffset += 0x7C;
    (*(s16 *)counterOffset)++;
    *(u16 *)(p + 0x366) = 0;
    func_0018C4B0(p, 5);
}
