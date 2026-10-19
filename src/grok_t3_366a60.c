typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2974;

void func_00366A60(u8 *p)
{
    f32 vx;
    int anim;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)D_004C2974) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)D_004C2974;
        *(s16 *)(p + 0x1E) = 3;
        if (D_004C2974[7])
            vx = 3.3333332538604736f;
        else
            vx = -3.3333332538604736f;
        *(f32 *)(p + 0x5C) = vx;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        anim = 13;
        anim = ((*(s16 *)(p + 0x140) ^ D_004C2974[7]) != 0) ? anim : 15;
        p[0x168] = anim;
        func_001757E0(p, 0x17, p[0x168]);
    }
}
