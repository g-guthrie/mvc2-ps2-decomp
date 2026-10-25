#pragma padloop on
typedef unsigned char u8;typedef short s16;
typedef struct Actor {u8 pad[6];u8 phase;u8 pad7[0x15];s16 timer;u8 pad1E[0x16];float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;u8 pad70[0x16C];struct Actor *owner;} Actor;
extern void func_00178F20(u8*,u8*);
void func_00253A20(u8*raw) {
 Actor *p=(Actor*)raw;float difference,actorX,ownerX,velocity;
 p->phase++;
 difference=p->owner->x-p->x;actorX=p->x;ownerX=p->owner->x;
 func_00178F20(raw,(u8*)p->owner);
 velocity=(p->owner->x-p->x-difference)/16.0f;
 /* Restore starting positions before applying opposite velocities. */
 p->x=actorX;p->owner->x=ownerX;
 p->vx=0.0f;p->vy=0.0f;p->ax=0.0f;p->ay=0.0f;
 p->owner->vx=0.0f;p->owner->vy=0.0f;p->owner->ax=0.0f;p->owner->ay=0.0f;
 p->owner->vx=velocity;p->vx=-velocity;p->timer=16;
}
