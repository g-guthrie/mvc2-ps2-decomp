/* Owner velocity-table and indexed side-launch variants. */
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
extern f32 D_0044BA00[][2],D_0044BA04[][2];
void func_001AE060(u8 *actor)
{
    Actor *p=(Actor*)actor;
    f32 horizontal;
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
    if(p->facing)horizontal=D_0044BA00[p->entryIndex][0];
    else horizontal=-D_0044BA00[p->entryIndex][0];
    p->vx=horizontal;
    p->vy=D_0044BA04[p->entryIndex][0];
    p->position.x=((Actor*)*(u8**)(actor+0x18))->position.x+p->vx;
    p->position.y=((Actor*)*(u8**)(actor+0x18))->position.y+p->vy;
    func_001754A0(actor,27,14);
}

void func_001AE540(u8 *actor)
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
    p->layer=11;
    ownerX=((Actor*)*(u8**)(actor+0x18))->position.x;
    if(p->facing)offset=20.0f;else offset=-20.0f;
    p->position.x=ownerX+offset;
    p->position.y=254.99998474121094f+((Actor*)*(u8**)(actor+0x18))->position.y;
    p->vx=p->facing?-3.3333332538604736328125f:3.3333332538604736328125f;
    p->ax=0.0f;p->vy=0.0f;p->ay=-0.53571426868438720703125f;
    func_001754A0(actor,27,(u8)(p->entryIndex+3));
}

void func_001AFA70(u8 *actor)
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
    if(p->facing)offset=-191.66665649414062f;else offset=191.66665649414062f;
    p->position.x=ownerX+offset;
    p->position.y=36.42856979370117f+((Actor*)*(u8**)(actor+0x18))->position.y;
    p->vx=p->facing?-20.0f:20.0f;
    p->ax=0.0f;p->vy=9.64285659790039f;p->ay=-0.53571426868438720703125f;
    func_001754A0(actor,27,30);
}
