typedef unsigned char u8;
typedef signed char s8;

extern void func_001E3210();
extern void func_003B3870(u8 *);

void func_003A58E0(u8 *p) { p[4]++; p[316] = 0; func_001E3210(p, 43); }

void func_003B1A50(u8 *p) { p[4]++; p[316] = 0; func_001E3210(p, 43); }

void func_003B3860(u8 *p) { p[4]++; func_003B3870(p); }
