typedef unsigned char u8;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002BBF00(u8 *p)
{
    f32 *vx = (f32 *)(p + 0x5C);
    f32 *ax;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    ax = (f32 *)(p + 0x68);
    if (p[0x1E6] == 0) {
        if (*(f32 *)(p + 0x5C) > 0.0f)
            goto zero;
    } else {
        if (*(f32 *)(p + 0x5C) >= 0.0f)
            goto after;
    zero:
        *vx = 0.0f;
        *ax = 0.0f;
    }
after:
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183D50(p);
        func_001757E0(p, 21, 18);
    }
}
