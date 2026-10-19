/* ./try.sh src/grok_bg_0031D890.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern void func_0031DE00(u8 *, int);
extern void func_001E3210(u8 *, int);
extern void func_0031DEC0(u8 *);
extern void func_0031DF20(u8 *);

void residual_0031D890(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        p[0x151] = 0;
        if (p[0x20D] != 2)
            func_00186A20(p);
        func_0031DE00(p, 0);
        func_001E3210(p, 31);
        func_0031DEC0(p);
        func_0031DF20(p);
    }
}
