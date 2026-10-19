typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00182DB0(u8 *, int);
extern void func_00182C30(u8 *, int);

void residual_002A5F70(u8 *p)
{
    u8 *q;

    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
        func_00182DB0(p, 3);
        func_00182C30(*(u8 **)(p + 0x1DC), 0x30);
        *(s16 *)(p + 0x1C) = 120;
        *(s16 *)(p + 0x1E) = 0;
        if (!(p[0x22] & 2)) {
            p[0x1E6] ^= 1;
            *(s16 *)(p + 0x140) = p[0x1E6];
        }
        q = *(u8 **)(p + 0x1DC);
        if (!((*(unsigned int *)(q + 0x428) & 0x20000000) | (*(unsigned int *)(q + 0x42C) & 0x04000000)))
            *(f32 *)(q + 0x38) = *(f32 *)(p + 0x430);
    }
}
