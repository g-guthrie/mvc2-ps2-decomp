typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_001537B0(s32);
extern s32 func_003DF850(s32, s32);
extern void func_00153A40(s32, s32);
extern void func_00413F50(void *, f32, s32);
extern void func_00152D20(u8 *);
extern void func_00152FB0(u8 *);
extern void func_00413DE0(void);
extern s8 D_004D1960[16];
extern u8 *D_004D1970[16][96];
extern u8 D_004F1F40[];
void func_00152AD0(void)
{
    s32 slot;
    s32 palette;
    s32 busy = 0;
    func_001537B0(0);
    func_003DF850(0x6C, 3);
    func_00153A40(4, 5);
    func_00413F50(D_004F1F40, 120000.0f, 0);
    for (palette = 0; palette < 16; palette++) {
        for (slot = 0; slot < D_004D1960[palette]; slot++) {
            u8 *object = D_004D1970[palette][slot];
            if (object[3] == 0) {
                if (!(*(f32 *)(object + 0x118) < 0.9333299994468689f))
                    func_00152D20(object);
                else
                    busy = 1;
            } else {
                if (!(*(f32 *)(object + 0x118) < 0.9333299994468689f))
                    func_00152FB0(object);
                else
                    busy = 1;
            }
        }
    }
    func_003DF850(0x6B, 0);
    if (busy == 1) {
        for (palette = 0; palette < 16; palette++) {
            for (slot = 0; slot < D_004D1960[palette]; slot++) {
                u8 *object = D_004D1970[palette][slot];
                if (*(f32 *)(object + 0x118) < 0.9333299994468689f) {
                    if (object[3] == 0)
                        func_00152D20(object);
                    else
                        func_00152FB0(object);
                }
            }
        }
    }
    func_003DF850(0x6B, 1);
    func_001537B0(1);
    func_003DF850(0x6C, 1);
    func_00413DE0();
}
