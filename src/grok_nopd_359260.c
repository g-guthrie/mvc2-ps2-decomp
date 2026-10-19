typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_0035A820(u8 *, u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_0035A7B0(u8 *, u8 *);

void residual_00359260(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(p + 24);

    if ((s8)r[336] == 0) {
        func_0035A820(p, q);
        return;
    }
    *(f32 *)(p + 52) = *(f32 *)(r + 52);
    *(f32 *)(p + 56) = *(f32 *)(r + 56);
    if ((s8)r[336] == 1) {
        r[336] = 2;
        p[361] = 23;
        p[360] = 31;
        func_001757E0(p, p[361], p[360]);
    }
    func_00175700(p);
    func_001E7F60(p);
    func_0035A7B0(p, q);
}
