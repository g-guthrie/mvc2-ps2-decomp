typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;


extern u8 D_004CFF20[];
extern u8 D_004CE120[];
extern u8 D_004D0420[];
extern u64 D_004C2748;
extern u8 D_004C2750;
extern s32 D_004C275C;
extern u8 D_004C2764;
extern u8 D_004C2768;
extern u8 D_004C276C;
extern u8 D_004C2770;
extern u8 D_004C2774;
extern u32 D_004C2778;
extern u8 D_004C2780;
extern u32 D_004C2534;

extern void func_00420230(void);
extern void func_00420150(void);
extern void func_0011D8F8(void *destination, s32 value, u32 size);
extern void func_0011FE88(void *destination, u32 source);

void func_00420340(void)
{
    func_00420230();
    D_004C2750 = 0;
    func_0011D8F8(D_004CFF20, 0, 1280);
    func_0011D8F8(D_004CE120, 0, 7680);
    func_0011D8F8(&D_004C2778, 0, 5);
    D_004C275C = -1;
    D_004C276C = 1;
    D_004C2774 = 0;
    D_004C2780 = 0;
    D_004C2764 = 0;
    D_004C2770 = 0;
    D_004C2768 = 0;
    func_0011D8F8(D_004D0420, 0, 1600);
    func_0011D8F8(&D_004C2748, 0, 8);
    func_0011FE88(&D_004C2748, D_004C2534);
    func_00420150();
}
