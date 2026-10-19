typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);

void residual_00377AA0(u8 *p, u8 *q)
{
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0x1E)) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[5]++;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = -4.166666507720947f;
        if (*(s16 *)(p + 0x140)) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
}
