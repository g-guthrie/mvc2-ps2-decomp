typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC 2.96, $gp globals: ./tryee8.sh src/r5_c.c sn */

typedef struct { s8 a; char pad[0x1BF]; } E4680;
extern s32 D_004C2418;
extern E4680 D_00485880[];
extern void func_00404968(void *);
extern void func_0011D8F8(void *, s32, s32);
void func_00404680(void) {
    s32 i;
    if (--D_004C2418 == 0) {
        for (i = 0; i < 4; i++) { if (D_00485880[i].a == 1) func_00404968(&D_00485880[i]); }
        func_0011D8F8(D_00485880, 0, 0x700);
    }
}

extern s32 func_003FF5C8(s32);
extern s32 func_003FFF90(void *);
extern s32 D_004C2404;
extern s32 D_004C2408;
typedef struct VO { s32 (**vt)(struct VO *, s32); } VO;
typedef struct { u8 p0; u8 f1; char p2[2]; s32 f4; char p8[0x10]; VO *objs[1]; } Q3A70;

void func_00403A70(Q3A70 *q) {
    s32 r, n, i; VO **pp;
    if (func_003FF5C8(q->f4) == 3) {
        i = 0;
        n = func_003FFF90((void *)q->f4);
        pp = q->objs;
        D_004C2404 = n;
        for (; i < n; i++) {
            VO *o = *pp++;
            r = o->vt[9](o, 1);
            D_004C2408 = r;
            if (r >= 0x40) break;
        }
        if (i == n) {
            *(s32 *)((u8 *)q + 0xA8) = 0;
            q->f1 = 4;
        }
    }
}
