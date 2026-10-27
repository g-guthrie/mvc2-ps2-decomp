typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001FBA50(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    extern void func_001E3A40();
    extern void func_001E3710();
    extern void func_001843A0();
    extern void func_0018FDB0();
    extern void func_001548D0();
    f32 v[3];
    f32 y;
    if (p[6] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
        y = *(f32 *)(p + 0x38);
        if (y <= *(f32 *)(p + 0x430)) {
            u32 t = p[7];
            if (t == 0) {
                if (y <= 342.85711669921875f) p[7] = t + 1;
            }
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0xF, 4);
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            func_001E3A40(p);
            func_001E3710(p, 2);
        }
        return;
    }
    {
        s8 r = (s8)func_00175700(p);
        if (r >= 0) {
            s8 t = p[0x151];
            if (t < 0) {
                p[0x151] = 0;
                (*(u8 **)(p + 0x1DC))[0x1B5] = 0x24;
                func_0018FDB0(p);
                v[0] = -53.33333206176758f;
                v[1] = 68.57142639160156f;
                v[2] = 0;
                func_001548D0(p, v, 1);
            } else if (t > 0) {
                u8 *q;
                p[0x151] = 0;
                q = *(u8 **)(p + 0x1DC);
                *(u8 **)(q + 0x1C8) = p;
                q[0x20A] = 1;
                q[0x1B5] = 0x22;
            }
            return;
        }
        func_001843A0(p);
    }
}
