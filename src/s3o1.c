typedef signed int s32;
typedef struct E8 { s32 v; s32 pad; } E8;
extern E8 *D_004C3AE4, *D_004C3AEC;
void func_00106270(s32 a) { s32 o = a << 3; if (a < 0) a = (s32)D_004C3AE4; else a = (s32)D_004C3AEC; o += a; *(s32*)o = 0; }
