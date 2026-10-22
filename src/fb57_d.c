typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void func_002C9A20(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    f32 vel, acc;

    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        p[0x1B5] = 0x3D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        q[5] = 2;
    }
    t = q[5] - 1;
    q[5] = t;
    if ((u8)t == 0) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            p[0x1B5] = 0x3D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 124))[p[2]]++;
        }
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6]; p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        q[2] = 0;
        p[0x1B5] = 0x3D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        if (p[0x1E6])
            vel = 21.666666030883789f;
        else
            vel = -21.666666030883789f;
        *(f32 *)(p + 0x5C) = vel;
        if (p[0x1E6])
            acc = -0.3125f;
        else
            acc = 0.3125f;
        *(f32 *)(p + 0x68) = acc;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 0x13);
    }
}
