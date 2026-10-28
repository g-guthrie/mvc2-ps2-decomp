/* sLa2_c: MW 3.0 (./try30.sh src/sLa2_c.c "-O3,p -sdatathreshold 0").
 * func_00422FB0: opt_lifetimes off + opt_propagation off; parameter copy, named constants
 * and entry pointer in declaration order give retail temp colouring. */
typedef unsigned int u32;
typedef signed int s32;
typedef struct { s32 w; s32 x; } NQ54E;
extern s32 D_00633E20;
extern s32 D_00633E28;
extern NQ54E D_00633E30[64];
#pragma push
#pragma opt_lifetimes off
#pragma opt_propagation off
s32 func_00422FB0(u32 a0) {
s32 v;
s32 kbig;
s32 k8;
u32 am;
s32 i;
NQ54E *e;
u32 mask;
u32 a;
a = a0;
i = D_00633E28;
k8 = 8;
kbig = 0x7F000000;
mask = 0x7F7F7F;
am = a & mask;
goto check;
loop:
    { u32 vm = v & mask;
    if (vm == am) {
        if (((s32)v >> 24) == k8) return 0;
        e->w = kbig;
    } }
    v = ++i % 64;
    if (v == D_00633E20) goto done;
    i = v;
check:
    e = &D_00633E30[i];
    if ((s32)(v = e->w) >= 0) goto loop;
done:
    if (D_00633E30[D_00633E20].w >= 0) return -1;
    D_00633E30[D_00633E20].w = (a & 0xFFFFFF) | 0x08000000;
    { s32 n = ++D_00633E20; D_00633E20 = n % 64; }
    return 0;
}
#pragma pop
