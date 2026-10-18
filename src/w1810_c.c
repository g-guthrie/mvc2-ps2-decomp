typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0xE]; s16 h; } G;
extern G *D_004C2840;
extern u8 D_004F7D10[], D_004F7D20[];
void func_00148ED0(s32 a) {
    extern s32 func_00149380(void *);
    extern void func_00148FD0(void);
    extern void func_003D47E0(void);
    extern void func_00148F80(void);
    extern void func_0012AC70(s32, void *);
    extern void func_0012AC90(s32, s32);
    s32 r;
    s16 v;
    r = 0;
    r |= func_00149380(D_004F7D10);
    r |= func_00149380(D_004F7D20);
    func_00148FD0();
    v = D_004C2840->h + 1;
    D_004C2840->h = v;
    if (v < 8) return;
    D_004C2840->h = 8;
    if (r != 0) {
        func_003D47E0();
        func_0012AC70(1, func_00148F80);
        func_0012AC90(1, a);
    }
}
