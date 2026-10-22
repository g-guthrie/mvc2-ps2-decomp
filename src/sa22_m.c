typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

void func_002493F0(u8 *p)
{
    extern s32 func_00175700();
    extern void func_00175C00();
    extern void func_001843A0();
    extern void func_001A78D0();
    extern void func_00362000();
    extern void func_00176160();
    u16 h;
    s16 v;
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        break;
    case 1:
        if (p[6] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                u32 t = p[6];
                p[6] = t + 1;
                *(s16 *)(p + 0x1C) = 1;
                *(s16 *)(p + 0x1E) = 0;
            }
        }
        if (p[6] == 1) {
            if (*(s8 *)(p + 0x151) != 0) {
                v = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = v;
                if (v <= 0) {
                    func_00362000(p, 0);
                    func_00362000(p, 1);
                    *(s16 *)(p + 0x1C) = 10;
                }
                v = *(s16 *)(p + 0x1E) + 1;
                *(s16 *)(p + 0x1E) = v;
                if ((v & 2) != 0) {
                    func_00175C00(p, 0);
                } else {
                    func_00176160(p, 3, 3, 1);
                }
            }
        }
        break;
    case 2:
        if (p[6] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                u32 t = p[6];
                p[6] = t + 1;
                func_001A78D0(p, 1);
            }
        }
        break;
    default:
        break;
    }
    h = *(u16 *)(p + 0x160);
    if (h != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)(s16)h;
        } else {
            *(f32 *)(p + 0x34) -= 1.6666666269302368f * (f32)(s16)h;
        }
        *(u16 *)(p + 0x160) = 0;
    }
}
