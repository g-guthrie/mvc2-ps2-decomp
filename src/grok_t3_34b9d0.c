typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void residual_0034B9D0(u8 *p)
{
    f32 lim;
    u8 *parent;
    s16 t;

    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    parent = *(u8 **)(p + 24);
    lim = 68.57142639160156f + *(f32 *)(parent + 1072);
    if (*(f32 *)(p + 56) < lim) {
        *(f32 *)(p + 56) = lim;
        *(s16 *)(p + 28) = 1;
    }
    t = --*(s16 *)(p + 28);
    if (t != 0) {
        if ((s8)p[434] == 0)
            goto do_jal;
    }
    p[5]++;
    *(s16 *)(p + 30) = 21;
    return;
do_jal:
    func_001E7F60(p);
}
