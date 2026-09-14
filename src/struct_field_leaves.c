typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

void func_003BD2D0(u8 *p) { p[432] = 65; p[433] = 65; }
void func_003BD4A0(u8 *p) { p[4]++; p[5] = 0; p[6] = 0; }
void func_003BD480(u8 *p) { p[4]++; p[5] = 1; p[6] = 0; }
void func_003BB8F0(u8 *p) { p[4]++; p[5] = 0; p[6] = 0; p[316] = 1; }
void func_003BB910(u8 *p) { p[4]++; p[5] = 1; p[6] = 0; p[316] = 1; }
void func_002AE2F0(u8 *p) { p[1036] = 2; p[828] = 5; p[6]++; }

s32 func_003D8680(u8 *p) { p[62] = 0; return 1; }
s32 func_003D8690(u8 *p) { p[62] = 1; return 1; }
s32 func_003D86A0(s8 *p) { p[62] = -1; return 1; }

s32 func_00105F00(s32 *a, s32 *b) { return b[2] = a[4]; }
void func_003F0A40(s32 *base, s32 *rec) { base[rec[1] + 3] = rec[0]; }
void func_004043B0(u16 *p, s32 a, s32 b, s32 c) { p[28] = c; p[26] = a; p[27] = b; }

s32 func_00400BC8(s32 *p, s32 v) { p[11] = v; return 1; }
s32 func_00400C18(s32 *a, s32 *b) { *b = 0; return 1; }
