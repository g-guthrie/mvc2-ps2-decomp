#pragma padloop on
typedef unsigned char u8;
typedef struct {float x,y,z;} V3;
typedef struct Actor Actor;
struct Actor {
 u8 prefix[0x14];Actor *parent;u8 pad18[0x1C];V3 position;
 int pad40;int rotation;u8 pad48[0x14];V3 saved;
 u8 pad68[0x20];float matrix[16];void *anchor;
 u8 padCC[12];int mode,enabled;
};
extern int func_00416AE0(float*),func_00416CC0(int);
extern void func_00416F80(float*);
void func_00331EB0(Actor *p)
{
 if((p->enabled=p->parent->enabled)){
  switch(p->enabled=p->parent->mode){case 0:break;case 1:p->position.y-=1.0f;break;case 2:p->position.y+=1.0f;break;}
  if(!p->anchor){p->anchor=p->parent->matrix;p->position=p->saved;p->rotation=0;}
  return;
 }
 if(p->anchor){
  p->anchor=0;p->saved=p->position;func_00416AE0(0);func_00416F80(p->matrix);func_00416CC0(1);
  p->rotation=p->parent->parent->parent->rotation;
 }
}
