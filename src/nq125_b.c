typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 p0[3]; u8 b3; u8 p4; s8 b5; } G2840;
typedef struct { u8 p0[5]; u8 b5; u8 pad[0x1D]; u8 b23; } G2600;

extern G2840 *D_004C2840;
extern G2600 *D_004C2600;
extern u8 D_004D179A[];

void func_0012D300(void)
{
    extern void func_003DA650(s32);
    extern void func_00146C80(s32);
    extern void func_001489E0(s32, s32);
    extern s32 func_0014B660(s32);
    extern void func_0014BDA0(void);
    extern void func_003298B0(s32, s32, s32);
    extern s32 func_003299D0(void);
    extern s32 func_00131660(void);
    extern s32 func_00131720(void);
    extern void func_001E3CE0(s32);

    switch (D_004C2840->b5) {
    case 0:
        func_003DA650(0xD);
        func_00146C80(5);
        func_001489E0(0xB, 0xB);
        D_004C2600 = (G2600 *)func_0014B660(D_004D179A[0]);
        func_0014BDA0();
        func_003298B0(0xFF000000, 0xA, 0);
        D_004C2840->b5++;
    case 1:
        if (func_003299D0() != 0) return;
        D_004C2840->b5++;
        break;
    case 2:
        if (func_00131660() != 0) {
            if (D_004C2600->b23 != 0) {
                if (D_004C2600->b5 != 0) goto L444;
            } else {
                if (D_004C2600->b5 == 7) goto L444;
            }
        }
        if (func_00131720() != 0) goto L444;
        break;
    case 3:
        if (func_003299D0() != 0) break;
        D_004C2840->b3 = 1;
        D_004C2840->b5 = 0;
        break;
    }
    return;
L444:
    if (func_00131660() != 0) func_001E3CE0(2);
    else func_001E3CE0(3);
    func_003298B0(0xFF000000, 0xA, 1);
    D_004C2840->b5++;
}
