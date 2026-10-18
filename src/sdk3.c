typedef signed int s32;
typedef unsigned int u32;
typedef signed char s8;
extern void func_0040E4B0(void);
extern void func_0040E930(void);
extern void func_0040E980(void);
extern void func_003F81F0(void *p, void *q);
extern void func_00402DE0(u32 a, u32 b, u32 c);
extern void func_00104210(s32 a, void *b);
extern void func_003F6150(void *p);

void func_003FF0B0(void) { func_0040E4B0(); }
void func_003FF118(void) { func_0040E930(); }
void func_003FF148(void) { func_0040E980(); }
void func_003FFEE0(s32 *p, void *q) { func_003F81F0((void *)p[1], q); }
void func_00402DC8(u32 a, u32 b) { func_00402DE0(a, b, 0x40000000); }
void func_003F63E0(s8 *p) { if (p[1] == 2) func_003F6150(p); }
