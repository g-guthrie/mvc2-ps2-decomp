typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[16]; } M64;

void func_003DE160(M64 *out, M64 *a, M64 *b) {
    M64 ta;
    M64 tb;
    M64 r;
    s32 cnt;
    M64 *pa;
    M64 *pb;
    M64 *pr;
    cnt = 4;
    ta = *a;
    tb = *b;
    pa = &ta;
    pb = &tb;
    pr = &r;
    asm {
        .set noreorder
        lqc2 vf4, 0x0(pb)
        lqc2 vf5, 0x10(pb)
        lqc2 vf6, 0x20(pb)
        lqc2 vf7, 0x30(pb)
    }
    asm {
    loop:
        lqc2 vf8, 0x0(pa)
        addi cnt, cnt, -1
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf9, vf7, vf8w
        sqc2 vf9, 0x0(pr)
        addi pa, pa, 16
        bne zero, cnt, loop
        addi pr, pr, 16
        .set reorder
    }
    *out = r;
}
