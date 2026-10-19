typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_00375CA0(u8 *, u8 *);
extern u8 *D_004C2794;

void func_00375B20(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    u8 *d = p + 0xD0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        p[0x1B5] = 0x45;
        *(s16 *)(p + 0x1C0) = 0;
        p[0x1B2] = (u8)(0 & 0xFFFF);
        *(unsigned int *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    }
    func_001E7F60(p);
    if (q[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (q[0x1FD] == 7) {
        if (q[6] == 3) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
        if (q[6] == 4) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    if (q[0x1FD] == 0xC) {
        if (q[6] == 7) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
        if (q[6] == 8) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    d[0] = q[0x168];
    func_00375CA0(q, p);
    p[0x24] = 0;
}
