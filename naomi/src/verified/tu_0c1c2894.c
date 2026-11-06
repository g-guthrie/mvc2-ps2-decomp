/* Paired UI construction, owner dispatch, and event countdown handling. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern unsigned char dat_0c2d7088[];
extern struct Vec3_tu5_03 dat_0c25c910[][2],dat_0c25c940;
extern struct Actor *dat_0c2f8350[][3];
extern void (*table_0c25ce8c[])(struct Obj_tu5_03 *,struct Actor *),(*table_0c25ce9c[])(struct Obj_tu5_03 *,struct Actor *);
void func_0c1c28b0(int),func_0c1c292e(struct Obj_tu5_03 *);
void func_0c1c2894(void){if(dat_0c2d6f84->i20!=64){func_0c1c28b0(0);func_0c1c28b0(1);}}
void func_0c1c28b0(int index){
 struct Obj_tu5_03 *a;struct Actor *owner;int *slots,i;
 if((a=func_0c0374da(0,12,1))){
 a->b12c=1;a->p16=func_0c1c292e;a->l84=0;a->lcc=0;((struct Actor *)a)->b2=index;
 a->pos=dat_0c25c910[index][0];*(struct Vec3_tu5_03 *)&a->f80=dat_0c25c940;
 owner=(struct Actor *)(dat_0c2d7088+index*0x5a4);a->p24=(struct Obj_tu5_03 *)owner;((struct Actor *)a)->b1=owner->b1;
 slots=(int *)((char *)a+0x19c);i=0;do{*slots++=0;i++;}while(i<4);
 }
}
void func_0c1c292e(struct Obj_tu5_03 *a){
 *(struct Actor **)((char *)a+0x138)=dat_0c2f8350[((struct Actor *)a)->b2][0];
 table_0c25ce8c[a->b4](a,*(struct Actor **)((char *)a+0x138));
}
void func_0c1c295a(struct Obj_tu5_03 *a,struct Actor *owner){
 a->b4++;*(short *)((char *)a+0x12e)=0;*(short *)((char *)a+0x134)=0;a->w130=0;
 ((struct Actor *)a)->b13f=0;((struct Actor *)a)->b13e=0;a->b32=0;
 if(owner->b525)((struct Actor *)a)->b13e=255;
}
void func_0c1c2990(struct Obj_tu5_03 *a,struct Actor *owner){
 *(short *)((char *)a+0x134)=*(short *)((char *)a+0x12e);
 if(((struct Actor *)a)->b13f<(signed char)owner->pad7fc[0]){((struct Actor *)a)->b13f=owner->pad7fc[0];owner->pad7fc[0]=0;}
 if(((struct Actor *)a)->b13f)((struct Actor *)a)->b13f--;
 table_0c25ce9c[a->b32](a,owner);
}
