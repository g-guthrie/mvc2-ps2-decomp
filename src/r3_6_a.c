typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct { u64 NLOOP:15; u64 EOP:1; u64 pad16:16; u64 id:14; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
  u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
  u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4; } GifTag;
typedef struct { u64 FBP:9; u64 FBW:6; u64 PSM:5; u64 p0:12; u64 DBX:11; u64 DBY:11; u64 p1:10; } DispFb;
typedef struct { u64 FBP:9; u64 p0:7; u64 FBW:6; u64 p1:2; u64 PSM:6; u64 p2:2; u64 FBMSK:32; } Frame;
typedef struct { u64 pmode; u64 smode2; DispFb dispfb; u64 display; u64 bgcolor; } DispEnv;
typedef struct { Frame frame1; u64 frame1addr; u64 r[14]; } DrawEnv1;
typedef struct { Frame frame2; u64 frame2addr; u64 r[14]; } DrawEnv2;
typedef struct { u64 r[12]; } Clear;
typedef struct { DispEnv disp[2]; GifTag giftag0; DrawEnv1 draw01; DrawEnv2 draw02; Clear clear0;
  GifTag giftag1; DrawEnv1 draw11; DrawEnv2 draw12; Clear clear1; } DBuffDc;
typedef struct { short sceGsInterMode; short sceGsOutMode; short sceGsFFMode; short sceGsVersion; } __attribute__((aligned(8))) GParam;
extern GParam *func_00100468(void);
extern int func_00100590(DispEnv *, short, short, short, short, short);
extern int func_00100A90(DrawEnv1 *, short, short, short, short, short);
extern int func_00101E78(DrawEnv2 *, short, short, short, short, short);
extern int func_00100C78(Clear *, short, short, short, short, short, u8, u8, u8, u8, u32);
extern int func_001009C8(short, short, short);

void func_001020E0(DBuffDc *db, short psm, short w, short h, short ztest, short zpsm, short clear)
{
    GParam *gp;
    int fbp;
    gp = func_00100468();
    func_00100590(&db->disp[0], psm, w, h, 0, 0);
    func_00100590(&db->disp[1], psm, w, h, 0, 0);
    func_00100A90(&db->draw01, psm, w, h, ztest, zpsm);
    func_00101E78(&db->draw02, psm, w, h, ztest, zpsm);
    func_00100A90(&db->draw11, psm, w, h, ztest, zpsm);
    func_00101E78(&db->draw12, psm, w, h, ztest, zpsm);
    if (clear) {
        func_00100C78(&db->clear0, ztest, 2048 - (w >> 1), 2048 - (h >> 1), w, h, 0, 0, 0, 0, 0);
        func_00100C78(&db->clear1, ztest, 2048 - (w >> 1), 2048 - (h >> 1), w, h, 0, 0, 0, 0, 0);
    }
    *(u128 *)&db->giftag0 = 0;
    *(u128 *)&db->giftag1 = 0;
    db->giftag0.NLOOP = clear ? 22 : 16;
    db->giftag0.EOP = 1;
    db->giftag0.NREG = 1;
    db->giftag0.REGS0 = 0xE;
    db->giftag1.NLOOP = clear ? 22 : 16;
    db->giftag1.EOP = 1;
    db->giftag1.NREG = 1;
    db->giftag1.REGS0 = 0xE;
    fbp = func_001009C8(psm, w, h);
    if ((gp->sceGsInterMode == 1 && gp->sceGsFFMode == 1) || gp->sceGsInterMode == 0) {
        short half = fbp >> 1;
        db->disp[1].dispfb.FBP = half;
        db->draw01.frame1.FBP = fbp >> 1;
        db->draw02.frame2.FBP = fbp >> 1;
    }
}
