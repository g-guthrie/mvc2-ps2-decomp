typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern s32 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);
extern void func_001830D0(void *, void *, s32);
void func_002004B0(u8 *p)
{
    u8 *q = p + 0x2B8;
    f32 values[2] __attribute__((aligned(16)));
    s8 status;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    status = (s8)func_00175700(p);
    if (status < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[7] = 0;
        *(s16 *)(p + 0x1C) = 40;
        *(u32 *)(p + 0x5C) = 0x41555555;
        *(u32 *)(p + 0x68) = 0xBDD55555;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        p[0x20D] = 2;
        func_001757E0(p, 22, 6);
        q[0x1C] = 1;
        *(u32 *)&values[0] = 0xC1D55555;
        *(u32 *)&values[1] = 0x43092492;
        func_001830D0(p, values, 1);
    }
}
