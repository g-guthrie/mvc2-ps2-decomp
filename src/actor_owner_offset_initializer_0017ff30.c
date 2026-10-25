#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
typedef struct Actor {u8 pad[6];u8 phase;u8 pad7[0x15];s16 timer;u8 pad1E[0x16];V3 position;u8 pad40[8];u32 angleZ;u8 pad4C[4];V3 scale;float vx,vy,vz,ax,ay;u8 pad70[0xA8];float unit;u8 pad11C[0x20];u8 visible;u8 pad13D[0x9F];struct Actor *owner;u8 pad1E0[6];u8 facing;u8 pad1E7[0x67];s8 counter;u8 pad24F[0x49];V3 savedScale;} Actor;
extern void func_00191430(u8*),func_00180060(u8*);
extern int func_001757E0(u8*,int,int);
void func_0017FF30(u8*raw) {
 Actor *p=(Actor*)raw;
 p->phase++;p->counter++;
 func_00191430((u8*)p);
 p->visible=1;p->angleZ=0;p->scale=p->savedScale;p->unit=1.0f;
 func_001757E0((u8*)p,13,29);
 p->vy=-8.571428298950195f;p->ay=-0.8035714030265808f;p->vx=0.0f;p->ax=0.0f;p->timer=20;
 p->position=p->owner->position;p->position.y+=822.8571166992188f;
 if(p->owner->facing)p->position.x+=213.3333282470703f;
 else p->position.x-=213.3333282470703f;
 func_00180060((u8*)p);
}
