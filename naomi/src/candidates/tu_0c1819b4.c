/* Candidate 0x0c1819b4..0x0c181a74: dispatcher exact; constructor differs by seven register and prefetch bytes. All pools exact. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c255690[])(struct LinkedActor *,struct LinkedActor *);
void func_0c181a44(struct LinkedActor *);
struct LinkedActor *func_0c1819b4(struct Actor *source)
{
 short displacement;unsigned char index;float offset;
 struct LinkedActor *q;struct LinkedActor *(*allocate)(int,int,int);
 displacement=-224;if(source->w130)displacement=224;
 index=0;
 allocate=func_0c0374da;
 offset=displacement*1.66666663f;
 do{
 if((q=allocate(0,1,0))!=0){
 q->p16=func_0c181a44;q->p24=(struct LinkedActor *)source;q->b1=source->b1;q->w38=0x3601;
 q->b32=index;q->b33=*(unsigned char *)&source->w130^index;
 q->f52=source->f52+offset;q->wcc.dword_value=(int)q->f52;q->f56=source->f41c;
 }
 index++;
 }while(index<2);
 return q;
}
void func_0c181a44(struct LinkedActor *q){table_0c255690[q->b4](q,q->p24);}
