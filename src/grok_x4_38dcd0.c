typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00174470(u8 *);
extern void func_0038DE10(u8 *);
extern void func_0038DDA0(u8 *);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_0038DCD0(u8 *p)
{
    if (!func_00174470(p)) {
        func_0038DE10(p);
        return;
    }
    if (*(s8 *)(p + 0x1B2)) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_0038DDA0(p);
        return;
    }
    if (*(s8 *)(p + 0x1B3)) {
        p[0x1B3] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_0038DDA0(p);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_001E7F60(p);
}
