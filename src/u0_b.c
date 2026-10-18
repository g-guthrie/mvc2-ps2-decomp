typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
extern s32 D_004C22B4, D_004C2448, D_004C22BC;
extern void func_003FF0B0(), func_003FB460(), func_00400130(), func_0040D6A0(), func_003F9630(), func_00411BC8(), func_003FF388(), func_003FB0D8(), func_0040F070(), func_0040F598(), func_0040FD78(), func_003F9660();
extern void func_004116B0(s32, s32);
void func_003FDBC0(void) {
    if (--D_004C22B4 == 0) {
        D_004C2448 = 0;
        func_003FF0B0();
        func_003FB460();
        func_00400130();
        func_0040D6A0();
        func_003F9630();
        func_004116B0(2, 1);
        func_004116B0(2, 3);
        func_004116B0(4, D_004C22BC);
        func_00411BC8();
        func_003FF388();
        func_003FB0D8();
        func_0040F070();
        func_0040F598();
        func_0040FD78();
        func_003F9660();
        D_004C2448 = 1;
    }
}
