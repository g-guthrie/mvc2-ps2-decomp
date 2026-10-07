/* Dispatch the global signed phase, flush object categories, and queue the frame hook. */
#include "mvc2_phase_callbacks.h"
typedef Mvc2PhaseCallback PhaseCallback;
extern signed char *D_004C2840;
extern void func_003DA6F0(int),func_003D7310(PhaseCallback),func_00152570(void);
extern PhaseCallback D_0045E260[];
void func_0032A1B0(void) {
 D_0045E260[D_004C2840[4]]();
 func_003DA6F0(6);func_003DA6F0(8);func_003DA6F0(1);
 func_003D7310(func_00152570);
}
extern PhaseCallback D_0045E270[];
void func_0032A510(void) {
 D_0045E270[D_004C2840[4]]();
 func_003DA6F0(6);func_003DA6F0(8);func_003DA6F0(1);
 func_003D7310(func_00152570);
}
extern PhaseCallback D_0045E2C0[];
void func_0032BF70(void) {
 D_0045E2C0[D_004C2840[4]]();
 func_003DA6F0(6);func_003DA6F0(8);func_003DA6F0(1);
 func_003D7310(func_00152570);
}
