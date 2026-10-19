typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 *D_004C2938 __attribute__((section(".sdata")));
extern void func_00346030(u8 *);
extern void func_00346080(u8 *);

void func_00346300(u8 *p)
{
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        p[4]++;
        p[0x13C] = 0;
    } else if ((*(u8 **)(p + 0x18))[0x169] != 0x16) {
        p[4]++;
        p[0x13C] = 0;
    } else {
        u8 st = (*(u8 **)(p + 0x18))[0x168];
        if (st != 4 && st != 6) {
            p[5]++;
            *D_004C2938 = 4;
            *(s16 *)(p + 0x1C) = 2;
        } else if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
            D_004C2938[7] = 0;
            if (*(s16 *)(*(u8 **)(p + 0x18) + 0x1C) <= 0) {
                p[5]++;
                *D_004C2938 = 4;
                *(s16 *)(p + 0x1C) = 2;
            }
        }
    }
    func_00346030(p);
    func_00346080(p);
}
