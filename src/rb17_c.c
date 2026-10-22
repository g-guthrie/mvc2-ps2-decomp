typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u64 NLOOP : 15;
    u64 EOP : 1;
    u64 pad16 : 30;
    u64 PRE : 1;
    u64 PRIM : 11;
    u64 FLG : 2;
    u64 NREG : 4;
    u64 REGS0 : 4;
    u64 pad68 : 60;
} Tag;

typedef struct {
    u32 w[4];
    Tag giftag;
    u64 bitbltbuf;
    u64 bitbltbufaddr;
    u64 trxpos;
    u64 trxposaddr;
    u64 trxreg;
    u64 trxregaddr;
    u64 finish;
    u64 finishaddr;
    u64 trxdir;
    u64 trxdiraddr;
} Store;

int func_00101400(Store *sp, short sbp, short sbw, short spsm, short x, short y, short w, short h) {
    sp->w[0] = 0;
    sp->w[1] = 0x06008000;
    sp->w[2] = 0x13000000;
    sp->w[3] = 0x50000006;
    *(u128 *)&sp->giftag = 0;
    sp->giftag.NLOOP = 5;
    sp->giftag.EOP = 1;
    sp->giftag.NREG = 1;
    sp->giftag.REGS0 = 0xE;
    sp->bitbltbuf = (long)sbp | (sbw << 16) | ((long)spsm << 24);
    sp->bitbltbufaddr = 0x50;
    sp->trxpos = (long)x | ((long)y << 16);
    sp->trxposaddr = 0x51;
    sp->trxreg = (long)w | ((long)h << 32);
    sp->trxregaddr = 0x52;
    sp->finish = 0;
    sp->finishaddr = 0x61;
    sp->trxdir = 1;
    sp->trxdiraddr = 0x53;
    __asm__ volatile("sync");
    return 7;
}
