typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004CB1F4[], D_004CB1F8[], D_004CB1FC[], D_004CB200[], D_004CB204[], D_004CB208[], D_004CB20C[], D_004CB210[], D_004CB214[], D_004CB218[], D_004CB21C[], D_004CB1F0[];
extern s32 D_004468F8[], D_004468B8[], D_004468D8[], D_00446918[];
extern s32 D_004C28B0, D_004C28B8, D_004C28BC;
extern void func_00413D30();

void func_0016F0E0(void)
{
    s32 a = D_004C28B8;
    D_004CB1F4[0] = 0;
    D_004CB1FC[0] = 0;
    D_004CB200[0] = 0;
    D_004CB204[0] = 0;
    D_004CB208[0] = 0;
    D_004CB210[0] = 0;
    D_004CB218[0] = 0;
    D_004CB21C[0] = 0;
    D_004CB1F0[0] = a + 0x67000;
    D_004CB20C[0] = a + 0x67000;
    D_004CB1F8[0] = D_004C28BC + 0x3D0000;
    D_004CB214[0] = D_004C28BC + 0x7C0000;
    D_004468B8[0] = D_004C28B0;
    D_004468F8[0] = a + 0xF7000;
    D_004468D8[0] = a + 0x67000;
    D_00446918[0] = a + 0x80000;
    func_00413D30();
}
