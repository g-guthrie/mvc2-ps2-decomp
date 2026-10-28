/* EE GCC 2.96 (-O2 -G0, SN as).  In the VU0 helper the compiler supplies the
 * operand registers and return; only the COP2 instructions are inline asm
 * with C operands.  The nops in func_003FF1C0's endless loop are the
 * compiler's own R5900 short-loop padding. */

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

/* v0 = m0 * v1, with x and y converted to 12.4 fixed point */
void func_004135D0(sceVu0IVECTOR v0, sceVu0FVECTOR v1, sceVu0FMATRIX m0)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "lqc2 $vf6,0x10(%2)\n\t"
        "lqc2 $vf7,0x20(%2)\n\t"
        "lqc2 $vf8,0x30(%2)\n\t"
        "vmulax.xyzw ACC,$vf5,$vf4x\n\t"
        "vmadday.xyzw ACC,$vf6,$vf4y\n\t"
        "vmaddaz.xyzw ACC,$vf7,$vf4z\n\t"
        "vmaddw.xyzw $vf4,$vf8,$vf4w\n\t"
        "vftoi4.xy $vf4,$vf4\n\t"
        "sqc2 $vf4,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(m0) : "memory");
}

extern char D_004BBE88[];
extern void func_0011EB60(char *);

/* Report a fatal error, then hang. */
void func_003FF1C0(void)
{
    func_0011EB60(D_004BBE88);
    for (;;)
        ;
}
