typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_0045A000[];
s32 func_002CBF80(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 s0;
    if (func_00189310(p, D_0045A000, p + 0x380) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
        s0 = 0xB;
    } else {
        s0 = 1;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[0x1FD] = s0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

void func_00223B30(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_00355BE0();
    u8 *q;
    if (*(u8 *)((s32)p + 0x2B8) != 0) {
        p[0x200] = 1;
    }
    q = (u8 *)((s32)p + 0x2B8);
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            break;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            if (q[0] == 0) {
                func_00355BE0(p, 0);
            }
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}

