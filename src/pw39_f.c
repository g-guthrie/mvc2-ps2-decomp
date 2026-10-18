typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long u64;

/* EE GCC 2.96; REQUIRES the SN assembler run with -mips4 (no hazard nops):
   SNASFLAGS=-mips4 equivalent of ./tryee.sh src/pw39_f.c sn */
extern u8 D_004BC2A8[];
extern void func_003FB128(u8 *);
void func_00402178(u8 *p, s32 w, s32 n, f32 f) {
    s32 v;
    s32 lim;
    if (p == 0) {
        func_003FB128(D_004BC2A8);
        return;
    }
    v = (s32)(f * (f32)n);
    v = (v / 32) * w;
    v = (v * 18) / 2048;
    lim = *(s16 *)(p + 0x3C);
    if (v < lim) lim = v;
    *(s16 *)(p + 0x3E) = lim;
}
