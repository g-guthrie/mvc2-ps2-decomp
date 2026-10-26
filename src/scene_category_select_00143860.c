typedef unsigned char u8;
typedef short s16;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern int D_004C2634 __attribute__((section(".sdata")));

void func_00143860(void)
{
    s16 id = *(s16 *)(D_004C2840 + 0xa);
    switch (id) {
    case 0: D_004C2634 = 0; break;
    case 0x346: D_004C2634 = 1; break;
    case 0x233: case 0x41a: D_004C2634 = 2; break;
    case 0x6e: case 0x1e3: case 0x3ca: case 0x5bb: D_004C2634 = 3; break;
    case 0x52f: D_004C2634 = 4; break;
    }
}
