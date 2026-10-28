/* Script op: step up to three weighted entries, choosing the first whose
 * weight exceeds the actor limit, then skip the unread entries. */
typedef unsigned char u8; typedef unsigned short u16; typedef signed int s32; typedef float f32;
#include "script_actor_view.h"
extern void func_0016B0C0(SA37_J0 *, SA37_R *, int);
int func_00167060(u8 *actor,u8 *cursor) {
 SA37_R *q=(SA37_R *)cursor; SA37_J0 *p=(SA37_J0 *)actor; int i;
 func_0016B0C0(p,q,0);
 for (i=0;i<3;i++) {
  func_0016B0C0(p,q,1);
  p->scratch=p->w4c8.integer;
  func_0016B0C0(p,q,3);
  if (!(p->w4c8.real<=p->limit)) { i++; break; }
 }
 q->pos+=(3-i)*3+1;
 p->chosen=*(signed char *)&p->scratch;
 p->active=1;
 p->a=0; p->b=0; p->c=0;
 return 1;
}
