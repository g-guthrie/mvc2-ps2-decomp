/* func_00418D70: MW 3.0 (./try30.sh) "-O3,p -sdatathreshold 0", jump table @N -> jtbl_004BEF40.
   Speed mode (,p) emits an 8-byte align pseudo-op at labels whose loop weight >= 8; with
   global_optimizer off that weight comes from source loop statements, so the goto-built outer
   loop gets none and only the inner while is padded: the pad blocks the bnez copy from the loop
   test, so the slot is filled from the fall-through, and the pad after the loop is retail nop. */
#pragma global_optimizer off
typedef signed int s32;
extern s32 D_00633690, D_00633694, D_00633698, D_0063369C, D_006336A0, D_006336A4;
extern s32 D_006336A8, D_006336AC, D_006336B0, D_006336B4, D_006336B8, D_006336BC;
extern s32 D_006336C0, D_006336C4;

#define NEG(call) \
    if (D_00633698 >= 0) break; \
        if (--D_00633690 != 0) { D_00633694 = 0; call; r = -1; } \
        else { D_00633694 = 0; r = 1; } \
    break;
#define NZ(call) \
    if (D_00633698 == 0) break; \
        if (--D_00633690 != 0) { D_00633694 = 0; call; r = -1; } \
        else { D_00633694 = 0; r = 1; } \
    break;

s32 func_00418D70(s32 a) {
    extern s32 func_001107B8(s32, s32 *, s32 *);
    extern void func_00419420(s32, s32, s32);
    extern void func_00419520(s32, s32, s32);
    extern void func_00419610(s32, s32, s32, s32, s32);
    extern void func_00419730(s32, s32);
    extern void func_00419840(s32, s32, s32, s32);
    extern void func_00419950(s32);
    extern void func_004199F0(s32, s32, s32);
    extern void func_00419AC0(s32, s32, s32);
    extern void func_00419B90(s32, s32, s32);
    extern void func_00419C60(s32);
    extern void func_00419D00(s32, s32, s32);
    extern void func_00419DF0(s32, s32, s32);
    s32 r;
    top: {
        if (D_00633694 == 0) return 0;
        if (a == 0) {
            if (func_001107B8(1, &D_00633694, &D_00633698) != 1) return -1;
        } else {
            while (func_001107B8(1, &D_00633694, &D_00633698) != 1) {
                __I_nop(); __I_nop(); __I_nop(); __I_nop(); __I_nop(); __I_nop();
            }
        }

        r = 0;
        switch (D_00633694) {
        case 1: D_00633694 = 0; break;
        case 12: NEG(func_00419420(D_0063369C, D_006336A0, D_006336A4))
        case 11: NEG(func_00419520(D_0063369C, D_006336A0, D_006336A4))
        case 13: NEG(func_00419610(D_0063369C, D_006336A0, D_006336A4, D_006336A8, D_006336AC))
        case 16: NZ(func_00419730(D_0063369C, D_006336A0))
        case 2: NEG(func_00419840(D_0063369C, D_006336A0, D_006336A4, D_006336B0))
        case 3: NZ(func_00419950(D_006336B4))
        case 4: NEG(func_004199F0(D_006336B4, D_006336B8, D_006336BC))
        case 5: NEG(func_00419AC0(D_006336B4, D_006336C0, D_006336C4))
        case 6: NEG(func_00419B90(D_006336B4, D_006336C0, D_006336C4))
        case 10: NZ(func_00419C60(D_006336B4))
        case 15: NZ(func_00419D00(D_0063369C, D_006336A0, D_006336A4))
        case 18: NEG(func_00419DF0(D_0063369C, D_006336A0, D_006336A4))
        case 0: case 7: case 8: case 9: case 14: case 17: case 19: case 20: case 21: break;
        }
        if (r != -1) {
            if (r == 1) goto end;
            if (r != 0) return r;
            D_00633694 = 0; D_00633690 = 0; return r;
        }
        if (a != 1) { end: return r; }
    }
    goto top;
}
