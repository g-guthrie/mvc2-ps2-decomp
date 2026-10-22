typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x1B8]; u8 b1B8; u8 pad1[0x27B]; s16 h434; } Ent;
typedef struct { u8 pad[0x18]; Ent *tab[1][3]; } G88;
extern G88 *D_004C2794;
extern u8 D_004D18A0[];
extern s8 D_004D18D4[];

s32 func_00188690(u8 *p) {
    extern s32 func_0018AA10();
    extern s32 func_0018A580();
    s16 buf;
    s32 n;
    s32 cnt;
    s32 mask;
    u8 *o;
    s32 i;
    if ((s8)p[0x539] == 0 || p[0x471] == 0 || (s8)p[0x45C] != 0x7E) {
        if (func_0018AA10(p, 0x90, &buf) == 0) return 0;
    }
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) return 0;
    if (D_004D18A0[0] >= 5) return 0;
    if (D_004D18D4[p[2]] > 1) return 0;
    n = *(s8 *)*(u8 **)(p + 0x420);
    if (n == 0) return 0;
    if ((s8)p[0x205] != 0) return 0;
    if (n > 3) n = 3;
    cnt = 1;
    mask = (1 << ((s32)p[0x1B8] / 2)) & 0xFF;
    for (i = 1; i < 3 && cnt < n; i++) {
        o = (u8 *)D_004C2794->tab[p[2]][i];
        if (*(s16 *)(o + 0x434) > 0 && *(s16 *)(o + 0x2B4) == 0) {
            mask = (mask | ((1 << ((s32)o[0x1B8] / 2)) & 0xFF)) & 0xFF;
            cnt++;
        }
    }
    p[0x26D] = cnt;
    p[0x33D] = mask;
    p[0x268] = 4;
    return 1;
}
