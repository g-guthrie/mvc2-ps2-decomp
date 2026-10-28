extern int func_00104F08(int a0, void *a1, unsigned short a2);
extern int func_00104F40(int a0, void *a1, unsigned short a2);
extern void func_00105048(void *r);
extern char D_004AAF58[];
extern char D_004AAF80[];
extern char D_004AAF98[];
extern char D_004AAFB0[];

struct ring {
    unsigned char *f0;
    volatile unsigned int f4;
    volatile unsigned int f8;
    volatile unsigned int fC;
    unsigned int f10;
    unsigned int f14;
    void *f18;
};

struct ostr {
    char pad[0xC];
    unsigned char *fC;
};

extern void func_00105E48(const char *fmt, ...);

void func_001050C8(int mode, int n, struct ring *c)
{
    int t;
    unsigned short *h;

    switch (mode) {
    case 1:
    case 2:
        if (n != 0) {
            if (c->f8 + n > 0x140) {
                func_00105E48(D_004AAF58);
            }
            { unsigned int o = c->f8; n = func_00104F08((int)c->f0, (void *)(c->f14 + o), n & 0xFFFF); }
            if (n < 0) {
                func_00105E48(D_004AAF80);
            }
            c->f8 += n;
        } else {
            h = (unsigned short *)c->f14;
            for (n = 0xC; n < *h; n++) {
                *((struct ostr *)c->f18)->fC = ((unsigned char *)c->f14)[n];
                func_00105048(c->f18);
            }
            c->f8 = 0;
        }
        return;
    case 3:
        t = func_00104F40((int)c->f0, (void *)c->f10, c->f4 & 0xFFFF);
        if (t < 0) {
            func_00105E48(D_004AAF98, t);
        } else {
            c->f10 += t;
            c->f4 -= t;
            return;
        }
        break;
    case 4:
        if (c->f4 != 0) {
            func_00105E48(D_004AAFB0, c->f4);
        }
        break;
    default:
        return;
    }
    c->fC = 0;
}
