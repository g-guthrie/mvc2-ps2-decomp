#include "inherited_effect_phase_tables.h"
extern void func_00361310(u8 *, u8 *);
extern void func_00361340(u8 *, u8 *);
extern void func_00361380(u8 *, u8 *);
extern void func_00361420(u8 *, u8 *);
extern void func_00361830(u8 *, u8 *);
extern void func_00361870(u8 *, u8 *);
extern void func_003611D0(u8 *, u8 *);
const InheritedEffectPhaseTables jtbl_004634F0 = {
    {func_003611D0, func_00361310, func_00361830, func_00361870},
    {func_00361340, func_00361380, func_00361420},
};
