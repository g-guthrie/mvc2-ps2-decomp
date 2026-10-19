typedef signed int s32;
typedef float f32;

typedef struct { s32 w[16]; } M64;

void func_003DE230(f32 *out, M64 *a, M64 *b)
{
    M64 ta;
    M64 tb;
    M64 r;
    s32 cnt;
    M64 *pa;
    M64 *pb;
    M64 *pr;
    cnt = 3;
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
    }
    asm {
    loop:
        lqc2 vf8, 0x0(pa)
        addi cnt, cnt, -1
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf9, vf6, vf8z
        sqc2 vf9, 0x0(pr)
        addi pa, pa, 16
        bne zero, cnt, loop
        addi pr, pr, 16
        .set reorder
    }
    out[0] = ((f32 *)&r)[0];
    out[1] = ((f32 *)&r)[1];
    out[2] = ((f32 *)&r)[2];
    out[4] = ((f32 *)&r)[4];
    out[5] = ((f32 *)&r)[5];
    out[6] = ((f32 *)&r)[6];
    out[8] = ((f32 *)&r)[8];
    out[9] = ((f32 *)&r)[9];
    out[10] = ((f32 *)&r)[10];
}
