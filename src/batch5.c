typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern void func_001E3710(u8 *p, u8 a);
extern void func_00170E60(s32 a, s32 b, s32 c, s32 d, void *e, u8 *f);
extern void func_00330FF0(void);
extern void func_003311A0(void);

s32 func_0012BFB0(s32 a) {
    u32 *w = (u32 *)(D_004C2840 + 0x30);
    if (a >= 0x18) w = (u32 *)((u8 *)w + 4);
    if (*w & (1 << (a & 0x1F))) return 1;
    return 0;
}

void func_001E3B30(u8 *p) {
    u8 a;
    if ((p[0x216] & 0x80) || p[0x21B] >= 5) a = 0x2D;
    else a = 0x2C;
    func_001E3710(p, a);
}

void func_00330E70(u8 *p) {
    u8 *q = *(u8 **)(p + 0x84);
    func_00170E60(*(s32 *)(q + 0x14), ((s32 *)*(u8 **)(q + 0x1C))[*(s16 *)(p + 0xCC)],
                  *(s32 *)(q + 0x14), ((s32 *)*(u8 **)(q + 0x1C))[*(s16 *)(p + 0xCC)],
                  func_00330FF0, p);
}

void func_00330EB0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x84);
    func_00170E60(*(s32 *)(q + 0x14), ((s32 *)*(u8 **)(q + 0x1C))[*(s16 *)(p + 0xCC)],
                  *(s32 *)(q + 0x14), ((s32 *)*(u8 **)(q + 0x1C))[*(s16 *)(p + 0xCC)],
                  func_003311A0, p);
}

