typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00408628();
extern volatile s32 D_00487338;
void func_00408730(s32 x) { func_00408628(x); D_00487338 = x; }

typedef struct { u8 pad0[0x14]; u8 *base; s32 n; s32 pad1[2]; s32 idx; } Ring;
u8 *func_001068B8(Ring *p) {
    u8 *b;
    s32 r = p->idx % p->n;
    b = p->base + r * 64;
    p->idx = r + 1;
    return b;
}

/* fdlibm-style union word access: the retail code keeps the double in a union copy. */
typedef union { double value; struct { u32 lsw; u32 msw; } parts; } ieee_double_shape_type;
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
#define SET_HIGH_WORD(d,v) do { ieee_double_shape_type sh_u; sh_u.value = (d); sh_u.parts.msw = (v); (d) = sh_u.value; } while (0)
#define EXTRACT_WORDS(ix0,ix1,d) do { ieee_double_shape_type ew_u; ew_u.value = (d); (ix0) = ew_u.parts.msw; (ix1) = ew_u.parts.lsw; } while (0)

s32 func_00116970(double x) {
    s32 hx, lx;
    EXTRACT_WORDS(hx, lx, x);
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (s32)((u32)hx >> 31);
}

double func_00116568(double x, double y) {
    u32 hx, hy;
    GET_HIGH_WORD(hx, x);
    GET_HIGH_WORD(hy, y);
    SET_HIGH_WORD(x, (hx & 0x7fffffff) | (hy & 0x80000000));
    return x;
}
