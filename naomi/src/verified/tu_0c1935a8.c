/* 0x0c1935a8..0x0c193660: animation-bank handler and cleanup leaves. */
#include "objects.h"
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c193644(struct LinkedActor *,struct LinkedActor *);
void func_0c1935a8(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;
 if(!a->b34){if(func_0c02a026(a)<0)goto cleanup;goto draw;}
 func_0c02a026(a);
 if(--a->s30>0)goto draw;
 goto variant;variant:if((unsigned char)a->b33<=1){a->b4++;func_0c02a0c4(a,23,a->b33+11);return;}
 cleanup:func_0c193644(a,owner);return;
 draw:goto redraw;redraw:func_0c037d0c(a);
}
void func_0c193622(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){a->b4++;a->sdc.b12c=0;}
}
void func_0c193644(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
