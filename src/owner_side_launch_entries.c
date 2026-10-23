/* Owner-relative side placement and directional launch variants. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,entryIndex,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef signed short s16;
extern int func_001754A0(u8 *,int,int);
extern f32 D_0044BAD0[];
typedef struct {s32 word[49];} State;
extern int func_00174170(void);
extern void func_00175580(u8 *,s32,s32,s32);
void func_001AD2C0(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 offset,ownerX;
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p->phase;
    p->phase = t + 1;
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    q = *(u8 **)(actor + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
    p->layer=0;
    ownerX=((Actor*)*(u8**)(actor+0x18))->position.x;
    if(p->facing)offset=53.333332061767578125f;else offset=-53.333332061767578125f;
    p->position.x=ownerX+offset;
    p->position.y=171.42855834960938f+((Actor*)*(u8**)(actor+0x18))->position.y;
    p->vx=0.0f;p->vy=0.0f;p->ax=0.0f;p->ay=0.0f;
    p->vx=p->facing?-5.0f:5.0f;
    p->vy=8.571428298950195f;
    p->ay=-0.803571403026580810546875f;
    func_001754A0(actor,27,0);
}

void func_001AD640(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 offset,ownerX;
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p->phase;
    p->phase = t + 1;
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    q = *(u8 **)(actor + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
    ownerX=((Actor*)*(u8**)(actor+0x18))->position.x;
    if(p->facing)offset=53.333332061767578125f;else offset=-53.333332061767578125f;
    p->position.x=ownerX+offset;
    p->position.y=145.7142791748047f+((Actor*)*(u8**)(actor+0x18))->position.y;
    p->vx=0.0f;p->vy=0.0f;p->ax=0.0f;p->ay=0.0f;
    p->vx=p->facing?3.3333332538604736f:-3.3333332538604736f;
    p->vy=-6.4285712242126465f;
    p->ay=-0.5357142686843872f;
    func_001754A0(actor,27,1);
}

void func_001AD9C0(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 offset,ownerX;
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p->phase;
    p->phase = t + 1;
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    q = *(u8 **)(actor + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
    p->layer=0;
    ownerX=((Actor*)*(u8**)(actor+0x18))->position.x;
    if(p->facing)offset=85.0f;else offset=-85.0f;
    p->position.x=ownerX+offset;
    p->position.y=165.0f+((Actor*)*(u8**)(actor+0x18))->position.y;
    func_001754A0(actor,27,2);
}


void func_001AE880(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 offset,ownerX;
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p->phase;
    p->phase = t + 1;
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    q = *(u8 **)(actor + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
    p->layer=7;actor[0x14C]=48;actor[0x14D]=48;
    ownerX=((Actor*)*(u8**)(actor+0x18))->position.x;
    if(p->facing)offset=103.33332824707031f;else offset=-103.33332824707031f;
    p->position.x=ownerX+offset;
    p->position.y=64.28571319580078f+((Actor*)*(u8**)(actor+0x18))->position.y;
    p->vx=0.0f;p->vy=0.0f;p->ax=0.0f;p->ay=0.0f;
    p->vy=15.0f;*(short*)(actor+0x1C)=2;
    func_001754A0(actor,27,18);
}

void func_001AF150(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 offset,ownerX;
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p->phase;
    p->phase = t + 1;
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    q = *(u8 **)(actor + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
    p->layer=12;
    ownerX=((Actor*)*(u8**)(actor+0x18))->position.x;
    if(p->facing)offset=-141.66665649414062f;else offset=141.66665649414062f;
    p->position.x=ownerX+offset;
    p->position.y=((Actor*)*(u8**)(actor+0x18))->position.y+D_0044BAD0[p->entryIndex];
    func_001754A0(actor,27,15);
}

void func_001AF560(u8 *actor) {
 Actor *p=(Actor*)actor;
 s32 jitter;
 if(actor[5]==0) {
  ++actor[5];
  *(State*)(actor+0xEC)=*(State*)(*(u8**)(actor+0x18)+0xEC);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
  p->visible=0;p->layer=11;
  *(s16*)(actor+0x1C)=func_00174170()&15;
 } else if(--*(s16*)(actor+0x1C)<0) {
  ++p->phase;actor[5]=0;p->visible=1;
  p->position.x=((Actor*)*(u8**)(actor+0x14))->position.x;
  p->position.y=68.57142639160156f+((Actor*)*(u8**)(actor+0x14))->position.y;
  jitter=func_00174170()&31;
  if(jitter&16)jitter=-15;
  p->position.x+=1.66666662693023681640625f*(f32)jitter;
  jitter=func_00174170()&31;
  if(jitter&16)jitter=-15;
  p->position.y+=2.142857074737548828125f*(f32)jitter;
  p->vx=0.0f;p->vy=0.0f;p->ax=0.0f;p->ay=0.0f;
  p->vy=-1.6071428060531616f;
  func_00175580(actor,27,25,func_00174170()&7);
 }
}
