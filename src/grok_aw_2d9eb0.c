typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_002DC1B0(u8 *);

void func_002D9EB0(u8 *p)
{
    unsigned int offset;

    if (p[6] == 0) {
        p[6]++;
        func_001861B0(p);
        func_0018C4B0(p, 5);
        p[0x20D] = 0;
        p[0x1B5] = 0x61;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        func_001757E0(p, 0x14, 6);
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (((s8)func_00175700(p)) < 0)
        func_002DC1B0(p);
}
