typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef __int128 s128;

extern u16 D_004F4484[];
extern u16 D_004F4498[];



u8 *func_003DBA00(u8 *a0, u32 a1, s32 a2) {
    *(s128 *)a0 = 0;
    *(u32 *)a0 = a1 + 0x10000000;
    if (a2 == 1) *(u32 *)a0 |= 0x80000000;
    return a0 + 0x10;
}

/* Native callers also supply a fourth packet parameter. */
u8 *func_003DBAF0(u8 *a0, u32 a1, s32 a2, s32 a3) {
    *(s128 *)a0 = 0;
    *(u32 *)a0 = a1 + 0x70000000;
    if (a2 == 1) *(u32 *)a0 |= 0x80000000;
    return a0 + 0x10;
}
