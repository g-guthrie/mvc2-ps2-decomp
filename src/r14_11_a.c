/* func_001016C0 = libgraph sceGsExecStoreImage.
 * Sony EE GCC 2.9-ee-991111 cc1 (EE29CC1) -O2 -G0 -ffunction-sections, assembled with
 * GNU as 2.10-ee (EEAS210). The jump table must be referenced as jtbl_004AADD0
 * (rewrite %hi/%lo($Ln) in the .s before assembling, as the rb67_c.c stanza does). */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u64 SBP:14, :2, SBW:6, :2, SPSM:6, :2, DBP:14, :2, DBW:6, :2, DPSM:6, :2;
} GsBitbltbuf;

typedef struct {
    u64 RRW:12, :20, RRH:12, :20;
} GsTrxreg;

typedef struct {
    u64 vifcode[2];
    u64 giftag0[2];
    GsBitbltbuf bitbltbuf;
    u64 bitbltbufaddr;
    u64 trxpos;
    u64 trxposaddr;
    GsTrxreg trxreg;
    u64 trxregaddr;
    u64 finish;
    u64 finishaddr;
    u64 giftag1[2];
    u64 trxdir;
    u64 trxdiraddr;
} GsStoreImage;

extern char D_004AACF0[];
extern char D_004AAD28[];
extern char D_004AAD58[];
extern char D_004AAD98[];
extern u128 D_004381C0;
extern void func_00105E80(char *, ...);
extern u64 func_00104100(void);
extern u64 func_00104120(u64);

#define GS_CSR (*(volatile u64 *)0x12001000)
#define GS_BUSDIR (*(volatile u64 *)0x12001040)
#define VIF1_STAT (*(volatile u32 *)0x10003C00)
#define VIF1_FBRST (*(volatile u32 *)0x10003C10)
#define GIF_CTRL (*(volatile u32 *)0x10003000)
#define VIF1_FIFO (*(volatile u128 *)0x10005000)
#define VIF1_CHCR (*(volatile u32 *)0x10009000)
#define VIF1_MADR (*(volatile u32 *)0x10009010)
#define VIF1_QWC (*(volatile u32 *)0x10009020)

int func_001016C0(GsStoreImage *sp, u128 *dst)
{
    u32 timeout = 0;
    s32 dmaqwc = 0, fifoqwc = 0, rest = 0, extra = 0;
    s32 w, h, h2, bytes, qwc, i;
    u64 imask;
    union { u128 q; unsigned char b[16]; } tmp;

    w = sp->trxreg.RRW;
    h = sp->trxreg.RRH;
    h2 = 0;
    switch (sp->bitbltbuf.SPSM) {
    case 0: case 48:
        bytes = w * h * 4;
        rest = bytes & 0xF;
        dmaqwc = (bytes >> 4) & ~7u;
        fifoqwc = (bytes >> 4) & 7;
        if (rest == 0) { h2 = h; extra = 0; break; }
        h2 = (h + 3) & ~3;
        qwc = ((w * h2) >> 2);
        extra = qwc - dmaqwc - fifoqwc - 1;
        break;
    case 1: case 49:
        bytes = w * h * 3;
        rest = bytes & 0xF;
        dmaqwc = (bytes >> 4) & ~7u;
        fifoqwc = (bytes >> 4) & 7;
        if (rest == 0) { h2 = h; extra = 0; break; }
        h2 = (h + 15) & ~15;
        qwc = ((w * h2 * 3) >> 4);
        extra = qwc - dmaqwc - fifoqwc - 1;
        break;
    case 2: case 10: case 50: case 58:
        bytes = w * h * 2;
        rest = bytes & 0xF;
        fifoqwc = (bytes >> 4) & 7;
        dmaqwc = (bytes >> 4) & ~7u;
        if (rest == 0) { h2 = h; extra = 0; break; }
        h2 = (h + 7) & ~7u;
        qwc = ((w * h2) >> 3);
        extra = qwc - dmaqwc - fifoqwc - 1;
        break;
    case 19: case 27:
        bytes = w * h;
        rest = bytes & 0xF;
        fifoqwc = (bytes >> 4) & 7;
        dmaqwc = (bytes >> 4) & ~7u;
        if (rest == 0) { h2 = h; extra = 0; break; }
        h2 = (h + 7) & ~7u;
        qwc = ((w * h2) >> 4);
        extra = qwc - dmaqwc - fifoqwc - 1;
        break;
    case 20: case 36: case 44:
        bytes = (w * h) >> 1;
        rest = bytes & 0xF;
        fifoqwc = (bytes >> 4) & 7;
        dmaqwc = (bytes >> 4) & ~7u;
        if (rest == 0) { h2 = h; extra = 0; break; }
        h2 = (h + 7) & ~7u;
        qwc = ((w * h2) >> 5);
        extra = qwc - dmaqwc - fifoqwc - 1;
        break;
    }
    if (rest != 0) {
        *(u64 *)((u32)&sp->trxreg | 0x20000000) = (u64)(s32)sp->trxreg.RRW | ((u64)h2 << 32);
    }

    while (VIF1_CHCR & 0x100) {
        if (timeout++ > 0x1000000) {
            func_00105E80(D_004AACF0);
            return -1;
        }
    }
    imask = func_00104120(func_00104100() | 0x200);
    GS_CSR = 2;
    VIF1_QWC = 7;
    if (((u32)sp & 0x70000000) == 0x70000000)
        VIF1_MADR = ((u32)sp & 0x0FFFFFFF) | 0x80000000;
    else
        VIF1_MADR = (u32)sp & 0x0FFFFFFF;
    VIF1_CHCR = 0x101;
    while (VIF1_CHCR & 0x100) {
        if (timeout++ > 0x1000000) {
            func_00105E80(D_004AACF0);
            return -1;
        }
    }
    while (!(GS_CSR & 2)) {
        if (timeout++ > 0x1000000) {
            func_00105E80(D_004AAD28);
            VIF1_FIFO = D_004381C0;
            return -1;
        }
    }
    VIF1_STAT = 0x800000;
    GS_BUSDIR = 1;
    if (dmaqwc != 0) {
        VIF1_QWC = dmaqwc;
        if (((u32)dst & 0x70000000) == 0x70000000)
            VIF1_MADR = ((u32)dst & 0x0FFFFFFF) | 0x80000000;
        else
            VIF1_MADR = (u32)dst & 0x0FFFFFFF;
        VIF1_CHCR = 0x100;
        while (VIF1_CHCR & 0x100) {
            if (timeout++ > 0x1000000) {
                func_00105E80(D_004AAD58);
                GS_CSR = 0x100;
                GS_BUSDIR = 0;
                GIF_CTRL = 1;
                VIF1_FBRST = 1;
                return -1;
            }
        }
    }
    for (i = 0; i < fifoqwc; i++) {
        while (!(VIF1_STAT & 0x1F000000)) {
            if (timeout++ > 0x1000000) {
                func_00105E80(D_004AAD98);
                GS_CSR = 0x100;
                GS_BUSDIR = 0;
                GIF_CTRL = 1;
                VIF1_FBRST = 1;
                return -1;
            }
        }
        dst[dmaqwc + i] = VIF1_FIFO;
    }
    if (rest != 0) {
        while (!(VIF1_STAT & 0x1F000000)) {
            if (timeout++ > 0x1000000) {
                func_00105E80(D_004AAD98);
                GS_CSR = 0x100;
                GS_BUSDIR = 0;
                GIF_CTRL = 1;
                VIF1_FBRST = 1;
                return -1;
            }
        }
        tmp.q = VIF1_FIFO;
        for (i = 0; i < rest; i++)
            ((unsigned char *)&dst[dmaqwc + fifoqwc])[i] = tmp.b[i];
        for (i = 0; i < extra; i++) {
            while (!(VIF1_STAT & 0x1F000000)) {
                if (timeout++ > 0x1000000) {
                func_00105E80(D_004AAD98);
                GS_CSR = 0x100;
                GS_BUSDIR = 0;
                GIF_CTRL = 1;
                VIF1_FBRST = 1;
                return -1;
            }
            }
            tmp.q = VIF1_FIFO;
        }
    }
    VIF1_STAT = 0;
    GS_BUSDIR = 0;
    func_00104120(imask);
    {
        u128 q = D_004381C0;
        GS_CSR = 2;
        VIF1_FIFO = q;
    }
    return 0;

}
