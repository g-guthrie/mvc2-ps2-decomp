/* Sony libvu0 scalar-operand helpers (EE GCC 2.9-991111, -O2 -G0, SN as -mips4).
 *
 * Written in the shape of Sony's libvu0.c: the float argument enters the asm
 * as an "f" operand and is moved to the $8 ($9) scratch register inside the
 * asm, which lists it as clobbered.  The compiler supplies the operand
 * registers and the return. */

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));

/* sceVu0DivVector: v0 = v1 / q */
void func_00102E28(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float q)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "mfc1 $8,%2\n\t"
        "qmtc2 $8,$vf5\n\t"
        "vdiv Q,$vf0w,$vf5x\n\t"
        "vwaitq\n\t"
        "vmulq.xyzw $vf4,$vf4,Q\n\t"
        "sqc2 $vf4,0x0(%0)"
        : : "r"(v0), "r"(v1), "f"(q) : "$8", "memory");
}

/* sceVu0DivVectorXYZ: v0.xyz = v1.xyz / q */
void func_00102E48(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float q)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "mfc1 $8,%2\n\t"
        "qmtc2 $8,$vf5\n\t"
        "vdiv Q,$vf0w,$vf5x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf4,$vf4,Q\n\t"
        "sqc2 $vf4,0x0(%0)"
        : : "r"(v0), "r"(v1), "f"(q) : "$8", "memory");
}

/* sceVu0InterVector: v0 = v1 * t + v2 * (1 - t) */
void func_00102E68(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float t)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "mfc1 $8,%3\n\t"
        "qmtc2 $8,$vf6\n\t"
        "vaddw.x $vf7,$vf0,$vf0w\n\t"
        "vsub.x $vf8,$vf7,$vf6\n\t"
        "vmulax.xyzw ACC,$vf4,$vf6x\n\t"
        "vmaddx.xyzw $vf9,$vf5,$vf8x\n\t"
        "sqc2 $vf9,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(v2), "f"(t) : "$8", "memory");
}

/* sceVu0ScaleVector: v0 = v1 * t */
void func_00102ED8(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float t)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "mfc1 $8,%2\n\t"
        "qmtc2 $8,$vf5\n\t"
        "vmulx.xyzw $vf6,$vf4,$vf5x\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1), "f"(t) : "$8", "memory");
}

/* sceVu0ClampVector: v0 = clamp(v1, min, max) */
void func_00103280(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float min, float max)
{
    __asm__ __volatile__(
        "mfc1 $8,%2\n\t"
        "mfc1 $9,%3\n\t"
        "lqc2 $vf6,0x0(%1)\n\t"
        "qmtc2 $8,$vf4\n\t"
        "qmtc2 $9,$vf5\n\t"
        "vmaxx.xyzw $vf6,$vf6,$vf4x\n\t"
        "vminix.xyzw $vf6,$vf6,$vf5x\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1), "f"(min), "f"(max) : "$8", "$9", "memory");
}

/* sceVu0InterVectorXYZ: v0.xyz = v1 * t + v2 * (1 - t), v0.w = v1.w */
void func_001037D8(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float t)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "mfc1 $8,%3\n\t"
        "qmtc2 $8,$vf6\n\t"
        "vmove.w $vf9,$vf4\n\t"
        "vaddw.x $vf7,$vf0,$vf0w\n\t"
        "vsub.x $vf8,$vf7,$vf6\n\t"
        "vmulax.xyz ACC,$vf4,$vf6x\n\t"
        "vmaddx.xyz $vf9,$vf5,$vf8x\n\t"
        "sqc2 $vf9,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(v2), "f"(t) : "$8", "memory");
}

/* sceVu0ScaleVectorXYZ: v0.xyz = v1.xyz * t */
void func_00103808(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float t)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "mfc1 $8,%2\n\t"
        "qmtc2 $8,$vf5\n\t"
        "vmulx.xyz $vf4,$vf4,$vf5x\n\t"
        "sqc2 $vf4,0x0(%0)"
        : : "r"(v0), "r"(v1), "f"(t) : "$8", "memory");
}

typedef unsigned int u32;
typedef int u128 __attribute__((mode(TI)));
extern u128 D_00438220[2];

/* sceVu0 reset: stop VIF0, set the VU0 reset bit in FBRST ($vi28) and
 * reload VIF0 with the two-quadword initialisation packet.  Only the
 * first FIFO write is volatile; the second is the last access before
 * return. */
void func_00103958(void)
{
    *(volatile u32 *)0x10003830 = 0;
    *(volatile u32 *)0x10003820 = 0;
    *(volatile u32 *)0x10003810 = 1;
    __asm__ __volatile__(
        "cfc2 $8,$vi28\n\t"
        "ori $8,$8,0x2\n\t"
        "ctc2 $8,$vi28\n\t"
        "sync.p"
        : : : "$8");
    *(volatile u128 *)0x10004000 = D_00438220[0];
    *(u128 *)0x10004000 = D_00438220[1];
}
