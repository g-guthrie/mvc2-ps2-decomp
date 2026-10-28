typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC 2.96, $gp globals: ./tryee8.sh src/r5_c.c sn */

typedef struct { s8 a; char pad[0x1BF]; } E4680;
extern s32 D_004C2418;
extern E4680 D_00485880[];
extern void func_00404968(void *);
extern void func_0011D8F8(void *, s32, s32);
void func_00404680(void) {
    s32 i;
    if (--D_004C2418 == 0) {
        for (i = 0; i < 4; i++) { if (D_00485880[i].a == 1) func_00404968(&D_00485880[i]); }
        func_0011D8F8(D_00485880, 0, 0x700);
    }
}
