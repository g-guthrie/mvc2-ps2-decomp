typedef unsigned char u8;
typedef unsigned int u32;
extern volatile u8 D_00630000[0x4000];
extern volatile u8 D_004D0000[0x2000];
extern volatile int D_004C2B78;
extern volatile int D_004C2B7C;
#define MODE_A (*(volatile int *)(D_00630000 + 0x36e8))
#define MODE_B (*(volatile int *)(D_00630000 + 0x36ec))
#define FLAGS (*(volatile u32 *)(D_004D0000 + 0x1788))
int func_0041DE10(void)
{
    int value;
    value = MODE_A;
    if (value != 0 && value != -1) {
        D_004C2B78 = value;
        switch (value) {
        case 2:
        case 5:
        case 3:
        case 4:
            FLAGS |= 1;
            break;
        default:
            FLAGS &= 0xfffffffe;
            break;
        }
    }
    value = MODE_B;
    if (value != 0 && value != -1) {
        D_004C2B7C = value;
        switch (value) {
        case 2:
        case 5:
        case 3:
        case 4:
            FLAGS |= 2;
            break;
        default:
            FLAGS &= 0xfffffffd;
            break;
        }
    }
    return FLAGS;
}
