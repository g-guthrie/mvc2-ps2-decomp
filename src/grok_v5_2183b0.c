typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern void func_00218910(u8 *, int);
extern void func_001E3210(u8 *, int);
extern void func_002189D0(u8 *);
extern void func_00218A30(u8 *);

void func_002183B0(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[7]++;
        p[0x151] = 0;
        func_00186A20(p);
        func_00218910(p, 0);
        func_001E3210(p, 0x1F);
    }
    func_002189D0(p);
    func_00218A30(p);
}
