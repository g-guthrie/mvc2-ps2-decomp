typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_0018DDD0(u8 *);
extern void func_0018E0B0(u8 *);
extern void func_00199DD0(u8 *);
extern void func_001BD140(u8 *);
extern void func_001C4C30(u8 *);
extern void func_001C5110(s8 *);
extern void func_001757E0(u8 *, int, int);

void func_0018DDC0(u8 *p) { p[584] = 1; func_0018DDD0(p); }

void func_0018E0A0(u8 *p) { p[584] = 1; func_0018E0B0(p); }

void func_00199DC0(u8 *p) { p[4] = 3; p[316] = 0; func_00199DD0(p); }

void func_001BD130(u8 *p) { p[5]++; func_001BD140(p); }

void func_001C4C10(u8 *p) { p[5]++; p[316] = 1; func_001C4C30(p); }

void func_001C4DA0(s8 *p) { p[316] = p[28] & 1; func_001C5110(p); }

void func_001870A0(u8 *p) {
    p[525] = 0;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    func_001757E0(p, 3, 2);
}
