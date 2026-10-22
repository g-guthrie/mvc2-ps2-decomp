typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* Sixteen code addresses (no fixed-width data inside). Entries name code
 * symbols by address: func_ where symbol_addrs has a function start, lbl_ otherwise. */
extern char lbl_001A9DE0[];
extern char lbl_001A9E60[];
extern char lbl_001A9EF0[];
extern char lbl_001AB5A0[];
extern char lbl_001ABCC0[];
extern char lbl_001ABE90[];
extern void func_001A9FE0(void);
extern void func_001AA060(void);
extern void func_001AA0D0(void);
extern void func_001AB0B0(void);
extern void func_001AB110(void);
extern void func_001AB4A0(void);
extern void func_001AB500(void);
extern void func_001AB600(void);
extern void func_001ABDF0(void);
extern void func_001ABF50(void);

void *const jtbl_004BF7E0[16] = {
    (void *)lbl_001A9DE0,
    (void *)lbl_001A9E60,
    (void *)lbl_001A9EF0,
    (void *)func_001A9FE0,
    (void *)func_001AA060,
    (void *)func_001AA0D0,
    (void *)func_001AB0B0,
    (void *)func_001AB110,
    (void *)func_001AB4A0,
    (void *)func_001AB500,
    (void *)lbl_001AB5A0,
    (void *)func_001AB600,
    (void *)lbl_001ABCC0,
    (void *)func_001ABDF0,
    (void *)lbl_001ABE90,
    (void *)func_001ABF50
};
