typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_004D18B0;
extern s8 D_004D18DE;
extern s16 D_004D1918[];
extern s8 D_004D193C[];

void func_00136110(s32 flag)
{
    extern void func_001E3CE0(s32);
    extern u8 *func_001362C0(u8 *, s32);
    extern void func_00191C60(u8 *, u8 *);
    extern void func_00191BF0(u8 *, u8 *);
    extern void func_00191B60(u8 *, u8 *);
    extern void func_00191A00(u8 *, u8 *);
    extern void func_00136570(u8 *);
    extern void func_001366C0(u8 *);
    extern void func_00136640(u8 *);
    u8 *o;
    func_001E3CE0(0x3F);
    if (flag == 0) {
        if ((o = func_001362C0(0, 3)) != 0) {
            *(u32 *)(o + 0x38) = 0xC1200000;
            func_00191C60(o + 0x1DC, o + 0x1E0);
            func_00136570(o);
            if ((o = func_001362C0(o, 2)) != 0) {
                *(u32 *)(o + 0x38) = 0;
                func_00191BF0(o + 0x1DC, o + 0x1E0);
                func_00136570(o);
                if ((o = func_001362C0(o, 1)) != 0) {
                    *(u32 *)(o + 0x38) = 0x40A00000;
                    func_00191B60(o + 0x1DC, o + 0x1E0);
                    func_00136570(o);
                    if ((o = func_001362C0(o, 0)) != 0) {
                        *(u32 *)(o + 0x38) = 0x41200000;
                        func_00191A00(o + 0x1DC, o + 0x1E0);
                        func_00136570(o);
                    }
                }
            }
            o[0x21] = 1;
        }
    } else {
        if ((o = func_001362C0(0, 6)) != 0) {
            *(u32 *)(o + 0x38) = 0;
            *(u32 *)(o + 0x1E0) = D_004D18B0;
            func_001366C0(o);
            if ((o = func_001362C0(o, 5)) != 0) {
                *(u32 *)(o + 0x38) = 0x40A00000;
                *(s32 *)(o + 0x1E0) = D_004D1918[D_004D18DE];
                func_00136640(o);
                if ((o = func_001362C0(o, 4)) != 0) {
                    *(u32 *)(o + 0x38) = 0x41200000;
                    *(s32 *)(o + 0x1E0) = D_004D193C[D_004D18DE];
                    func_00136640(o);
                }
            }
            o[0x21] = 1;
        }
    }
}
