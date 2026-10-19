typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern f32 D_004CB704;

void func_00367AB0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= D_004CB704) {
        p[5]++;
        *(f32 *)(p + 0x38) = D_004CB704;
        *(s16 *)(p + 0x1E) = 3;
        if (*(s16 *)(p + 0x140) == 0)
            *(u32 *)(p + 0x5C) = 0x40555555;
        else
            *(u32 *)(p + 0x5C) = 0xC0555555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0xD);
    }
}
