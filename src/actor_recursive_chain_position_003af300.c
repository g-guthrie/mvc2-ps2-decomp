#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct Frame {s16 x,y,reference_x,reference_y,flip;u8 padA[0x12];float base_x,base_y;u8 pad24[5];s8 count;} Frame;
typedef struct Actor {u8 prefix[0x34];float x,y;u8 pad3C[0x178];s8 busy;} Actor;
typedef struct Node Node;
struct Node {u8 prefix[8];Node *previous,*next;u8 pad10[4];Node *chain;Actor *actor;s16 timer;u8 pad1E[0x16];float x,y,z;u8 pad40[0x48];Frame frame;u8 padB4[0x88];u8 visible;};
extern void func_003AF890(u8*,u8*,u8*);
void func_003AF300(Node *p,Frame *reference)
{
 Node *chain,*previous,*before,*next;
 Actor *actor;Frame *root,*end;
 previous=p->previous;chain=p->chain;before=previous->previous;actor=p->actor;root=&chain->frame;
 p->x=before->x+(float)before->frame.x-(float)reference->reference_x;
 p->y=(float)reference->reference_y+(before->y-(float)before->frame.y);
 p->visible=1;p->timer=1;
 next=p->next;
 next->x=previous->x+(float)previous->frame.x-(float)next->frame.reference_x;
 next->y=(float)next->frame.reference_y+(previous->y-(float)previous->frame.y);
 next->visible=1;next->timer=1;
 end=&next->frame;
 if((chain->frame.count-=2)>0){Node *rest=next->next;func_003AF300(rest,&rest->frame);return;}
 if(!actor->busy){
  actor->x=next->x-root->base_x;actor->y=next->y-root->base_y;
  if((root->flip=-root->flip)>=0){actor->x+=(float)end->x;actor->y-=(float)end->y;func_003AF890((u8*)chain,(u8*)next,(u8*)actor);}
 }
}
