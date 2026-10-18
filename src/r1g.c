typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;typedef signed int s32;
extern s8 *D_004C2938;
static void func_003460D0(u8 *p) { s16 v = *(s16 *)(p + 0x1C) - 1; *(s16 *)(p + 0x1C) = v; if (v <= 0) { s8 *a; *(s16 *)(p + 0x1C) = 2; a = D_004C2938; *a = *a - 1; } }
void func_00346410(u8 *p) { if ((*(u8 **)(p + 0x18))[0x169] != 0x16) { u32 t = p[4]; p[4] = t + 1; p[0x13C] = 0; } else { ((u8 *)D_004C2938)[7] = 0; func_003460D0(p); if (*D_004C2938 < 0) { u32 t = p[4]; p[4] = t + 1; } } }

extern s8 *D_004C29C4;
static void func_0038E700(u8 *p) { s16 v = *(s16 *)(p + 0x1C) - 1; *(s16 *)(p + 0x1C) = v; if (v <= 0) { s8 *a; *(s16 *)(p + 0x1C) = 2; a = D_004C29C4; *a = *a - 1; } }
void func_0038EA30(u8 *p) { if ((*(u8 **)(p + 0x18))[0x169] != 0x16) { u32 t = p[4]; p[4] = t + 1; p[0x13C] = 0; } else { ((u8 *)D_004C29C4)[7] = 0; func_0038E700(p); if (*D_004C29C4 < 0) { u32 t = p[4]; p[4] = t + 1; } } }
