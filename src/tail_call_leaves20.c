typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void func_00175C00();
extern void func_003DAA40();
extern void func_001757E0();
extern void func_003C88C0(u8 *);
extern void func_0011D8F8();
extern void func_003DCDC0();
extern void func_003F5270();

void func_003BD7F0(void *p, u8 *unused) { func_00175C00(*(void **)((u8 *)p + 208), 1); }

void func_003BE5E0(u8 *p) { p[0] = 0; p[316] = 0; func_003DAA40(p); }

void func_003C0550(void *p, u8 *q) { *(s16 *)(q + 28) = 50; func_003DAA40(p, q); }

void func_003C6500(u8 *p) { p[5] = 8; func_001757E0(p, 21, 28); }

void func_003C6520(u8 *p) { p[5] = 8; func_001757E0(p, 21, 29); }

void func_003C8650(u8 *p) { p[5] = 2; p[6] = 0; func_003C88C0(p); }

void func_003D6B60(void *p) { func_0011D8F8(p, 0, 8); }

void func_00420970(void *p) { func_0011D8F8(p, 0, 32); }

void func_003EF980(s32 a, s32 b, s32 c) { func_003DCDC0(b, c, a); }

void func_003F5070(void *p) { func_003F5270(p, 0, 0); }
