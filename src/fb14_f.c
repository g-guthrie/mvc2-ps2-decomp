typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x0029EAF0 */
extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0018FDB0(u8 *);
extern void func_001E3B70(u8 *, s32);
extern void func_00191480(u8 *, u8 *, s32);
extern void func_001548D0(u8 *, f32 *, s32);
void func_0029EAF0(u8 *p, u8 *q) {
    f32 *s0, *s1, *s2, *s3;
    f32 z;
    f32 v[3];
    s3 = (f32 *)(p + 0x6C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x60);
    s0 = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    z = 0.0f;
    if (*(f32 *)(p + 0x60) < z && !(*(f32 *)(p + 0x2BC) <= *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x2BC);
        *(s16 *)(p + 0x1C) = 0x60;
        *s0 = z;
        *s1 = z;
        *s2 = z;
        *s3 = z;
        *(u32 *)(p + 0x6C) = 0xBFF00000;
        func_001757E0(p, 0x16, 0xF);
        func_00175700(p);
        p[7] += 1;
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x3E;
        func_0018FDB0(p);
        func_001E3B70(q, 1);
        func_00191480(q, p, 1);
        v[0] = -53.33333206176758f;
        v[1] = 34.28571319580078f;
        func_001548D0(p, v, 3);
    }
}
