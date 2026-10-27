typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C22CC;
extern volatile s32 D_004C22C8;
extern volatile s32 D_004C232C;
extern s32 D_004C239C;
extern s32 D_004C22D0;
typedef struct { s32 f0, f4, f8, fc, f10, f14, f18; } T3FED28;
extern T3FED28 D_0047D0E0;
extern void func_003FDC70(void *);
extern void func_003FDCD0(void);
extern void func_003FDDE8(void);
extern void func_003FDE10(void);
extern void func_00411B98(void);
extern void func_00411898(void *, s32);
extern void func_004118A8(void *, s32);
extern s32 func_00103CD0(void);
extern void func_00103CE0(s32, void *);
extern void func_00103C70(s32, s32);
extern void func_003FE258(void);
extern void func_003FE2F0(void);
extern void func_003FE368(void);
extern void func_003FE3E0(void);
extern void func_003FE468(void);
extern void func_004117C0(s32, void *, s32);

void func_003FED28(s32 *a)
{
    s32 buf[12];
    (void)D_004C22C8;
    if (D_004C22CC == 0) {
        func_00411B98();
        func_00411898(func_003FDC70, 0);
        func_004118A8(func_003FDCD0, 0);
        if (a == 0) {
            D_0047D0E0.f10 = 0x18;
            D_0047D0E0.f0 = 1;
            D_0047D0E0.f4 = 8;
            D_0047D0E0.f8 = 0xF;
            D_0047D0E0.fc = 0x10;
            D_0047D0E0.f14 = 0x19;
            D_0047D0E0.f18 = 0x1A;
        } else {
            D_0047D0E0.f10 = a[4];
            D_0047D0E0.f0 = a[0];
            D_0047D0E0.f4 = a[1];
            D_0047D0E0.f8 = a[2];
            D_0047D0E0.fc = a[3];
            D_0047D0E0.f14 = a[5];
            D_0047D0E0.f18 = a[6];
        }
        D_004C232C = func_00103CD0();
        func_00103CE0(D_004C232C, buf);
        { register s32 j __asm__("$3"); j = buf[6]; D_004C239C = j; }
        func_003FE258();
        func_003FE2F0();
        func_003FE368();
        func_003FE3E0();
        func_003FE468();
        func_00103C70(D_004C232C, D_0047D0E0.f10);
        func_004117C0(5, func_003FDDE8, 0);
        func_004117C0(6, func_003FDE10, 0);
        D_004C22D0 = 1;
    }
    D_004C22CC++;
}
