#include "character_owner_callbacks.h"
/* Native consumers address this readonly backing table through the GP window. */
extern const CharacterControllerTables jtbl_004BF520 __attribute__((section(".sdata")));
typedef signed char s8;


void func_001934B0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004BF520.owner[p[0x20]](p, q);
}
