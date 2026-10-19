/* Restore six records' slot indices and rebuild the two interleaved pointer lists.
 * The record view exposes only the two native byte fields; list extents stay unspecified. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    u8 pad0[0x425];
    u8 slot425;
    u8 pad426[0x12D];
    u8 slot553;
} SlotRecord;
extern u8 D_004D18A0[];
extern u8 D_004C27D0 __attribute__((section(".sdata")));
extern SlotRecord D_004F20B0, D_004F2668, D_004F2C20, D_004F31D8, D_004F3790, D_004F3D48;
extern SlotRecord *D_004D18B8[], *D_004D18C4[];
extern void *func_0011D8F8(void *,int,u32);
extern void func_003D91B0(void);
void func_003D7F10(void) {
    u8 slot0,slot2,slot4,slot1,slot3,slot5;
    func_0011D8F8(D_004D18A0,0,0x94);
    D_004D18A0[0x32]=0;
    D_004D18A0[0x30]=6;
    D_004D18A0[0x31]=1;
    D_004D18A0[0x48]=D_004C27D0;
    func_003D91B0();
    slot0=D_004F20B0.slot553;
    slot2=D_004F2C20.slot553;
    slot4=D_004F3790.slot553;
    slot1=D_004F2668.slot553;
    slot3=D_004F31D8.slot553;
    slot5=D_004F3D48.slot553;
    D_004F20B0.slot425=slot0;
    D_004F2C20.slot425=slot2;
    D_004F3790.slot425=slot4;
    D_004F2668.slot425=slot1;
    D_004F31D8.slot425=slot3;
    D_004F3D48.slot425=slot5;
    D_004D18B8[D_004F20B0.slot425]=&D_004F20B0;
    D_004D18C4[D_004F2668.slot425]=&D_004F2668;
    D_004D18B8[D_004F2C20.slot425]=&D_004F2C20;
    D_004D18C4[D_004F31D8.slot425]=&D_004F31D8;
    D_004D18B8[D_004F3790.slot425]=&D_004F3790;
    D_004D18C4[D_004F3D48.slot425]=&D_004F3D48;
}
