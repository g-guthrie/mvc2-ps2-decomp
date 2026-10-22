typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/sa9_b.c sn */

typedef struct { u32 key; u32 f4[3]; } TB;
extern TB D_0062FB48[32];
extern u8 D_004BD170[];
extern void func_00405DC8(u8 *);

u32 *func_00407530(u32 *p)
{
    s32 i, j;
    if (p == 0) {
        func_00405DC8(D_004BD170);
        return 0;
    }
    for (i = 0; i < 32; i++) {
        if (D_0062FB48[i].key == *p) break;
    }
    j = i;
    return D_0062FB48[j].f4;
}
