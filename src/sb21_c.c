typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern u8 D_004B4880[];
extern u8 D_004B4898[];

void func_0016BC70(void) {
    extern void func_003D7350(s32, s32, s32, u8 *);
    extern void func_0016D190();
    extern void func_0016BE80();
    s16 v = *(s16 *)(D_004C2840 + 8) - 1;
    *(s16 *)(D_004C2840 + 8) = v;
    if (v == 0) {
        s8 t = *(s8 *)(D_004C2840 + 4);
        *(s8 *)(D_004C2840 + 4) = t + 1;
        D_004C2840[5] = 0;
    } else {
        func_003D7350(0x30, 0x24, 0x10, D_004B4880);
        func_003D7350(0x3C, 0x2E, 0x10, D_004B4898);
    }
    func_0016D190();
    {
        s8 f = D_004C2840[0x88];
        if (f & 1) {
            if (D_004F4480[0] & 0x8000) goto L1;
        }
        if (f & 2) {
            if (D_004F4494[0] & 0x8000) {
L1:
                func_0016BE80();
            }
            return;
        }
    }
}
