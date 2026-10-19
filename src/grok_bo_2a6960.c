typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_0018FDB0(u8 *);
extern void func_001548D0(u8 *, u32 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001266A0(u8 *, int, int);

void residual_002A6960(u8 *p)
{
    u32 v[4];

    func_00175700(p);
    if ((s8)p[0x151] > 0) {
        p[0x151] = 0;
        (*(u8 **)(p + 0x1DC))[0x1B5] = 0x26;
        func_0018FDB0(p);
        v[1] = 0xC0CDB6DB;
        v[0] = 0;
        v[2] = 0;
        func_001548D0(p, v, 1);
        func_001E3710(p, 15);
    }
    if ((s8)p[0x151] < 0) {
        p[6]++;
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        {
            u32 bits = 0xC326AAAA;
            if (p[0x1E6])
                bits = 0x4326AAAA;
            *(f32 *)(p + 0x34) += *(f32 *)&bits;
        }
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
}
