/* Initialize directional drift, preserving negative zero when acceleration is reversed. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
void func_001A1110(u8 *actor,u8 *owner)
{
    Actor *p=(Actor*)actor,*q=(Actor*)owner;
    f32 offset;
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
    ++p->phase;p->layer=0;
    p->vx=20.0f;
    p->ax=0.0f;
    p->vy=0.0f;
    p->ay=-0.8035714030265808f;
    offset=106.66666412353516f;
    if(p->facing) {
      offset=-offset;
      p->vx=-p->vx;
      p->ax=-p->ax;
    }
    p->position.x=q->position.x+offset;
    p->position.y=107.14285278320312f+q->position.y;
    func_001757E0(actor,23,21);
}
