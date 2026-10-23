/* Recovered ordinary C; verified independently against the pinned retail function. */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00197E40(u8 *p, u8 *q)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x150) == 0)
        return;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        p[5]++;
        func_001757E0(p, 0x14, 7);
    }
}
