struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_004C2838;
extern f32 D_004452E0[];
extern void func_003DAA40(struct Object *);
void func_0015D6A0(u8 *p) {
    s16 i;
    *(s16 *)(p + 0xCC) = *(s16 *)(p + 0x1E) + 0xBA;
    *(s32 *)(p + 0x84) = D_004C2838;
    i = *(s16 *)(p + 0x1C);
    if (i > 15) {
        func_003DAA40((struct Object *)p);
        return;
    }
    *(f32 *)(p + 0x74) = D_004452E0[i];
    *(s16 *)(p + 0x1C) += 1;
    if (*(s16 *)(p + 0x1C) < 8) *(s16 *)(p + 0x1E) += 1;
}
extern void (*D_004C21C0[2])();
extern s8 *D_004C2840;
extern void func_003DA6F0();
extern void func_001237A0();
extern void func_0016D190();
extern void func_001527C0();
extern void func_003D7310();
void func_003D1FB0(void) {
    D_004C21C0[D_004C2840[2]]();
    if (D_004C2840[2] != 0) {
        func_003DA6F0(6);
        func_001237A0();
        func_0016D190();
        func_003D7310(func_001527C0);
    }
}
