typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001B67C0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_001B62A0(u8 *p)
{
    u8 *g = *(u8 **)(p + 0x18);
    u8 *h = g + 0x2B8;
    u8 st = p[5];
    if (st != 3) {
        if (st != 2) {
            if (st != 1) {
                if (st != 0) {
                    return;
                }
                func_00175700(p);
                if (*(s8 *)(p + 0x151) != 0) {
                    p[5]++;
                    func_001B67C0(p, 2);
                }
                return;
            }
            if (h[1] != 0) {
                p[5] = st + 1;
                *(f32 *)(p + 0x34) = *(f32 *)(g + 0x34);
                return;
            }
            if (g[0x1E4] == 21 && g[5] == 0) {
                return;
            }
            p[5] = 3;
            func_001757E0(p, 21, 13);
            return;
        }
        if (g[0x1E4] != 21 || g[5] != 0) {
            p[5] = 3;
            func_001757E0(p, 21, 13);
            return;
        }
        if (*(u16 *)(g + 0x168) != 0x150B) {
            return;
        }
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[0x13C] = 0;
    }
}
