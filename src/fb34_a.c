typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern void func_00175700(s8 *);
extern void func_001E3710(s8 *, s32);
extern s32 func_00174170(void);
extern void func_0034BFB0(s8 *, s32, s32);

#define SETBIT(m, n) \
    { s32 h = *(s16 *)(p + 0x1E); \
      if ((h & m) == 0) { *(s16 *)(p + 0x1E) = h | m; func_0034BFB0(p, 0, n); } }

void func_00206790(s8 *p) {
    s32 s0;
    s32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[0x150] != 0) {
        p[0x150] = 0;
        func_001E3710(p, 0x30);
    }
    v = p[0x151];
    if (v != 0) {
        if ((s8)v == -1) {
            u32 t = *(u8 *)(p + 6);
            p[6] = t + 1;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            return;
        }
        {
            u32 a = *(u8 *)(p + 0x269);
            if (a == 5 || p[0x539] != 0 || a == 4) {
                if ((*(s32 *)(D_004C2840 + 0x1C) & 7) == 0) {
                    s0 = func_00174170() & 0xF;
                    if (s0 & 1) SETBIT(1, 0)
                    if (s0 & 2) SETBIT(2, 1)
                    if (s0 & 4) SETBIT(4, 2)
                    if (s0 & 8) SETBIT(8, 3)
                }
            } else {
                if (*(u16 *)(p + 0x35C) & 0x200) SETBIT(1, 0)
                if (*(u16 *)(p + 0x35C) & 0x100) SETBIT(2, 1)
                if (*(u16 *)(p + 0x35C) & 0x40) SETBIT(4, 2)
                if (*(u16 *)(p + 0x35C) & 0x20) SETBIT(8, 3)
            }
        }
    }
}
