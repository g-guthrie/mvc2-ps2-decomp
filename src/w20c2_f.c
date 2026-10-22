typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_004C1974; extern s32 D_004F1CDC[];
typedef struct { u8 p0[4]; u8 st; u8 p1[0x17]; s16 h1C; u8 p2[0x5A]; f32 f78; f32 f7C; } S;
void func_003450C0(S *p){ s32 v; switch (p->st) { case 0: if (D_004F1CDC[0] >= 2) p->st = p->st + 1; break; case 1: p->f78 += 1.0f / (f32)D_004C1974; p->f7C -= 1.0f / (f32)D_004C1974; v = (s16)(p->h1C + 1); p->h1C = v; if (v >= D_004C1974) { p->st = 2; p->h1C = 0; p->f78 = 1.0f; *(s32*)&p->f7C = 0; } break; case 2: break; } }
