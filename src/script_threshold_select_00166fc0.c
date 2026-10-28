/* Script handler from the gMvc2Dispatch_00445A20 table; same s32 (actor, cursor)
   signature as its matched siblings func_00163F90 and func_00166630. Scans three
   (value, threshold) byte pairs and advances the cursor by 7. */
#pragma padloop on
typedef unsigned char u8; typedef unsigned short u16;
#include "script_actor_view.h"
extern void func_0016B0C0(SA37_J0 *,SA37_R *,int);
extern short D_004D1802;
int func_00166FC0(u8 *actor,u8 *cursor) {
 SA37_J0 *p=(SA37_J0 *)actor; SA37_R *script=(SA37_R *)cursor;
 u8 *choices; int i;
 func_0016B0C0(p,script,0);
 choices=script->buf;
 choices+=script->pos;script->pos+=7;
 for(i=0;i<3;i++,choices+=2) {if(choices[1]>D_004D1802)break;}
 p->chosen=choices[0];p->active=1;p->a=0;p->b=0;p->c=0;
 return 1;
}
