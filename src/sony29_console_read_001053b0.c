/* Provisional: the shared DECI2 state and ring ownership require full linkage proof.
 * The count is updated by the registered DECI2 receive callback. */
#include "sony_console_ring.h"
typedef SonyConsoleRing RingCursor;
typedef struct { int f0,f4,f8,fC; char *f10,*f14; RingCursor *ring; } DebugState;
extern DebugState D_004C36D0;
extern void func_00105088(RingCursor *);
int func_001053B0(char *output,int length) {
 int i=0;
 char *slot;
 while (i<length) {
  while (*(volatile int *)&D_004C36D0.ring->count==0) { }
  slot=output+i;
  *slot=*D_004C36D0.ring->head;
  func_00105088(D_004C36D0.ring);
  if (*slot=='\n' || *slot=='\r') return i+1;
  i++;
 }
 return i;
}
