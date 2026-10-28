/* MW 3.0 (./try30.sh) -O3 -sdatathreshold 0. sync/ei are privileged (no compiler emits them); split into two asm statements so 3.0 accepts ei. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct BFa {
    unsigned f0 : 6;
    unsigned f6 : 1;
    unsigned f7 : 1;
} BFa;

typedef struct DQa {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC[2];
    s32 f14[2];
    s32 f1C[2];
    s32 f24[2];
    u32 f2C;
} DQa;

extern s32 D_0062BFD8;
extern DQa D_0062BBA0;
extern DQa D_0062BBD0;
extern BFa *D_0062BF9C[];
extern u32 *D_00477860[];

s32 func_003DC3C0(s32 a)
{
    extern u32 *func_003DD030(s32);
    extern void func_001028B0();
    extern void func_003EF980(s32, s32, s32);
    DQa *s;
    s32 i;
    u32 *base;
    u32 w;
    u32 f;
    u32 *m;
    u32 v;
    u32 t;
    u32 wm;

    if (a == 1) {
        s = &D_0062BBA0;
    } else if (a == 2) {
        s = &D_0062BBD0;
    }
    switch (a) {
    case 1:
    case 2:
        f = *D_00477860[s->f0];
        if (!(f & 0x100) && (f & 0xC) == 4 && (f & 0x80000000)) {
            i = D_0062BFD8 ^ 1;
            base = func_003DD030(s->fC[i]);
            s->f14[i]--;
            s->f24[i]++;
            if (s->f24[i] == s->f4) {
                s->f24[i] = 0;
            }
            if (s->f1C[i] != s->f24[i]) {
                wm = base[s->f24[i]];
                w = wm;
                t = (w & 0xF0000000) >> 28;
                s->f2C = w;
                wm = w;
                wm &= 0xFFFFFFF;
                if (wm != 0) {
                    switch (t) {
                    case 0:

                        D_0062BF9C[s->f0]->f6 = 1;
                        D_0062BF9C[s->f0]->f7 = 1;
                        func_001028B0(D_0062BF9C[s->f0], wm);
                        break;
                    case 1:

                        D_0062BF9C[s->f0]->f6 = 1;
                        D_0062BF9C[s->f0]->f7 = 1;
                        func_001028B0(D_0062BF9C[s->f0], wm);
                        break;
                    case 2:
                        m = (u32 *)wm;
                        if (m[2] != 0) {
                            func_003EF980(m[2], m[1] | 0x20000000, m[3]);
                        }
                        D_0062BF9C[s->f0]->f6 = 1;
                        D_0062BF9C[s->f0]->f7 = 1;
                        func_001028B0(D_0062BF9C[s->f0], m[0]);
                        break;
                    case 3:
                        D_0062BF9C[s->f0]->f6 = 1;
                        D_0062BF9C[s->f0]->f7 = 1;
                        func_001028B0(D_0062BF9C[s->f0], wm);
                        break;
                    }
                }
            }
        }
        break;
    }
    __asm__ volatile ("sync"); __asm__ volatile ("ei");
    return 0;
}
