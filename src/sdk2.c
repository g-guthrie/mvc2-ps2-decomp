typedef unsigned long long u64;
int func_00104598(int a, char *b) {
    *(u64 *)(b + 0x48) = 0;
    *(int *)(b + 4) = 0x2000;
    return 0;
}



#include "sony_console_ring.h"
typedef SonyConsoleRing Ring;
void func_00105048(Ring *r) {
    r->count++;
    r->tail++;
    if (r->tail == (char *)r + (r->size + 16)) r->tail = (char *)r + 16;
}
typedef struct Obj { char pad[0x14]; int len; char pad2[0x18]; int blocks; } Obj;

typedef struct Ent { int key; int a; int off; } Ent;


typedef unsigned int u32;
typedef union { float f; u32 u; } FU;

