typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern f32 *D_004C2974;

void func_00367AB0(u8 *p)
{
    f32 t;

    func_00175700(p);
    t = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += t;
    t = *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) += t;
    t = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x38) += t;
    t = *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x60) += t;
    if (*(f32 *)(p + 0x38) <= *D_004C2974) {
        p[5]++;
        *(f32 *)(p + 0x38) = *D_004C2974;
        *(s16 *)(p + 0x1E) = 3;
        {
            f32 vx;
            if (*(s16 *)(p + 0x140))
                vx = -3.3333332538604736f;
            else
                vx = 3.3333332538604736f;
            *(f32 *)(p + 0x5C) = vx;
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0xD);
    }
}
