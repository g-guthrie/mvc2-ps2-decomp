typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#define P(t,o) (*(t*)(p+(o)))
#define Q(t,o) (*(t*)(*(u8**)(p+0x18)+(o)))

extern u8 *D_004C2840;
extern s32 D_004C28BC;
extern s32 D_004C28B8;
extern s32 D_004C28AC;
extern void func_0012DA40();
extern void func_00176230(s16 *, s16 *);
void func_0016F810(void) {
    *(s32 *)(D_004C2840 + 0x98) = D_004C28BC + 0x3F0000;
    if (*(s8 *)(D_004C2840 + 0x88) == 1) *(s32 *)(D_004C2840 + 0x98) = D_004C28BC;
    func_0012DA40(0x3E, D_004C28B8, 2);
    func_00176230((s16 *)D_004C28B8, *(s16 **)(D_004C2840 + 0x98));
    func_0012DA40(0x34B, D_004C28AC, 2);
    func_0012DA40(0x34C, D_004C28B8, 2);
}

extern u32 D_0043E860[];
extern u8 D_0043E8E0[];
extern u8 D_0043E410[];
void func_00134710(u8 *p, u8 *q) {
    P(u32,0xD8) = D_0043E860[P(u8,0x14C) & 0xF];
    if (D_0043E8E0[P(u8,0x14C) & 0xF]) {
        if (*(s8 *)(D_004C2840 + 0x8F) == 0 && *(s8 *)(q + 0x539) == 0) P(u32,0xDC) = (u32)D_0043E410;
        else P(u32,0xDC) = 0;
    }
}


