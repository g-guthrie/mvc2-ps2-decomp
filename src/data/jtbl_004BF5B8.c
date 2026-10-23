#include "owner_effect_callbacks.h"

extern void func_00198030(u8 *, u8 *);
extern void func_00198090(u8 *, u8 *);
extern void func_00198E30(u8 *);
extern void func_00198F80(u8 *);
extern void func_00199330(u8 *);
extern void func_00199390(u8 *);

const SideOwnerDispatchTables jtbl_004BF5B8 = {
    { func_00198030, func_00198090 },
    { func_00198E30, func_00198F80, func_00199330, func_00199390 }
};
