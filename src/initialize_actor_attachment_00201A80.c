typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_00198100(u8 *, s32);
extern void func_00190D50(u8 *, u8 *);
extern void func_00200990(u8 *);
void func_00201A80(u8 *p)
{
    u8 **slot = (u8 **)(p + 0x2B8);
    s8 status = func_00175700(p);
    if (status < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[7]++;
        *(u32 *)(p + 0x5C) = 0x40555555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        if (*(s16 *)(p + 0x140) != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 22, 19);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00198100(p, 2);
        {
            u8 *q = *slot;
            *(u8 **)(q + 0x1C8) = p;
            *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140);
            q[0x20A] = 1;
            q[0x20D] = 2;
            q[0x1B5] = 68;
            func_00190D50(q, p);
            func_00190D50(q, p);
        }
        func_00200990(p);
    }
}
