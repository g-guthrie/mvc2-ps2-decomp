#include "data/mvc2_state_callbacks.h"

/* Child state table (jtbl_004C1C98, 17 entries) lives in small data. */
extern Mvc2StateCallback D_004C1C98[17];
extern void func_00372260(u8 *p);

void func_0036E220(u8 *p) {
    D_004C1C98[p[5]](p);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) { func_00372260(p); return; }
}
