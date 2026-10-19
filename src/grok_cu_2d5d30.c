/* Callback at jtbl_004C0FA0[0]. The native path initializes x/y only.
 * The z component is genuinely read at 0015659C through dispatcher case 1;
 * leave it uninitialized as retail does, rather than inventing zero or
 * declaring an eight-byte buffer that the callee would read past. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00154790(f32 *, s16, int, int);
extern void func_001E3B70(u8 *, int);

void func_002D5D30(u8 *p)
{
    f32 v[3] __attribute__((aligned(16)));

    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;
    p[0x151] = 0;
    p[6]++;
    v[1]=171.42855834960938f+*(f32 *)(p+0x38);
    if(p[0x1E6]) v[0]=53.33333206176758f; else v[0]=-53.33333206176758f;
    v[0] += *(f32 *)(p + 0x34);
    func_00154790(v, *(s16 *)(p + 0x140), 1, 0);
    func_001E3B70(*(u8 **)(p + 0x1DC), 0);
    *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
    (*(u8 **)(p + 0x1DC))[0x20A] = 1;
    (*(u8 **)(p + 0x1DC))[0x1B5] = 0x22;
    *(u32 *)(p + 0x60) = 0x41BC9249;
    *(u32 *)(p + 0x6C) = 0xBF700000;
    if(p[0x1E6]) *(f32 *)(p+0x5C)=-4.166666507720947f; else *(f32 *)(p+0x5C)=4.166666507720947f;
}
