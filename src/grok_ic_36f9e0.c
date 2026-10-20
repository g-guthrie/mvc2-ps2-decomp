typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void (*D_004C1CB4[])(u8 *) __attribute__((section(".sdata")));
extern void func_00175700(u8 *);

void func_0036F9E0(u8 *p)
{
    *(u32 *)(p + 0x50) = 0x3F8B851F;
    *(u32 *)(p + 0x54) = 0x3F7F9DB2;
    D_004C1CB4[p[5]](p);
}

void func_0036FA20(u8 *p)
{
    u8 *q;
    func_00175700(p);
    q = *(u8 **)(p + 0x18);
    if (q[6] != 2) {
        p[4]++;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    }
}
