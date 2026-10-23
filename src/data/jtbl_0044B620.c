#include "owner_effect_callbacks.h"

extern void func_001A8D70(u8 *);
extern void func_001A8E20(u8 *);
extern void func_001A9620(u8 *);
extern void func_001A9640(u8 *);
extern void func_001A8E50(u8 *, u8 *);
extern void func_001A9170(u8 *, u8 *);
extern void func_001A8E70(u8 *, u8 *);
extern void func_001A9070(u8 *, u8 *);
extern void func_001A9160(u8 *, u8 *);

const OwnerLaunchDispatchTables jtbl_0044B620 = {
    {
        func_001A8D70,
        func_001A8E20,
        func_001A9620,
        func_001A9640,
    },
    {
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A8E50,
        func_001A9170,
    },
    {
        func_001A8E70,
        func_001A9070,
        func_001A9160,
    },
};
