typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0019B110(u8 *, s32);
extern void func_00182C30(u8 *, s32);
extern void func_00182DB0(u8 *, s32);
extern void func_001266A0(u8 *, int, int);
extern void func_001757E0(u8 *, int, int);

void func_00192120(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    if ((s16)(--*(s16 *)(p + 28)) <= 0) {
        p[6]++;
        *(s32 *)(p + 104) = 0;
    }
}

void func_00192270(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    if ((s16)(--*(s16 *)(p + 28)) <= 0) {
        p[6]++;
        *(s32 *)(p + 104) = 0;
    }
}

void func_0021B470(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_0019B110(p, 6);
    }
}

void func_0021B9E0(u8 *p, u8 *q)
{
    func_00182C30(q, 0x38);
    func_00182DB0(p, 2);
    *(s16 *)(q + 0x1c) = 0;
    func_001266A0(p, 5, 5);
    func_001757E0(p, 15, 2);
}
