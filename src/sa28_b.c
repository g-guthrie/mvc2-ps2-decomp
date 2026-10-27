typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 f0; s32 f4; s32 f8; s32 pad[5]; } T3;
extern volatile s32 D_004C28AC;
extern volatile s32 D_004C28B8;
extern volatile s32 D_004C2830;
extern s8 *D_004C2840;
extern T3 D_004468D0[2];
extern T3 D_004468F0[2];

void func_0016FC80(void) {
    extern void func_0016F5B0(s32, s32, s32, s32, s32, s32);
    extern void func_0012DA40(s32, s32, s32);
    extern void func_00176230(s16 *, s16 *);
    extern s32 func_00416180(s32, s32);
    extern void func_00415140(s32, T3 *);
    T3 *q;
    s32 t1, t2, t3;
    t2 = D_004C28AC;
    t3 = D_004C28B8;
    t1 = D_004C2830;
    func_0016F5B0(0x810, t1, t2, t3, 6, 0);
    if (D_004C2840[0x4C] == 1) {
        func_0012DA40(0x96, D_004C28B8 + 0xFF000, 2);
        t1 = D_004C28B8;
        func_00176230((s16 *)(t1 + 0xFF000), (s16 *)(t1 + 0x67000));
        q = &D_004468D0[1];
        q->f4 = 0x10000;
        q->f8 = func_00416180(D_004C28B8 + 0x67000, 0x12);
        func_00415140(0xB, q);
        q = &D_004468F0[-1];
        q->f4 = 0x10000;
        q->f8 = func_00416180(D_004C28B8 + 0x67000, 0);
        func_00415140(0x914, q);
    }
}
