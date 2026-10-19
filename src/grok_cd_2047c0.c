typedef unsigned char u8;
typedef float f32;

extern void func_001863F0(u8 *);
extern void func_00204990(u8 *);
extern void func_00204950(u8 *);
extern void func_002048D0(u8 *);
extern void func_00204890(u8 *);

void residual_002047C0(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (p[0x212] == 1) {
        if (p[0x20D] == 1)
            func_00204990(p);
        else
            func_00204950(p);
    } else if (p[0x20D] == 1)
        func_002048D0(p);
    else
        func_00204890(p);
}
