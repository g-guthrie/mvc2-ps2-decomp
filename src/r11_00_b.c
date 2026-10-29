typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 sts, std, mfd, rcyc;
    u16 express, notify, sqwc, tqwc;
    void *rbadr;
    u32 rbmsk;
} DmaEnv;

extern u8 D_004AAF00[];
extern u8 D_004AAF10[];
extern u8 D_004AAF20[];
extern DmaEnv D_004C2D48;

#define D_CTRL ((volatile u32 *)0x1000E000)
#define D_PCR ((volatile u32 *)0x1000E020)
#define D_SQWC ((volatile u32 *)0x1000E030)
#define D_RBSR ((volatile u32 *)0x1000E040)
#define D_RBOR ((volatile u32 *)0x1000E050)

s32 func_00102688(DmaEnv *env) {
    u32 ctrl, pcr, sqwc, rbor, rbsr;
    ctrl = *D_CTRL;
    pcr = *D_PCR;
    sqwc = *D_SQWC;
    rbor = *D_RBOR;
    rbsr = *D_RBSR;
    if (env->sts >= 10) return -1;
    if (env->std >= 10) return -2;
    if (env->mfd >= 10) return -3;
    if (env->rcyc >= 7) return -4;
    ctrl = (ctrl & ~0x30) | (D_004AAF00[env->sts] << 4);
    ctrl = (ctrl & ~0xC0) | (D_004AAF10[env->std] << 6);
    ctrl = (ctrl & ~0xC) | (D_004AAF20[env->mfd] << 2);
    if (env->rcyc != 0) {
        ctrl |= 2;
        ctrl = (ctrl & ~0x300) | ((env->rcyc - 1) << 8);
    } else {
        ctrl &= ~2;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbsr = env->rbmsk;
    *D_CTRL = ctrl;
    *D_PCR = pcr;
    *D_SQWC = sqwc;
    rbor = (u32)env->rbadr;
    *D_RBOR = rbor;
    *D_RBSR = rbsr;
    D_004C2D48 = *env;
    return 0;
}
