typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } P;
extern s32 D_004C22CC;
extern volatile s32 D_004C22C8;
extern volatile s32 D_004C22EC;
extern volatile s32 D_004C232C;
extern s32 D_004C239C;
extern P D_0047D0E0;
void func_003FE5D8(P *a) {
    extern s32 func_00411B98();
    extern void func_00411898();
    extern void func_004118A8();
    extern s32 func_00103CD0();
    extern s32 func_00103CE0();
    extern void func_003FE258();
    extern void func_003FE368();
    extern void func_003FE3E0();
    extern void func_00103C70();
    extern void func_004117C0();
    extern void func_003FDC70(void *);
    extern void func_003FDCD0();
    extern void func_003FDDE8();
    s32 buf[12]; s32 k;
    (void)D_004C22C8;
    D_004C22EC = 0;
    if (D_004C22CC == 0) {
        func_00411B98();
        func_00411898(func_003FDC70, 0);
        func_004118A8(func_003FDCD0, 0);
        if (a == 0) {
            D_0047D0E0.f10 = 0x18;
            D_0047D0E0.f0 = 1;
            D_0047D0E0.f4 = 8;
            D_0047D0E0.fC = 0x10;
            D_0047D0E0.f14 = 0x19;
        } else {
            D_0047D0E0.f10 = a->fC;
            D_0047D0E0.f0 = a->f0;
            D_0047D0E0.f4 = a->f4;
            D_0047D0E0.fC = a->f8;
            D_0047D0E0.f14 = a->f10;
        }
        D_004C232C = func_00103CD0();
        func_00103CE0(D_004C232C, buf);
        k = buf[6]; D_004C239C = k;
        func_003FE258();
        func_003FE368();
        func_003FE3E0();
        func_00103C70(D_004C232C, D_0047D0E0.f10);
        func_004117C0(5, func_003FDDE8, 0);
    }
    D_004C22CC++;
}
