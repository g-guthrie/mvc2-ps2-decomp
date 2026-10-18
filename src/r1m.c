typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;typedef unsigned int u32;typedef signed int s32;
extern u8 D_004B1220[];
void func_001377F0(u8 *p) { u8 *b = D_004B1220; switch (b[p[0x21] * 2]) { case 0: case 7: *(s16 *)(p + 0x1C) = 0x28; break; case 1: case 6: *(s16 *)(p + 0x1C) = 0x26; break; case 2: case 5: *(s16 *)(p + 0x1C) = 0x24; break; default: *(s16 *)(p + 0x1C) = 0x22; break; } }
