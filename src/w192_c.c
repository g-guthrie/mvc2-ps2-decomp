typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { s32 a; void *fn; void *d; s32 sz; void *gp; s32 x; s32 pad[6]; } T;
extern s32 D_004C239C;
extern volatile s32 D_004C2320;
extern s32 D_0047D0E4[];
extern char D_0047D100[];
extern char _gp;
extern void func_003FDE40(void);
extern s32 func_00103BE0(T *);
extern void func_00103C00(s32, s32);
extern void func_003FE1F8(s32);
extern void func_00103C70(s32, s32);
void func_003FE258(void) {
    T t;
    t.fn = func_003FDE40;
    t.d = D_0047D100;
    t.sz = 0x1000;
    t.x = D_004C239C;
    t.gp = &_gp;
    D_004C2320 = func_00103BE0(&t);
    (void)D_004C2320;
    func_00103C00(D_004C2320, 0);
    { register s32 j __asm__("$3"); j = D_004C2320; if (j != 0) {
        func_003FE1F8(D_004C2320);
        { register s32 k __asm__("$3"); k = D_004C2320; }
    } }
    func_00103C70(D_004C2320, D_0047D0E4[0]);
}
