typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { s32 a; void *fn; void *d; s32 sz; void *gp; s32 x; s32 pad[6]; } T;
extern s32 D_004C239C;
extern volatile s32 D_004C2324;
extern char D_0047E100[];
extern s32 D_0047D0E8[];
extern char _gp;
extern void func_003FDE88(void);
extern s32 func_00103BE0(T *);
extern void func_00103C00(s32, s32);
extern void func_00103C70(s32, s32);
void func_003FE2F0(void) {
    T t;
    t.sz = 0x1000;
    t.fn = func_003FDE88;
    t.d = D_0047E100;
    t.x = D_004C239C;
    t.gp = &_gp;
    D_004C2324 = func_00103BE0(&t);
    (void)D_004C2324;
    func_00103C00(D_004C2324, 0);
    func_00103C70(D_004C2324, D_0047D0E8[0]);
}
