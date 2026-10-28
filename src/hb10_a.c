typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#pragma padloop on

extern s8 D_004BFA44[8];

/* Real body of func_001C8D60 (matched in src/wave25b.c); the static copy lets
   the compiler see that it leaves the actor pointer live in $a0. */
typedef struct { u8 pad[0x34]; f32 f34; } LF;
static void func_001C8D60(u8 *a) {
    LF *sa;
    *(float *)(a + 0x34) = *(float *)(*(u8 **)(a + 0x18) + 0x34);
    *(float *)(a + 0x38) = *(float *)(*(u8 **)(a + 0x18) + 0x38);
    if (*(s16 *)(*(u8 **)(a + 0x18) + 0x140) != 0) {
        sa = (LF *)a;
        sa->f34 = sa->f34 + 1.6666666f * (float)D_004BFA44[a[0x20]];
    }
    ((s8 *)a)[0x24] = ((s8 *)*(u8 **)(a + 0x18))[0x24];
    ((s8 *)a)[0x31] = -1;
}

void func_001C8EF0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_001C8FA0(u8 *);
    if (*(*(u8 **)(p + 0x18) + 0x169) != 0x13 && p[0x20] == 1) {
        u32 t = p[4];
        p[4] = t + 1;
        func_001C8FA0(p);
    } else {
        func_001C8D60(p);
        if (p[0x20] != 1) {
            if ((s8)func_00175700(p) < 0) {
                u32 t = p[4];
                p[4] = t + 1;
                func_001C8FA0(p);
            }
        } else {
            func_00175700(p);
        }
    }
}
