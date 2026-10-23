/* Initialize owner-ground placement and directional horizontal velocity. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
extern f32 D_004F1FC8,D_004F1FCC;
void func_001D2CC0(u8 *actor,u8 *owner)
{
    Actor *p=(Actor*)actor,*q=(Actor*)owner;
    f32 x;
    s32 n;
    s32 *d;
    s32 *s;
    s = (s32 *)(owner + 0xEC);
    d = (s32 *)(actor + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    p->visible = 1;
    actor[2] = owner[2];
    actor[1] = owner[1];
    p->scale.x = q->scale.x;
    p->scale.y = q->scale.y;
    p->mode = q->mode;
    p->variant = q->variant;
    p->group = q->group;
    p->scale = q->scale;
    p->layer = q->layer;
    ++p->phase;p->layer=12;
    p->position.y=*(f32*)(owner+0x430);
    *(short*)(actor+0x1C)=32;
    x=480.0f+D_004F1FCC;
    p->vx=-16.66666603088379f;
    if(owner[0x1E6]) {
      x=D_004F1FC8-533.3333129882812f;
      p->vx=-p->vx;
    }
    p->position.x=x;
    func_001757E0(actor,23,26);
}
