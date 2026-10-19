typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

extern s32 func_00175700(u8 *);
extern void func_003BEF10(u8 *, u16);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001DCDA0(u8 *, u8 *);

void func_001DCC80(u8 *p, u8 *q)
{
    if (*(s16 *)(p + 0x1C) != 0) {
        func_00175700(p);
        p[0x24] = *(s8 *)(p + 0x151) ? 0 : 7;
        if (q[0x1E4] == 0x1D) {
            if (q[5] == 0) {
                if (*(s16 *)(p + 0x1C) >= 0x3D && *(s16 *)(p + 0x1C) < 0x78) {
                    p[0x22] += 0x20;
                    if (p[0x22] & 0x80) {
                        *(s16 *)(p + 0x1E) ^= 1;
                        func_003BEF10(p, *(u16 *)(p + 0x1E));
                    }
                }
                *(s16 *)(p + 0x1C) -= 1;
                if (*(s16 *)(p + 0x1C) > 0)
                    return;
            }
        }
        *(s16 *)(p + 0x1C) = 0;
        func_001757E0(p, 0x16, 0x48);
        return;
    }
    if ((s8)func_00175700(p) < 0)
        func_001DCDA0(p, q);
}
