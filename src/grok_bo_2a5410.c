typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_004D18A0;
extern void func_00175700(u8 *);
extern s32 func_0018AB10(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_002A5410(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[0x22] != 0) {
        if (func_0018AB10(p) != 0) {
            *(s16 *)(p + 0x1E) += 1;
            if (*(s16 *)(p + 0x1E) >= 5) {
                *(s16 *)(p + 0x1E) = 0;
                *(s16 *)(p + 0x1C) += 4;
                p[0x22]--;
            }
        }
    }
    if (D_004D18A0 < 5) {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t != 0)
            return;
    }
    p[7]++;
    q[9] = 2;
    *(s16 *)(p + 0x1C) = 24;
    func_001757E0(p, 22, 6);
}
