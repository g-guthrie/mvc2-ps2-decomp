typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_001E3210(u8 *, int);
extern void func_00185490(u8 *);
extern void func_0029D5E0(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0029F700(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 5;
    func_00175C00(p, 0);
    func_0018C4B0(p, 5);
    if (p[0x1FD] == 12) {
        if (p[0x20D] == 2) {
            *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 16.0f;
            *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) / 8.0f;
            *(f32 *)(p + 0x6C) = *(f32 *)(p + 0x6C) / 64.0f;
            *(u32 *)(p + 0x68) = 0;
            func_001E3210(p, 43);
            func_00185490(p);
        } else {
            func_0029D5E0(p);
        }
        p[0x1B5] = 72;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_001757E0(p, 21, (u8)(p[0x1B7] + 13));
    } else {
        func_0029D5E0(p);
        p[0x1B5] = 50;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_001757E0(p, 21, (u8)(p[0x1B7] + 3));
    }
}
