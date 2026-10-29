typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

/* Memory-card state reset: wait for the card service, then clear the state
   blocks. The single nop after the wait loop is the original timing delay,
   written with MW's own __I_nop() intrinsic (unlike an __asm__ string, it is an
   ordinary scheduled instruction, so the argument setup after it keeps
   retail's order). */

typedef struct { u8 b[0x84]; } MC;
typedef struct { u8 b[0xC]; } MP;
extern MC D_00633690;
extern MP D_00633670[2];
extern u16 D_006336FE[];
extern u16 D_00633706[];

s32 func_00418CC0(void) {
    extern s32 func_0010FD90(void);
    extern void func_003DCD40(void *, s32, u32);
    s32 i;
    s32 r;
    do {
        r = func_0010FD90();
    } while (r == -0x65);
    __I_nop();
    func_003DCD40(&D_00633690, 0, sizeof(MC));
    for (i = 0; i < 2; i++) {
        func_003DCD40(&D_00633670[i], 0, sizeof(MP));
    }
    D_006336FE[0] = 0xFFFF;
    D_00633706[0] = 0xFFFF;
    return 1;
}
