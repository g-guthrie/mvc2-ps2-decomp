typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void residual_00225A20(u8 *p)
{
    u8 *owner;

    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        owner = *(u8 **)(p + 0x1DC);
        *(u8 **)(owner + 0x1C8) = p;
        owner[0x20A] = 4;
        owner[0x20D] = 2;
        func_001266A0(p, 0, 0);
        owner[0x1B5] = 0x20;
        owner[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
        func_001E3210(p, 0x20);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
}
