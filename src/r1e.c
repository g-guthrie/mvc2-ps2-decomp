typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
extern void func_001B5350(u8 *a, u8 *p, s32 t);
extern void func_001754A0(u8 *p, s32 a, s32 b);
void func_001B5290(u8 *p) { u8 *q = *(u8 **)(p + 0x18); u32 t = p[6] + 1; p[6] = t; p[0x13C] = 1; *(s16 *)(p + 0x1C) = 0x78; func_001B5350(q, p, t); func_001754A0(p, 0x1B, p[0x20]); p[0x24] = 0xB; }
