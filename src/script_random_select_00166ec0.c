/* Script op: pick one of four inline choice bytes at random into the actor's
 * chosen slot (0x492), mark it active and clear the 0x451..0x453 counters. */
typedef unsigned char u8; typedef unsigned short u16;
#include "script_actor_view.h"
extern void func_0016B0C0(SA37_J0 *, SA37_R *, int);
extern int func_00174170(void);
int func_00166EC0(u8 *p, u8 *q) {
 u8 *choices; SA37_R *script = (SA37_R *)q;
 func_0016B0C0((SA37_J0 *)p, script, 0);
 choices = script->buf; choices += script->pos; script->pos += 4;
 p[0x492] = choices[func_00174170() & 3]; p[0x494] = 1; p[0x451] = 0; p[0x452] = 0; p[0x453] = 0;
 return 1;
}
