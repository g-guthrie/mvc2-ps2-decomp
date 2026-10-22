typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x1C];
    s16 h1C;
    s16 h1E;
    u8 pad20[0x33B - 0x20];
    u8 b33B;
    u8 b33C;
    u8 pad33D[0x40C - 0x33D];
    u8 b40C;
    u8 b40D;
} PA;

void func_002FAFF0(PA *p) {
    extern int func_00175700(PA *);
    extern void func_001843A0(PA *);
    extern void func_003B0860(PA *, s32, u8);
    extern void func_001E3210(PA *, s32);
    s32 i;
    p->b40C = 2;
    p->b33C = 5;
    if ((s8)func_00175700(p) < 0) {
        p->b40D = 0;
        p->b40C = 0;
        p->b33B = 0;
        p->b33C = 0;
        func_001843A0(p);
        return;
    }
    if (p->h1E != 0) {
        s16 t = p->h1C;
        p->h1C = t - 1;
        if (t == 0) {
            p->h1C = 30;
            p->h1E -= 1;
            i = 0;
            do {
                func_003B0860(p, 0, i);
                i++;
            } while (i < 6);
            func_001E3210(p, 0x22);
        }
    }
}
