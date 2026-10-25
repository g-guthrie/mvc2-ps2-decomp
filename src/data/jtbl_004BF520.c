/* Two controller callbacks, two owner callbacks, and four bounded cooldowns. */
#include "character_owner_callbacks.h"
extern void func_001909E0(u8 *);
extern void func_00190A80(u8 *);
extern void func_001934E0(u8 *, u8 *);
extern void func_00193B80(u8 *, u8 *);
const CharacterControllerTables jtbl_004BF520 = {
    {func_001909E0, func_00190A80},
    {func_001934E0, func_00193B80},
    {16,16,12,10},
};
