/* Sony libvu0 macro-mode vector helpers (EE GCC 2.9-991111, -O2 -G0).
 *
 * Each function is ordinary C: the compiler supplies the argument registers,
 * return path and float return move.  Only the COP2 instructions, which no
 * compiler here emits, are written as inline asm with C operands, in the
 * style of Sony's own libvu0 sources. */

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

/* sceVu0ApplyMatrix: v0 = m0 * v1 */
void func_00102C70(sceVu0FVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x10(%1)\n\t"
        "lqc2 $vf6,0x20(%1)\n\t"
        "lqc2 $vf7,0x30(%1)\n\t"
        "lqc2 $vf8,0x0(%2)\n\t"
        "vmulax.xyzw ACC,$vf4,$vf8x\n\t"
        "vmadday.xyzw ACC,$vf5,$vf8y\n\t"
        "vmaddaz.xyzw ACC,$vf6,$vf8z\n\t"
        "vmaddw.xyzw $vf9,$vf7,$vf8w\n\t"
        "sqc2 $vf9,0x0(%0)"
        : : "r"(v0), "r"(m0), "r"(v1) : "memory");
}

/* sceVu0OuterProduct: v0 = v1 x v2 */
void func_00102CE8(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "vopmula.xyz ACC,$vf4,$vf5\n\t"
        "vopmsub.xyz $vf6,$vf5,$vf4\n\t"
        "vsub.w $vf6,$vf6,$vf6\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(v2) : "memory");
}

/* sceVu0InnerProduct: returns v0 . v1 (xyz) */
float func_00102D08(sceVu0FVECTOR v0, sceVu0FVECTOR v1)
{
    float ret;
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "vmul.xyz $vf5,$vf4,$vf5\n\t"
        "vaddy.x $vf5,$vf5,$vf5y\n\t"
        "vaddz.x $vf5,$vf5,$vf5z\n\t"
        "qmfc2 %0,$vf5"
        : "=r"(ret) : "r"(v0), "r"(v1));
    return ret;
}

/* sceVu0Normalize: v0 = v1 / |v1| */
void func_00102D30(sceVu0FVECTOR v0, sceVu0FVECTOR v1)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "vmul.xyz $vf5,$vf4,$vf4\n\t"
        "vaddy.x $vf5,$vf5,$vf5y\n\t"
        "vaddz.x $vf5,$vf5,$vf5z\n\t"
        "vsqrt Q,$vf5x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf5,$vf0,Q\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vdiv Q,$vf0w,$vf5x\n\t"
        "vsub.xyzw $vf6,$vf0,$vf0\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf6,$vf4,Q\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1) : "memory");
}

/* sceVu0AddVector: v0 = v1 + v2 */
void func_00102E90(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "vadd.xyzw $vf6,$vf4,$vf5\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(v2) : "memory");
}

/* sceVu0SubVector: v0 = v1 - v2 */
void func_00102EA8(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "vsub.xyzw $vf6,$vf4,$vf5\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(v2) : "memory");
}

/* sceVu0MulVector: v0 = v1 * v2 (per component) */
void func_00102EC0(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "lqc2 $vf5,0x0(%2)\n\t"
        "vmul.xyzw $vf6,$vf4,$vf5\n\t"
        "sqc2 $vf6,0x0(%0)"
        : : "r"(v0), "r"(v1), "r"(v2) : "memory");
}

/* sceVu0FTOI4Vector */
void func_00102F58(sceVu0IVECTOR v0, sceVu0FVECTOR v1)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "vftoi4.xyzw $vf5,$vf4\n\t"
        "sqc2 $vf5,0x0(%0)"
        : : "r"(v0), "r"(v1) : "memory");
}

/* sceVu0FTOI0Vector */
void func_00102F68(sceVu0IVECTOR v0, sceVu0FVECTOR v1)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "vftoi0.xyzw $vf5,$vf4\n\t"
        "sqc2 $vf5,0x0(%0)"
        : : "r"(v0), "r"(v1) : "memory");
}

/* sceVu0ITOF4Vector */
void func_00102F78(sceVu0FVECTOR v0, sceVu0IVECTOR v1)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "vitof4.xyzw $vf5,$vf4\n\t"
        "sqc2 $vf5,0x0(%0)"
        : : "r"(v0), "r"(v1) : "memory");
}

/* sceVu0ITOF0Vector */
void func_00102F88(sceVu0FVECTOR v0, sceVu0IVECTOR v1)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%1)\n\t"
        "vitof0.xyzw $vf5,$vf4\n\t"
        "sqc2 $vf5,0x0(%0)"
        : : "r"(v0), "r"(v1) : "memory");
}

/* sceVu0UnitMatrix */
void func_00102F98(sceVu0FMATRIX m0)
{
    __asm__ __volatile__(
        "vsub.xyzw $vf4,$vf0,$vf0\n\t"
        "vadd.w $vf4,$vf4,$vf0\n\t"
        "vmr32.xyzw $vf5,$vf4\n\t"
        "vmr32.xyzw $vf6,$vf5\n\t"
        "vmr32.xyzw $vf7,$vf6\n\t"
        "sqc2 $vf4,0x30(%0)\n\t"
        "sqc2 $vf5,0x20(%0)\n\t"
        "sqc2 $vf6,0x10(%0)\n\t"
        "sqc2 $vf7,0x0(%0)"
        : : "r"(m0) : "memory");
}

/* sceVu0RotTransPers: perspective transform of v1 by m0 into fixed point */
void func_00103770(sceVu0IVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1, int mode)
{
    __asm__ __volatile__(
        "lqc2 $vf4,0x0(%0)\n\t"
        "lqc2 $vf5,0x10(%0)\n\t"
        "lqc2 $vf6,0x20(%0)\n\t"
        "lqc2 $vf7,0x30(%0)\n\t"
        "lqc2 $vf8,0x0(%1)\n\t"
        "vmulax.xyzw ACC,$vf4,$vf8x\n\t"
        "vmadday.xyzw ACC,$vf5,$vf8y\n\t"
        "vmaddaz.xyzw ACC,$vf6,$vf8z\n\t"
        "vmaddw.xyzw $vf9,$vf7,$vf8w\n\t"
        "vdiv Q,$vf0w,$vf9w\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf9,$vf9,Q\n\t"
        "vftoi4.xyzw $vf10,$vf9"
        : : "r"(m0), "r"(v1));
    if (mode)
        __asm__ __volatile__("vftoi0.zw $vf10,$vf9");
    __asm__ __volatile__("sqc2 $vf10,0x0(%0)" : : "r"(v0) : "memory");
}

/* sceVu0ClipScreen: returns the clip flags of v0 against the 4096 guard band */
int func_00103820(sceVu0FVECTOR v0)
{
    int ret;
    __asm__ __volatile__("vsub.xyzw $vf4,$vf0,$vf0");
    __asm__ __volatile__(
        "lqc2 $vf7,0x0(%1)\n\t"
        "qmtc2 %0,$vf6\n\t"
        "ctc2 $0,$vi16\n\t"
        "vsub.xyw $vf5,$vf7,$vf4\n\t"
        "vsub.xy $vf5,$vf6,$vf7\n\t"
        "vnop\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\t"
        "cfc2 %0,$vi16"
        : "=r"(ret) : "r"(v0), "0"(0x4580000045800000UL));
    return ret & 0xC0;
}

/* sceVu0ClipScreen3: as above for a triangle */
int func_00103868(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2)
{
    int ret;
    __asm__ __volatile__("vsub.xyzw $vf4,$vf0,$vf0");
    __asm__ __volatile__(
        "lqc2 $vf6,0x0(%1)\n\t"
        "lqc2 $vf8,0x0(%2)\n\t"
        "lqc2 $vf9,0x0(%3)\n\t"
        "qmtc2 %0,$vf7\n\t"
        "ctc2 $0,$vi16\n\t"
        "vsub.xyw $vf5,$vf6,$vf4\n\t"
        "vsub.xy $vf5,$vf7,$vf6\n\t"
        "vsub.xyw $vf5,$vf8,$vf4\n\t"
        "vsub.xy $vf5,$vf7,$vf8\n\t"
        "vsub.xyw $vf5,$vf9,$vf4\n\t"
        "vsub.xy $vf5,$vf7,$vf9\n\t"
        "vnop\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\t"
        "cfc2 %0,$vi16"
        : "=r"(ret) : "r"(v0), "r"(v1), "r"(v2), "0"(0x4580000045800000UL));
    return ret & 0xC0;
}
