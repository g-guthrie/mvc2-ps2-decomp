typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad0[0x1C]; s16 s1c; u8 pad1[2]; u8 b20; u8 pad2[0x53]; u32 f74; u8 pad3[0xC]; u8 *p84; u8 pad4[0x44]; s16 scc; } HM5A_S0;

extern u8 *D_0045F048[];
extern s32 D_0045F058[];
extern u8 *D_004C283C;
extern void func_003DAA40();

void func_0033D5F0(HM5A_S0 *p) {
    s16 v;
    p->f74 = 0x3F000000;
    p->scc = *(s16 *)((u8 *)D_0045F048[p->b20] + p->s1c * 4);
    p->p84 = D_004C283C;
    v = p->s1c + 1;
    p->s1c = v;
    if (v >= D_0045F058[p->b20]) func_003DAA40(p);
}
