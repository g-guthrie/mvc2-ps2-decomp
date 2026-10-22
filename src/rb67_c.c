typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4; u64 REGS0:4; u64 REGS1:4;
    u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4; u64 REGS8:4; u64 REGS9:4;
    u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} GifTag67;
typedef struct {
    GifTag67 giftag0;
    long bitbltbuf; long bitbltbufaddr;
    long trxpos; long trxposaddr;
    long trxreg; long trxregaddr;
    long trxdir; long trxdiraddr;
    GifTag67 giftag1;
} LoadImage67;

extern void func_00105E80(const char *, ...);
extern char D_004AAB90[];

int func_00101218(LoadImage67 *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h) {
    int size = 0;
    switch (dpsm) {
    case 0:
    case 0x30:
        size = (w * h) >> 2; break;
    case 1:
    case 0x31:
        size = (w * h * 3) >> 4; break;
    case 2:
    case 0xA:
    case 0x32:
    case 0x3A:
        size = (w * h) >> 3; break;
    case 0x13:
    case 0x1B:
        size = (w * h) >> 4; break;
    case 0x14:
    case 0x24:
    case 0x2C:
        size = (w * h) >> 5; break;
    }
    if (size > 0x7FFF) {
        func_00105E80(D_004AAB90);
        return 0;
    }
    *(u128 *)&lp->giftag1 = 0;
    *(u128 *)&lp->giftag0 = 0;
    lp->giftag0.NLOOP = 4;
    lp->giftag0.NREG = 1;
    lp->giftag0.REGS0 = 0xE;
    lp->bitbltbuf = ((long)dbp << 32) | ((long)dbw << 48) | ((long)dpsm << 56);
    lp->bitbltbufaddr = 0x50;
    lp->trxpos = ((long)x << 32) | ((long)y << 48);
    lp->trxposaddr = 0x51;
    lp->trxreg = (long)w | ((long)h << 32);
    lp->trxregaddr = 0x52;
    lp->trxdiraddr = 0x53;
    lp->trxdir = 0;
    lp->giftag1.NLOOP = size;
    lp->giftag1.EOP = 1;
    lp->giftag1.FLG = 2;
    __asm__ volatile("sync");
    return 6;
}
