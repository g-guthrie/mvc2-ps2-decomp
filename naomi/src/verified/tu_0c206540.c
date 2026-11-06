/* Shinobi sh4tmr_ (SH-4 TMU channel timers): syTmrInit .. syTmrGenDiffCount. */


#define TOCR  (*(volatile char *)0xffd80000)
#define TSTR  (*(volatile char *)0xffd80004)
#define TCOR0 (*(volatile long *)0xffd80008)
#define TCNT0 (*(volatile long *)0xffd8000c)
#define TCR0  (*(volatile short *)0xffd80010)
#define TCOR1 (*(volatile long *)0xffd80014)
#define TCNT1 (*(volatile long *)0xffd80018)
#define TCR1  (*(volatile short *)0xffd8001c)
#define TCOR2 (*(volatile long *)0xffd80020)
#define TCNT2 (*(volatile long *)0xffd80024)
#define TCR2  (*(volatile short *)0xffd80028)
#define IPRA  (*(volatile short *)0xffd00004)

typedef void (*TmrFunc)(void *);
extern TmrFunc dat_0c3a635c;
extern void *dat_0c3a6360;
extern TmrFunc dat_0c3a6364;
extern void *dat_0c3a6368;

int func_0c2065c8(unsigned long count, TmrFunc func, void *arg, int mode);
int func_0c20669c(void);
int func_0c2066c8(void);
unsigned long func_0c206570(unsigned long a, unsigned long b);

void func_0c206540(void)
{
    TOCR = 0;
    TSTR &= ~1;
    TCR0 = 2;
    TCOR0 = 0xffffffff;
    TCNT0 = 0xffffffff;
    TSTR |= 1;
}

unsigned long func_0c206566(void)
{
    return 0xffffffff - (unsigned long)TCNT0;
}

unsigned long func_0c206570(unsigned long a, unsigned long b)
{
    return b - a;
}

unsigned long func_0c206576(unsigned long count)
{
    return count % 100 * 128 / 100 + count / 100 * 128;
}

unsigned long func_0c2065aa(unsigned long micro)
{
    return ((micro & 127) * 100 >> 7) + (micro >> 7) * 100;
}

int func_0c2065c4(unsigned long count, TmrFunc func, void *arg)
{
    return func_0c2065c8(count, func, arg, 2);
}

int func_0c2065c8(unsigned long count, TmrFunc func, void *arg, int mode)
{
    if (TSTR & 2) return -1;
    TOCR = 0;
    TSTR &= ~2;
    TCR1 = mode;
    if (func) {
        *(void **)((char *)_builtin_get_vbr() + 0x244) = (void *)func_0c20669c;
        dat_0c3a635c = func;
        dat_0c3a6360 = arg;
        TCR1 |= 0x20;
        IPRA = (IPRA & 0xf0ff) | 0x0f00;
        TCR1 &= ~0x100;
    }
    TCOR1 = count;
    TCNT1 = count;
    TSTR |= 2;
    if (!func) {
        while (!(TCR1 & 0x100))
            ;
        TSTR &= ~2;
        TCR1 &= ~0x100;
    }
    return 0;
}

void func_0c206646(void)
{
    TSTR &= ~2;
    TCR1 &= ~0x20;
}

int func_0c20669c(void)
{
    TSTR &= ~2;
    TCR1 &= ~0x20;
    TCR1 &= ~0x100;
    dat_0c3a635c(dat_0c3a6360);
    return 0;
}

int func_0c2066c8(void)
{
    TSTR &= ~4;
    TCR2 &= ~0x20;
    TCR2 &= ~0x100;
    dat_0c3a6364(dat_0c3a6368);
    return 0;
}

void func_0c2066f4(void)
{
    TOCR = 0;
    TSTR |= 4;
}

void func_0c206704(void)
{
    TSTR &= ~4;
}

void func_0c20670e(TmrFunc func, void *arg)
{
    unsigned char save = TSTR;
    TSTR &= ~4;
    if (func) {
        *(void **)((char *)_builtin_get_vbr() + 0x248) = (void *)func_0c2066c8;
        dat_0c3a6364 = func;
        dat_0c3a6368 = arg;
        TCR2 |= 0x20;
        IPRA = (IPRA & 0xff0f) | 0x00f0;
        TCR2 &= ~0x100;
    }
    TSTR = save;
    if (!func) {
        TOCR = 0;
        TSTR |= 4;
        while (!(TCR2 & 0x100))
            ;
        TSTR &= ~4;
        TCR2 &= ~0x100;
    }
}

void func_0c20677a(void)
{
    unsigned char save = TSTR;
    TSTR &= ~4;
    TCR2 &= ~0x20;
    TSTR = save;
}

void func_0c2067c4(unsigned short clock)
{
    unsigned char save;
    if (clock != 0 && clock != 1 && clock != 2 && clock != 3 && clock != 4)
        clock = 2;
    save = TSTR;
    TSTR &= ~4;
    TCR2 = (TCR2 & ~7) | clock;
    TSTR = save;
}

void func_0c2067fe(unsigned long count)
{
    unsigned char save = TSTR;
    TSTR &= ~4;
    TCOR2 = 0xffffffff;
    TCNT2 = -count;
    TSTR = save;
}

unsigned long func_0c206818(void)
{
    return 0xffffffff - (unsigned long)TCNT2;
}

unsigned long func_0c206822(unsigned long micro, unsigned short clock)
{
    unsigned long div;
    switch (clock) {
    case 0: div = 8; break;
    case 1: div = 32; break;
    case 3: div = 512; break;
    case 4: div = 2048; break;
    default: div = 128; break;
    }
    return micro / 100 * div + micro % 100 * div / 100;
}

unsigned long func_0c206878(unsigned long count, unsigned short clock)
{
    unsigned long div;
    switch (clock) {
    case 0: div = 8; break;
    case 1: div = 32; break;
    case 3: div = 512; break;
    case 4: div = 2048; break;
    default: div = 128; break;
    }
    return count / div * 100 + count % div * 100 / div;
}

unsigned long func_0c2068ec(unsigned long a, unsigned long b)
{
    return func_0c206570(a, b);
}
