/* Three dispatch functions and the pool match exactly. The 16-entry palette
 * copy still differs in pointer/counter allocation and instruction scheduling. */
#include "objects.h"
extern void func_0c045248(struct Actor *,int);
struct PaletteCopyRecord { int pad0,pad4,enabled,pad12; unsigned short colors[16]; };
extern struct PaletteCopyRecord dat_0c2d4724[];
extern unsigned short table_0c2497bc[][16];
void func_0c0e8350(struct Actor *a)
{
 a->b6=a->b7=a->b5=0;
 switch(a->b4c9){case 0:a->b1e9=7;break;case 1:a->b1e9=7;break;case 2:a->b1e9=11;break;}
 func_0c045248(a,29);
}
void func_0c0e8380(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=2;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}

void func_0c0e83be(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=2;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}

void func_0c0e83fc(struct Actor *a)
{
 struct PaletteCopyRecord *p;
 register unsigned short *src;unsigned short *dst;
 int count;
 p=dat_0c2d4724+*(short *)((char *)a+0x12e);
 p+=2;
 dst=p->colors;
 p->enabled=1;src=table_0c2497bc[a->b37];
 count=16;
 do{*dst++=*src++;}while(--count);
}
